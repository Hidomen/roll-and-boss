#include <iostream>
// #include <ncurses.h>

#include "classes.h"

#define NOMINMAX 1
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <string>



#ifndef DISPLAY_H
#define DISPLAY_H

#define NAME_LIMIT 12
#define SCREEN_X_POS 40
#define Y_OFFSET 5
#define P_INFO_X_POS 10
#define DISPLAY_LENGTH 20

using namespace std;
HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);


void drawFrameUnichar(short startx, short starty, int width, int height, char c, char corner){
    SetConsoleCursorPosition(stdHandle, {startx,starty});

    short xPos = startx+1;
    short yPos = starty+1;

    //CORNERS
    SetConsoleCursorPosition(stdHandle, {startx,starty});
    cout << corner;
    SetConsoleCursorPosition(stdHandle, {startx,(short)(starty+height-1)});
    cout << corner;
    SetConsoleCursorPosition(stdHandle, {(short)(startx+width-1), starty});
    cout << corner;
    SetConsoleCursorPosition(stdHandle, {(short)(startx+width-1), (short)(starty+height-1)});
    cout << corner;


    //TOP AND BOTTOM (below)
    for(int i = 0; i < width-2; i++){
        SetConsoleCursorPosition(stdHandle, {xPos, starty});
        cout << c;
        SetConsoleCursorPosition(stdHandle, {xPos, (short)(starty+height-1)});
        cout << c;

        xPos++;
    }

    //LEFT AND RIGHT (front)
    for(int i = 0; i < height-2; i++){
        SetConsoleCursorPosition(stdHandle, {startx, yPos});
        cout << c;

        SetConsoleCursorPosition(stdHandle, {(short)(startx+width-1), yPos});
        cout << c;
        
        yPos++;
    }
    

    SetConsoleCursorPosition(stdHandle, {startx,starty});
}


void drawFrameDifchar(short startx, short starty, int width, int height, char top, char bottom, char left, char right, char corner){
    SetConsoleCursorPosition(stdHandle, {startx,starty});

    short xPos = startx+1;
    short yPos = starty+1;


    //CORNERS
    SetConsoleCursorPosition(stdHandle, {startx,starty});
    cout << corner;
    SetConsoleCursorPosition(stdHandle, {startx,(short)(starty+height-1)});
    cout << corner;
    SetConsoleCursorPosition(stdHandle, {(short)(startx+width-1), starty});
    cout << corner;
    SetConsoleCursorPosition(stdHandle, {(short)(startx+width-1), (short)(starty+height-1)});
    cout << corner;

    //TOP AND BOTTOM (below)
    for(int i = 0; i < width-2; i++){
        SetConsoleCursorPosition(stdHandle, {xPos, starty});
        cout << top;
        SetConsoleCursorPosition(stdHandle, {xPos, (short)(starty+height-1)});
        cout << bottom;

        xPos++;
    }

    //LEFT AND RIGHT (front)
    for(int i = 0; i < height-2; i++){
        SetConsoleCursorPosition(stdHandle, {startx, yPos});
        cout << left;

        SetConsoleCursorPosition(stdHandle, {(short)(startx+width-1), yPos});
        cout << right;
        
        yPos++;
    }
    

    SetConsoleCursorPosition(stdHandle, {startx,starty});
}


int nextLine(int indentation, int currenty){
    // LP a = NULL;
    // GetConsoleCursorInfo(stdHandle,a);
    currenty++;

    SetConsoleCursorPosition(stdHandle, {(short)(indentation), (short)currenty});

    return currenty;
}


void displayPlayerInfo(){

    int indentation = 7;
    int currentx = 7;
    int currenty = 7;
    SetConsoleCursorPosition(stdHandle, {(short)currentx,(short)currenty});


    cout << "NAME: HIDOMEN";
    currenty = nextLine(indentation, currenty);
    cout << "LEVEL: 5";
    currenty = nextLine(indentation, currenty);
    cout << "blabla";
    currenty = nextLine(indentation, currenty);

}


void newWindow(short startx, short starty, int width, int height, std::string text){
    int textStart = startx + (width - text.size())/2;

    drawFrameUnichar(startx, starty, width, height, '-', '+');
    SetConsoleCursorPosition(stdHandle, {(short)textStart,starty});
    cout << text;
    SetConsoleCursorPosition(stdHandle, {startx,starty});
}


