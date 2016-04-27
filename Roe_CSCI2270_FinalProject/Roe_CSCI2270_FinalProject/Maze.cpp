//
//  Maze.cpp
//  Roe_CSCI2270_FinalProject
//
//  Created by Aliisa Roe on 4/23/16.
//  Copyright © 2016 Aliisa Roe. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
//#include <curses.h>   for user interaction eventually
#include "Maze.h"
using namespace std;


Maze::Maze(int size){
    SIZE = size;
    start = NULL;
    finish = NULL;
    root = NULL;
    int ranking = 0;
    
    //creating nodes in every cell, a way to access the nodes
    for (int y = 0; y < SIZE; y++){
        for (int x = 0; x < SIZE; x++){
            Node* node = new Node(ranking++, SIZE, x, y);
            grid[x][y] = node;
        }
    }
    makePath();
    
    //don't want a path with no forks, very likely in smaller graph dimensions --BUG 
    if (root == NULL){
        teardown();
        makePath();
    }
    printMazePrivate(false);
    //char event = getchar();    //TODO-- allow user to traverse inside 2d array grid
    
    
}



Maze::~Maze(){
    teardown();
    
//BUG-- probably memory loss since not deleting the dynamically allocated nodes created in the grid.
//    Node** temp = NULL;
//    for (int y = 0; y < SIZE; y++){
//        for (int x = 0; x < SIZE; x++){
//            temp = &(grid[x][y]);
//            delete [] *temp;              //not working
//                temp = NULL;
//        }
//    }
}

void Maze::printAns(){
    printMazePrivate(true);
    for (int i= path.size()-1; i > 0; i--){
        cout << path[i]->ranking << "->";
    }
    cout << finish->ranking << endl;
   // DFS(finish);
};


void Maze::printMaze(bool withAns=false){
    printMazePrivate(withAns);
};

void Maze::printForks(){
    printMazePrivate(true);
    printTree(root, true);
}

void Maze::printLeaves(){
    printMazePrivate(true);
    for (int x = 0; x < SIZE; x++){
        for (int y = 0; y < SIZE; y++){
            if (grid[x][y]->passes == 1){
                cout << grid[x][y]->ranking << endl;
            }
        }
    }
}


//5
int Maze::countForks(){
    printMazePrivate(true);
    int totalForks = 0;
    countForks(root, totalForks);
    return totalForks;
}

//6

void Maze::printNeightbors(int in_rank){
    for (int x = 0; x < SIZE; x++){
        for (int y = 0; y < SIZE; y++){
            if (grid[x][y]->ranking == in_rank){
                for (int i =0; i < grid[x][y]->neighbors.size(); i++){
                    cout << grid[x][y]->neighbors[i]->ranking << endl;
                }
            }
        }
    }
}

//7

//8

//9

//10


//PRIVATE

void Maze::makePath(){
    //randomly generated path using stack
    //the last node to be traversed will be the finishing point
    //if a node is passed 3 times it is a fork, and is saved to the tree
    //leaves will be passed only once, and the rest will be passed 2 times
    
    stack<Node*> buildStack, pathSubtree, deadEndSubtree;
    srand( time( NULL ) );
    int random = rand() % SIZE;
    start = grid[0][random];
    
    vector<Node*> choices;
    Node* current = start;
    Node* nextNode = NULL;
    Node* leaf = NULL;
    Node* lastNode = NULL;
    
    int first = true;
    bool foundEnd = false;
    
    while (!buildStack.empty() || first){
        first=false;
        
        current->visited = true;
        current->passes++; //to check if leaf or vertex
        
        
    
        //CREATING THE PATH after final vertice found and traverse back to start
        if (!foundEnd){
            
            if (reachedFinal()){ //expensive?
                finish = current;
                foundEnd = true;
                path.push_back(current);
            }
        }
        // this will add all the nodes from the finish back to the start and
        //create the path, only called after the final vertex is found
        else {
            path.push_back(current);
            if (current->passes > 2 ){
                pathSubtree.push(current);
            }
        }
        
        
        //n is the neighbor nodes of the current node, we see whether a path is eligible
        //a path is only eligible if it is not already visited
        //all eligible moves are appended to a vector and randomly chosen
        Node* n = NULL;
        
        int x1 = current->x;
        int y1 = current->y;
        if (x1-1 >= 0){
            n = grid[x1-1][y1];
            if (!n->visited){
                choices.push_back(n);
            }
        }
        if (x1+1 < SIZE){
            n = grid[x1+1][y1];
            if (!n->visited ){
                choices.push_back(n);
            }
        }
        if (y1-1 >= 0){
            n = grid[x1][y1-1];
            if (!n->visited ){
                choices.push_back(n);
            }
        }
        if (y1+1 < SIZE){
            n = grid[x1][y1+1];
            if (!n->visited ){
                choices.push_back(n);
            }
        }
        
        
        
        //if there were no options, pop node and move back until another option (when reaches start, will exit func)
        if (choices.empty()){
            buildStack.pop();
            
            //if passed three times, then a fork, this stack is all the dead end forks not on the path/subtree
            if (current->passes > 2){
                deadEndSubtree.push(current);
            }
            
            //if the finishing node has been visited, then those forks are saved in the path stack/subtree
            if (!pathSubtree.empty()){
                
                //the two subtrees will merge at the first fork in the path
                //when the path stack is filled to the first fork, then merge the two subtrees into one
                if (deadEndSubtree.top() == pathSubtree.top()){
                    
                   // checkLeaves();
                    
                    root = pathSubtree.top();
                    buildTree(pathSubtree, deadEndSubtree);
                    //empty path subtree
                    while (!pathSubtree.empty()){
                        pathSubtree.pop();
                    }
                }
            }
            
            if (!buildStack.empty()){
                lastNode = current;
                current = buildStack.top();
            }
        }
        
        
        // if there were options, make a move
        else {
            random = rand() % choices.size();
            nextNode = choices[random];
            current->neighbors.push_back(nextNode);
            lastNode = current;
            current = nextNode;
            buildStack.push(nextNode);
        }
        choices.clear();
    }
    path.push_back(start);
}


