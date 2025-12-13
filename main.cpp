#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "classes.h"
#include "playerFuncs.h"

#include "bossFight.h"
#include "bossAttack.h"

#include "shop.h"

using namespace std;




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
    while(isAlive(player)){
        //start of a turn

        //Roll a number
        updateScreen(player, screen);
        player = roll(player, screen, MAX_NUMBER);


        updateScreen(player, screen);
        player = shop(player,screen);

        // clearScreen();
        //Action
        //player = action(player, screen);

        updateScreen(player, screen);
        player = bossFight(player, screen);
        // bossFight(player, screen);

        player = cellCheck(player);
        player.turnNumber++;
    }

    return 0;
}