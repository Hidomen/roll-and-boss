#include "classes.h"
#include "inGameClasses.h"





Player classChoose(Player player,Display screen){

    const int classSize = 5;

    int option,newNum;

    do{
        cin >> option;

    }while(option > classSize || option <= 0);
 
    player.pClass = (playerClass) option;



    screen.classChoice(player,screen);

    //first four classes
    switch(option){
        // Oddian Class - Random Odds - ListSize: 10
        case ODDIAN_INDEX:
            player = cOddian(player);
            break;

        // Evengelion Class - Random Evens - listSize: 10
        case EVENGELION_INDEX:
            player = cEvengelion(player);
            break;

        // Prime Class - Random Prime - listSize: 7
        case PRIME_INDEX:
            break;

        // Random Class - Random Fill - listSize: 10
        case RANDOM_INDEX:
            break;

        // Listed Class - 1 to 20 - listSize: 20
        case LISTED_INDEX:
            player = cListed(player);
            break;

            
            
        }
        
        
        //class list: 
    // OneNumMan Class - 1 Choosable Number - 5X Power - listSize: 1
    // Mirror Class - First 5 random last 5 is mirrored version of numbers - mirrored cards dynamically changes their value to origin - listSize: 10
    // Lovers Class - every 2 random cards are same - listSize: 10
    // VampireLord Class - range of numbers in start 50 to 100 - each turn max num becomes (-1) - ListSize: 13
    // Herd Class - Random Fill - *0.5 power - listSize: 50
    // Power Class - Random Fill - If a num. hits a boss, power *1.5 - listSize: 10 

    return player;
}


Player roll(Player player, Display screen, int max){
    
    int rolledNum = rand() % max;
    
    screen.roll(player,rolledNum);
    
    
    
    int rollDecision;
    //validity check (make a warning message)
    do{
        cin >> rollDecision;

    }while(!(rollDecision == 1 || rollDecision == 0));



    if(rollDecision == 1){
        
        player.playerList.arr[player.current] = rolledNum;
        player.current = player.playerList.nextCurrent(player.listLength,player.current);
    }

    return player;
}


Player cellCheck(Player player){
    player.remainingCell = 0;

    for(int i = 0; i < player.listLength; i++){
        if(player.playerList.arr[player.current] > 0){
            player.remainingCell++;
        }
    }


    return player;
}