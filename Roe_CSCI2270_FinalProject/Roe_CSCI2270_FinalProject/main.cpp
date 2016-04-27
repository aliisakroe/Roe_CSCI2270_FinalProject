//
//  main.cpp
//  Roe_CSCI2270_FinalProject
//
//  Created by Aliisa Roe on 4/17/16.
//  Copyright © 2016 Aliisa Roe. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Maze.h"
using namespace std;

Maze makeMaze(){
    int response;
    cout << "What size maze would you like to solve? " << endl;
    cout << "Please enter a number from 2 to 10: " << endl;
    while (!(cin>>response) || response < 2 || response > 10){
        cout << "Please enter a number from 2 to 10: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    Maze maze(response);
    cout << "\n Ready to solve?" << endl;
    return maze;
    
};

int main(int argc, const char * argv[]) {
    cout << "Hi!\n" << endl;
    Maze maze = makeMaze();
    int response = -1;
    while ( response != 0){
        cout << "\n======Main Menu======" << endl;
        cout << "1. Make a new maze" << endl;
        cout << "2. Solve the maze path" << endl;
        cout << "3. Print the maze " << endl;
        cout << "4. Print the maze with indexes" << endl;
        cout << "5. Print the forks" << endl;
        cout << "6. Print Dead Ends" << endl;
        cout << "7. Count Forks" << endl;
        cout << "0. Quit" << endl;
        cin >> response;
        switch(response){
            case 1 :{
                cout << endl;
               // maze.teardown();
                maze = makeMaze();
                break;
            }
            case 2 :{
                maze.printAns();
                cout << "Is the whole path" << endl;
                break;
            }
            case 3 :{
                maze.printMaze(false);
                break;
            }
            case 4 :{
                maze.printMaze(true);
                break;
            }
            case 5 :{
                maze.printForks();
                cout << "Are the forks " << endl;
                break;
            }
            case 6 :{
                maze.printLeaves();
                cout << "Are the dead ends" << endl;
                break;
            }
            case 7 :{
                cout  <<  maze.countForks() << " forks" << endl;
                break;
            }
            case 8 :{
                break;
            }
            case 9 :{
                break;
            }
            case 10 :{
                break;
            }
            case 0: {
                cout << "Sayoonara!" << endl;
                break;
            }
        }
        
    }
    
    return 0;
}