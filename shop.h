#include <iostream>

#include "classes.h"
#include "funcs.h"
#include "playerFuncs.h"
#include "display.h"

bool isVampActive(Player player){
    for(int i = 0; i < player.listLength; i++){
        if(player.playerList.arr[i] < 0){
            return true;
        }
    }
    return false;
}

Player numberShop(Player player){
    int slots[3];
    int selection;


    const int numberCost = 3;

    if(player.money >= numberCost){
        
        slots[0] = getRandom(MAX_NUMBER);
        slots[1] = getRandom(MAX_NUMBER);
        slots[2] = getRandom(MAX_NUMBER);
        
        //selection
        displayNumberShop(player, slots);
        
        selection = getInput(selection, 0, 3);

        //didnt select any of the number and didnt update current
        if(selection == 0){
            return player;
        } else { //purchased
            
            player.playerList.arr[player.current] = slots[selection - 1];
            
            player.money = player.money - numberCost;
            player = nextCurrent(player);
        }

    }else{


        cout << "GET THE HELL OUT OF HERE FILTHY POOR" << endl;
        getInput(selection, 1, 1);
    }

    return player;
}


#define P_NUMBER_SHOP 70
//
Player shop(Player player){
    bool vamp = isVampActive(player);

    int probability = getRandom(100); //100 based probability

    if(probability < P_NUMBER_SHOP){
        //classic number shop ~ choose a new to add it current index
        player = numberShop(player);
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
