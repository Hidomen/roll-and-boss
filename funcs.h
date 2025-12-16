#include <iostream>
#include <time.h>

#include "display.h"

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








std::string getString(HANDLE stdHandle, const int limit, int xPos, int yPos){
    SetConsoleCursorPosition(stdHandle,{(short)xPos,(short)yPos});

    std::string text(limit, ' ');
    int letter = 0;

    while(!GetAsyncKeyState(VK_RETURN)){

        for(int i= 0; i < 256; i++){
            if(GetAsyncKeyState(i) & 0b1 && letter < limit){
                cout << (char)i;
                text[letter] = (char)i;
                letter++;
                xPos++;
            }
            if(GetAsyncKeyState(VK_BACK) & 0b1 && letter > 0){
                xPos--;
                SetConsoleCursorPosition(stdHandle, {(short)(xPos),(short)yPos});
                cout << ' ';
                SetConsoleCursorPosition(stdHandle, {(short)(xPos),(short)yPos});

                letter--;
            }
        }
    }
    text.resize(letter);

    return text;
}

#endif //FUNCS_H