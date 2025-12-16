#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;


#ifndef CLASSES_H
#define CLASSES_H

typedef enum {Oddian = 1,Evengelion,Prime,Random,OneNumMan,Listed} playerClass;

//there should be better way to find and use their index numbers 
#define ODDIAN_INDEX 1
#define EVENGELION_INDEX 2
#define PRIME_INDEX 3
#define RANDOM_INDEX 4
#define ONENUMMAN_INDEX 5
#define LISTED_INDEX 6


#define MAX_LENGTH 20
#define MAX_NUMBER 100


class List{

    public:
        int front,rear;
        int arr[MAX_LENGTH] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        
        
};


struct Player{

    string name = "traveler";

    List playerList;
    int listLength = 10;
    int remainingCell;
    int current = 0;
    
    int level = 1;
    int power;
    playerClass pClass;
    
    int money = 8;

    string nextBoss;
    
    int turnNumber = 1;
    // Display screen;
};



#endif //CLASSES_H