void Maze::buildTree(stack<Node*> pathStack, stack<Node*> deadStack ){
    //build the two subtrees and merge under the first fork
    //the furthest left linked list will be the correct path turns
    
    Node* temp = NULL;
    pathStack.pop();
    while (!pathStack.empty()){
        temp->leftChild = pathStack.top();
        pathStack.pop();
        temp = temp->leftChild;
    }
    
    temp = deadStack.top();
    deadStack.pop();
    while (!deadStack.empty()){
        temp->rightChild = deadStack.top();
        deadStack.pop();
        temp = temp->rightChild;
    }
}


void Maze::printWallRow(int y, bool last=false){
    //helper funtction for printMaze()
    
    cout << "|";
    for (int i = 0; i < SIZE; i++){
        if (y < SIZE-1){
            if ( !isEdge(grid[i][y], grid[i][y+1])){
                cout << setfill('=') << setw(6) << "";
            } else {
                cout << setfill(' ') << setw(6) << "";
            }
        }
    }
    if (!last){
        cout << "|" << endl;
    }
}


void Maze::printMazePrivate(bool withAns=false){
    //visually builds the maze by text in the terminal
    // if withAns true, will print maze with index numbers
    
    Node* n = NULL;
    int width = SIZE*6;
    
    cout << setfill('=') << setw(width+2) << "" << endl;
    
    for (int y = 0; y < SIZE; y++){
       // cout<< "|" << endl;
        
        for (int x = 0; x < SIZE; x++){
            n = grid[x][y];
            
            //mark start
            if (start->ranking == n->ranking){
                cout << setfill(' ') << setw(1) << "";
                cout << setfill(' ') << setw(5) << "-> S " ;
            }
            
            //otherwise
            else {
                if (x == 0){
                    cout << setfill(' ') << setw(1) << "|";
                }
                
                //mark end
                if ( finish->ranking == n->ranking){
                    cout << setfill(' ') << setw(5) << " ** " ;
                }
                //mark numbers
                else {
                    if (withAns){
                        cout << setfill(' ') << setw(5) << n->ranking;
                    } else {
                        cout << setfill(' ') << setw(5) << "";
                    }
                }
            }
            
            //mark horizontal walls
            if (x < SIZE-1){
                if ( !isEdge(n, grid[x+1][y])){
                    cout << setfill(' ') << setw(1) << "|";
                } else {
                    cout << setfill(' ') << setw(1) << "";
                }
            }
        }
        
        cout << setfill(' ') << setw(2) << "|" << endl;
        
        //mark vertical walls
        if (y == SIZE-1){
            printWallRow(y, true);
        } else {
            printWallRow(y);
        }
    }
    
    //last line
    cout << setfill('=') << setw(width+1) << "" << endl;
}




bool Maze::isEdge(Node* node1, Node* node2){
    //helper function to check whether you can walk from one cell to the next(return true), or if there is a wall (return false)
    
    for (int i = 0; i < node1->neighbors.size(); i++){
        if (node1->neighbors[i] == node2){
            return true;
        }
    }
    for (int i = 0; i < node2->neighbors.size(); i++){
        if (node2->neighbors[i] == node1){
            return true;
        }
    }
    return false;
}


void Maze::printTree(Node * node, bool printWholeTree=true){
    //prints the nodes in the binary tree
    
    if (root == NULL){
        cout << "EMPTY" << endl;
        return;
    }
    if (node->leftChild != NULL){
        printTree(node->leftChild);
    }
    cout << node->ranking  << endl;
    if (node->rightChild != NULL  && printWholeTree) {
        printTree(node->rightChild );
    }
}

void Maze::DFS(Node* node){
    node->visited = true;
    for (int i = 0; i < node->neighbors.size(); i++){
        if (!node->neighbors[i]->visited){
            cout << node->neighbors[i]->ranking << endl;
            if (node->neighbors[i] == finish){
                return;
            }
            DFS(node->neighbors[i]);
        }
    }
    
}


bool Maze::reachedFinal(){
//helper function to see when the lest vertex has been reached in makePath()
//will return true when all vertices have been visited
    
    for (int y = 0; y < SIZE; y++){
        for (int x=0; x < SIZE; x++){
            if ( grid[x][y]->visited == false){
                return false;
            }
        }
    }
    return true;
}

void Maze::teardown(){
    start = NULL;
    finish = NULL;
    root = NULL;
    path.clear();
    
    Node* temp = NULL;
    for (int x = 0; x < SIZE; x++){
        for (int y = 0; y < SIZE; y++){
            temp = grid[y][x];
            temp->visited = false;
            temp->passes = 0;
            temp->leftChild = NULL;
            temp->rightChild = NULL;
        }
    }
}

void Maze::countForks(Node *node, int &totalForks){
    totalForks++;
    if (node->leftChild != NULL){
        countForks(node->leftChild, totalForks);
    }
    if (node->rightChild != NULL) {
        countForks(node->rightChild, totalForks);
    }
}
