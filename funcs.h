#include <iostream>
#include <time.h>

using namespace std;

#ifndef FUNCS_H
#define FUNCS_H

//returns random integer numbers between 0 to max
int getRandom(int max){

    return rand() % (max+1);
}

//gets numerical inputs within the interval given
int getInput(int input, int minValue, int maxValue){
    do{
        cin >> input;
    }while(!(input >= minValue && input <= maxValue));

    return input;
}


void clearScreen(){
    // cout << "\x1B[2J\x1B[H";
    system("cls");

}


void updateScreen(Player player, Display screen){
    clearScreen();

    
    cout << "TURN: " << player.turnNumber << endl << endl << endl;
    screen.list(player);
    
    //player info
    cout << "____________________________________________________________________________________" << endl;
    cout << "NAME: " << player.name;
    cout << "     ";
    cout << "MONEY: " << player.money;
    cout << "     ";
    cout << "POWER: " << player.power;
    cout << "     ";
    
    cout << "LIST: ";
    for(int i = 0; i < player.listLength; i++){

        cout << player.playerList.arr[i];
    }
    cout << "     ";

    cout << "NEXT BOSS: " << player.nextBoss;
    cout << endl;
}

#endif //FUNCS_H