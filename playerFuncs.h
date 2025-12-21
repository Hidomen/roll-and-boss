#include "classes.h"
#include "inGameClasses.h"
#include "funcs.h"


#ifndef PLAYERFUNCS_H
#define PLAYERFUNCS_H


void nextCurrent(Player *player){
    
    player->current = ((player->current + 1) % player->listLength);
}


void classChoose(Player *player){

    const int classSize = 5;

    int option,newNum;

    // do{
    //     cin >> option;
    // }while(option > classSize || option <= 0);

    getInput(&option,0,classSize);
 
    player->pClass = (playerClass) option;



    displayClassChoice(*player);

    //first four classes
    switch(option){
        // Oddian Class - Random Odds - ListSize: 10
        case ODDIAN_INDEX:
            cOddian(player);
            break;

        // Evengelion Class - Random Evens - listSize: 10
        case EVENGELION_INDEX:
            cEvengelion(player);
            break;

        // Prime Class - Random Prime - listSize: 7
        case PRIME_INDEX:
            break;

        // Random Class - Random Fill - listSize: 10
        case RANDOM_INDEX:
            break;

        // Listed Class - 1 to 20 - listSize: 20
        case LISTED_INDEX:
            cListed(player);
            break;

            
            
        }
        
        
        //class list: 
    // OneNumMan Class - 1 Choosable Number - 5X Power - listSize: 1
    // Mirror Class - First 5 random last 5 is mirrored version of numbers - mirrored cards dynamically changes their value to origin - listSize: 10
    // Lovers Class - every 2 random cards are same - listSize: 10
    // VampireLord Class - range of numbers in start 50 to 100 - each turn max num becomes (-1) - ListSize: 13
    // Herd Class - Random Fill - *0.5 power - listSize: 50
    // Power Class - Random Fill - If a num. hits a boss, power *1.5 - listSize: 10 
}


void roll(Player *player, int max){
    
    int rolledNum = getRandom(max);
    
    displayRoll(*player,rolledNum);
        
    
    int rollDecision;
    //validity check (make a warning message)
    getInput(&rollDecision,0,1);


    if(rollDecision == 1){
        player->playerList.arr[player->current] = rolledNum;
    }
    nextCurrent(player);
    
    // return player;
}


void cellCheck(Player *player){
    player->remainingCell = 0;

    for(int i = 0; i < player->listLength; i++){
        if(player->playerList.arr[player->current] > 0){
            player->remainingCell++;
        }
    }

}


bool isAlive(Player player){
    if(player.remainingCell <= 0){
        return false;
    }
    return true;
}

#endif //PLAYERFUNCS_H