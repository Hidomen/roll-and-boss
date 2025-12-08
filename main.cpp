#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "classes.h"
#include "playerFuncs.h"

// #include "bossInit.h"
#include "bossAttack.h"

#include "shop.h"

using namespace std;


Player bossFight(Player player){

    //pick a boss in the boss list
    //initilaize the fight

    //turns
    //each turn check lose condition & win condition
    //player actions
    //boss attacks
    //next turn


    return player;
}


int main(){
    srand(time(NULL));

    Display screen;
    Player player;

    //Introduction
    screen.intro();

    //Choosing a class
    //Filling the list
    player = classChoose(player, screen);

    //display the list
    screen.list(player);

    //TURNS
    int turnNumber = 1;
    while(isAlive(player)){
        clearScreen();
        //start of a turn
        screen.turn(player, turnNumber);
        
        //Roll a number
        player = roll(player, screen, MAX_NUMBER);
        screen.list(player);

        //screen clear
        player = shop(player, screen);

        //screen clear
        //Action
        //player = action(player, screen);

        //screen clear
        // bossFight(player, screen);

        player = cellCheck(player);
        turnNumber++;
    }

    return 0;
}