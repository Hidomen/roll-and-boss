#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "classes.h"
#include "playerFunc.h"

#include <windows.h>

using namespace std;


//CIRCULAR QUEUE

// 1 2 3 4 5 6 
// front -- rear

// enum phase ROLL, SHOP, ACTION, BOSS -- Random Encounter
// Number Shop %70, Attribute and Vampire Shop %30

bool isAlive(Player player){
    if(player.remainingCell <= 0){
        return false;
    }
    return true;
}

void clearScreen(){
    // cout << "\x1B[2J\x1B[H";
    system("cls");

}


int main(){
    srand(time(NULL));


    Display screen;
    Player player;

    //Introduction
    screen.intro();



    
    //Choosing a class
    //Filling the list
    player = classChoose(player,screen);

    
    //display the list
    screen.list(player);

    int rollDecision;
    int turnNumber = 1;

    while(isAlive(player)){
        clearScreen();
        //start of a turn
        screen.turn(player,turnNumber);
        
        
        //Roll a number
        player = roll(player, screen, MAX_NUMBER);
        screen.list(player);




        //screen clear
        //Shop
        
        //screen clear
        //Action

        //screen clear
        //Boss

        player = cellCheck(player);
        turnNumber++;
        //screen clear
    }




    return 0;
}