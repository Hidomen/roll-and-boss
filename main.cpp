#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "playerClasses.h"


#define MAX_NUMBER 100

using namespace std;


//CIRCULAR QUEUE

// 1 2 3 4 5 6 
// front -- rear

// enum phase ROLL, SHOP, ACTION, BOSS -- Random Encounter
// Number Shop %70, Attribute and Vampire Shop %30


void cOddian(Player player){
    
}





Player classChoose(Player player,Display screen){

    int option,newNum;

    do{
        cin >> option;

    }while(option > 4 || option <= 0);
 
    player.pClass = (playerClass) option;


    screen.classChoice(player,screen);

    //first four classes
    switch(option){
        // Oddian Class - Random Odds - ListSize: 10
        case 1:
            player.listLength = 10;

            //filling with odds
            for(int i = 0; i < player.listLength; i++){      

                newNum = rand() % MAX_NUMBER;
                while(newNum % 2 == 0){
                    newNum = rand() % MAX_NUMBER;
                } // try 'till its odd

                player.playerList.arr[i] = newNum;
            }

            break;
        // Evengelion Class - Random Evens - listSize: 10
        case 2:
            player.listLength = 10;

            //filling with evens
            for(int i = 0; i < player.listLength; i++){      

                newNum = rand() % MAX_NUMBER;
                while(newNum % 2 == 1){
                    newNum = rand() % MAX_NUMBER;
                } // try 'till its odd

                player.playerList.arr[i] = newNum;
            }
            
            break;
        // Prime Class - Random Prime - listSize: 7
        case 3:
            break;
        // Random Class - Random Fill - listSize: 10
        case 4:
        // OneNumMan Class - 1 Choosable Number - 5X Power - listSize: 1
            break;
        // Listed Class - 1 to 20 - listSize: 20

    }


    //class list: 
    // Mirror Class - First 5 random last 5 is mirrored version of numbers - mirrored cards dynamically changes their value to origin - listSize: 10
    // Lovers Class - every 2 random cards are same - listSize: 10
    // VampireLord Class - range of numbers in start 50 to 100 - each turn max num becomes (-1) - ListSize: 13
    // Herd Class - Random Fill - *0.5 power - listSize: 50
    // Power Class - Random Fill - If a num. hits a boss, power *1.5 - listSize: 10 

    return player;
}

int main(){
    srand(time(NULL));

    Display screen;
    Player player;

    //Introduction
    screen.intro();

    
    //Choosing a class
    player = classChoose(player,screen);

    //Filling the list
    player.playerList.display(player.listLength);

    //while isAlive()
    //Roll a number
    //Shop
    //Action
    //Boss




    return 0;
}