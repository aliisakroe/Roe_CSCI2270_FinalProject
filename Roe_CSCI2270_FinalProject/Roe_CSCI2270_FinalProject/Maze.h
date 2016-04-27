//
//  Maze.hpp
//  Roe_CSCI2270_FinalProject
//
//  Created by Aliisa Roe on 4/23/16.
//  Copyright © 2016 Aliisa Roe. All rights reserved.
//

#ifndef Maze_h
#define Maze_h
#include <vector>
#include <stack>

#include <stdio.h>
#include <iostream>

//enum Position {L, R, U, D};

struct Node{
    int ranking;
    int x;
    int y;
    int passes;
    bool visited;
//    unsigned char relation;
//    unsigned char left;
//    unsigned char right;
//    unsigned char up;
//    unsigned char down;
    Node *leftChild;
    Node *rightChild;
    std::vector<Node*> neighbors;
    
    Node(int in_ranking, int size, int xin, int yin)
    {
        ranking = in_ranking;
        visited = false;
        passes = 0;
        leftChild = NULL;
        rightChild = NULL;
        x = xin;
        y = yin;
        
//        //setting position
//        if (ranking % size == 0){
//            pos = L;
//        } else if (ranking % size == size-1){
//            pos = R;
//        }
//        left = 2;
//        right = 1;
//        up = 4;
//        down = 8;
//        switch(pos)
//        {
//            case L:
//                left = 0;
//                break;
//            case R:
//                right = 0;
//                break;
//        }
//        if (ranking <= size){ //top
//            up = 0;
//        } else if (ranking >= size*(size-1)){ //bottom
//            down = 0;
//        }
        //relation = (left | right | up | down);
    }
};

class Maze
{
    
public:
    Maze(int size);
    ~Maze();
    void printAns();
    void printMaze(bool withAns);
    void printForks();
    void teardown();
    void printLeaves();
    int countForks();
    void printNeightbors(int in_rank);
    
    
protected:
    
    
private:
    bool isEdge(Node* node1, Node* node2);
    void buildTree(std::stack<Node*> vPath, std::stack<Node*> vDead);
    void printWallRow(int y, bool last);
    void printMazePrivate(bool withAns);
    void printTree(Node* node, bool printWholeTree);
    void makePath();
    void DFS(Node* node);
    void countForks(Node *node, int &totalForks);
    bool onPath(Node* node);
    bool reachedFinal();
    Node *root;
    Node *start;
    Node *finish;
    int SIZE;
    Node* grid[10][10];
    std::vector<Node*> path;
};

#endif /* Maze_hp */
