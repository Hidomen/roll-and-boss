#include "classes.h"


Player cOddian(Player player){
    int newNum;
    
    player.listLength = 10;

    //filling with odds
    for(int i = 0; i < player.listLength; i++){      

        newNum = rand() % MAX_NUMBER;
        while(newNum % 2 == 0){
            newNum = rand() % MAX_NUMBER;
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

        newNum = rand() % MAX_NUMBER;
        while(newNum % 2 == 1){
            newNum = rand() % MAX_NUMBER;
        } // try 'till its even

        player.playerList.arr[i] = newNum;
    }

    return player;
}

Player cFullRandom(Player player){
    player.listLength = 10;

    for(int i = 0; i < player.listLength; i++){
        player.playerList.arr[i] = rand() % MAX_NUMBER;
    }


    return player;
}


//power+onenumman
Player cPowerFull(Player player){
    player.listLength = 1;
    player.power = player.power * 5;
    
    player.playerList.arr[0] = rand() % MAX_NUMBER;
}

Player cListed(Player player){

    player.listLength = 20;

    for(int i=0; i < player.listLength;i++){
        player.playerList.arr[i] = i + 1;
    }

    return player;
}

//Mirror


//Lovers


//VampireLord


//Herd

