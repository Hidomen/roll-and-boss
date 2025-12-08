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

#endif //FUNCS_H