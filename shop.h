#include <iostream>

#include "classes.h"
#include "funcs.h"
#include "playerFuncs.h"


bool isVampActive(Player player){
    for(int i = 0; i < player.listLength; i++){
        if(player.playerList.arr[i] < 0){
            return true;
        }
    }
    return false;
}

Player numberShop(Player player, Display screen){
    int slots[3];

    slots[0] = getRandom(MAX_NUMBER);
    slots[1] = getRandom(MAX_NUMBER);
    slots[2] = getRandom(MAX_NUMBER);

    //selection
    screen.numberShop(player, slots);
    
    int selection;
    selection = getInput(selection, 1, 3);

    player.playerList.arr[player.current] = slots[selection - 1];
    player = nextCurrent(player);

    return player;
}


#define P_NUMBER_SHOP 70
//
Player shop(Player player, Display screen){
    bool vamp = isVampActive(player);

    int probability = getRandom(100); //100 based probability

    if(probability < P_NUMBER_SHOP){
        //classic number shop ~ choose a new to add it current index
        player = numberShop(player, screen);
        // player.playerList.arr[player.current] = selected;
    } else {
        //attrib or vamp shop
        if(vamp && probability%2){
            // %15 vamp if there are negative num
        } else {
            // %15 attrib or %30 if there are not negative num
            
        }

    }


    return player;
}