void displayInit(){
    int buffer = 10;
    int pinfoWidth = 20;
    int screenWidth = 70;
    int displayLength = 25;

    newWindow(buffer, 5, pinfoWidth, displayLength, " PLAYER INFO ");
    newWindow(buffer*2+pinfoWidth, 5,screenWidth, displayLength,"+SCREEN+");
}



void displayIntro(){
    
    // cout << "Hello Stranger, welcome to the nameless for now village. " << endl;
    // cout << "Be careful, people around this village are very cruel. They don't want any new people" << endl;
    // cout << "They kind of corrupted..." << endl;
    // cout << "Anyways. Let me introduce my special assistant. ____" << endl;
    // cout << "____ going to guide you to choose your class. Classes will help you through your journey in this village" << endl;

    cout << "~sOMe GibBerIsh TaLK~" << endl;
    cout << "1 TO " << 5 << endl;
}

void displayList(Player player){
    //check if its empty or not
    

    cout << "LIFE LIST: ";

    for(int i = 0; i < player.listLength; i++){ //just for debugging
        if(i % 5 == 0 && i != 0){ // to have more clear visual ends line for every 5
            cout << endl;
        }
        cout << player.playerList.arr[i] << " ";
    }
    cout << endl;
}


void displayNumberShop(Player player, int slots[]){

    cout << endl << endl;
    for(int i = 0; i < 3; i++){

        cout << "[  " << slots[i] << "  ]";
    }
    cout << endl;
    cout << "CURRENT: " << player.current+1 << " -----> " << player.playerList.arr[player.current] << endl;
    cout << "PICK ONE OF THESE NUMBERS: [1,2,3]" << endl;
    cout << "> ";
}

void displayBossfight(){

}

void allClass(){
    //print every option for classes
}

void pClass(Player player){
        //elim ilen yapcam artık enum printlemiyor direkt
    switch (player.pClass){

        case ODDIAN_INDEX:
            cout << "Oddian";
            break;
    
        case EVENGELION_INDEX:
            break;
    
        case PRIME_INDEX:
            break;

        case RANDOM_INDEX:
            break;

        case ONENUMMAN_INDEX:
            break;

        case LISTED_INDEX:
            break;            
    }
}

void displayClassChoice(Player player){

    cout << "You have choose the ";
    pClass(player);
    cout << "  Class..." << endl;
    cout << "I wish you luck" << endl << endl;
}

void displayRoll(Player player, int rolledNum){
    int xPos = SCREEN_X_POS+10;
    int yPos = Y_OFFSET+2;

    SetConsoleCursorPosition(stdHandle, {(short)xPos, (short)yPos});

    cout << "NEW NUMBER IS " << rolledNum;
    yPos = nextLine(xPos,yPos);
    cout << "DO YOU WANT TO ADD IT TO YOUR LIST?";
    yPos = nextLine(xPos,yPos);

    cout << "Instead of " << player.playerList.arr[player.current];
    yPos = nextLine(xPos,yPos);


    SetConsoleCursorPosition(stdHandle, {0,(short)(yPos)});
    nextLine(0,DISPLAY_LENGTH+3);
    cout << "1 FOR YES, 0 FOR NO";
    nextLine(0,DISPLAY_LENGTH+4);

    cout << "> ";
}


void clearScreen(){
    // cout << "\x1B[2J\x1B[H";
    system("cls");

}


void updateScreen(Player player){
    clearScreen();
    SetConsoleCursorPosition(stdHandle, {0,0});

    displayInit();

    int indentation = P_INFO_X_POS+2;
    int yPos = Y_OFFSET+2;

    SetConsoleCursorPosition(stdHandle, {(short)indentation, (short)yPos});

    
    cout << "TURN: " << player.turnNumber;
    yPos = nextLine(indentation,yPos);

    // displayList(player);
    
    //player info
    cout << "NAME: " << player.name;
    yPos = nextLine(indentation,yPos);

    cout << "MONEY: " << player.money;
    yPos = nextLine(indentation,yPos);

    cout << "POWER: " << player.power;
    yPos = nextLine(indentation,yPos);
    
    cout << "LIST: ";
    for(int i = 0; i < player.listLength; i++){

        cout << player.playerList.arr[i] << ' ';
    }
    yPos = nextLine(indentation,yPos);


    cout << "NEXT BOSS: " << player.nextBoss;
    yPos = nextLine(indentation,yPos);



    SetConsoleCursorPosition(stdHandle, {0,0});
}

#endif //DISPLAY_H