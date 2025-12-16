#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "classes.h"
#include "playerFuncs.h"

#include "bossFight.h"
#include "bossAttack.h"

#include "shop.h"

#include "display.h"

using namespace std;




int main(){
    srand(time(NULL));

    Player player;

    //Introduction
    // displayIntro();

    //Choosing a class
    //Filling the list
    // player = classChoose(player);

    //TURNS
    while(isAlive(player) && !GetAsyncKeyState(VK_ESCAPE) & 0b1){
        //start of a turn

        //Roll a number
        updateScreen(player);
        roll(&player, MAX_NUMBER);


        // updateScreen(player);
        // player = shop(player);

        // clearScreen();
        //Action
        //player = action(player, screen);

        // updateScreen(player);
        // player = bossFight(player);
        // bossFight(player, screen);

        player = cellCheck(player);
        player.turnNumber++;

    }

    return 0;
}