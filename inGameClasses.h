#include "classes.h"
#include "funcs.h"


#ifndef INGAME_CLASSES_H
#define INGAME_CLASSES_H

Player cOddian(Player player){
    int newNum; 
    player.listLength = 10;

    //filling with odds
    for(int i = 0; i < player.listLength; i++){      

        newNum = getRandom(MAX_NUMBER);
        while(newNum % 2 == 0){
            newNum = getRandom(MAX_NUMBER);
        } // try 'till its odd

        player.playerList.arr[i] = newNum;
    }

    return player;
}

Player cEvengelion(Player player){
    int newNum;
    player.listLength = 10;

    //filling with evens
    for(int i = 0; i < player.listLength; i++){      

        newNum = getRandom(MAX_NUMBER);
        while(newNum % 2 == 1){
            newNum = getRandom(MAX_NUMBER);
        } // try 'till its even

        player.playerList.arr[i] = newNum;
    }

    return player;
}

Player cFullRandom(Player player){
    player.listLength = 10;

    for(int i = 0; i < player.listLength; i++){
        player.playerList.arr[i] = getRandom(MAX_NUMBER);
    }


    return player;
}


//power+onenumman
Player cPowerFull(Player player){
    player.listLength = 1;
    player.power = player.power * 5;
    
    player.playerList.arr[0] = getRandom(MAX_NUMBER);
}

Player cListed(Player player){

    player.listLength = 20;

    for(int i = 0; i < player.listLength; i++){
        player.playerList.arr[i] = i + 1;
    }

    return player;
}

//Mirror


//Lovers


//VampireLord


//Herd

#endif //INGAME_CLASSES_H