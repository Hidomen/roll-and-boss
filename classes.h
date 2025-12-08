#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


#ifndef CLASSES_H
#define CLASSES_H

typedef enum {Oddian = 1,Evengelion,Prime,Random,OneNumMan,Listed} playerClass;

//there should be better way to find and use their index numbers 
#define ODDIAN_INDEX 1
#define EVENGELION_INDEX 2
#define PRIME_INDEX 3
#define RANDOM_INDEX 4
#define ONENUMMAN_INDEX 5
#define LISTED_INDEX 6


#define MAX_LENGTH 20
#define MAX_NUMBER 100


class List{

    public:
        int front,rear;
        int arr[MAX_LENGTH];
        
        
};


struct Player{

    char *name;

    List playerList;
    int listLength;
    int remainingCell;
    int current = 0;
    
    int level = 1;
    int power;
    playerClass pClass;
    
    int money = 8;

    // Display screen;
};


class Display{
    //before every display operation clear the screen
    public:
        void intro(){
            
            // cout << "Hello Stranger, welcome to the nameless for now village. " << endl;
            // cout << "Be careful, people around this village are very cruel. They don't want any new people" << endl;
            // cout << "They kind of corrupted..." << endl;
            // cout << "Anyways. Let me introduce my special assistant. ____" << endl;
            // cout << "____ going to guide you to choose your class. Classes will help you through your journey in this village" << endl;

            cout << "~sOMe GibBerIsh TaLK~" << endl;
            cout << "1 TO " << 5 << endl;
        }

        void list(Player player){
            //check if its empty or not

            cout << "UR LIFE LIST" << endl;

            for(int i = 0; i < player.listLength; i++){ //just for debugging
                if(i % 5 == 0 && i != 0){ // to have more clear visual ends line for every 5
                    cout << endl;
                }
                cout << player.playerList.arr[i] << " ";
            }
            cout << endl;
        }

        void turn(Player player, int turnNumber){

            cout << "TURN: " << turnNumber << endl << endl << endl;
            list(player);
        }

        void shop(){

        }

        void numberShop(Player player, int slots[]){

            cout << endl << endl;
            for(int i = 0; i < 3; i++){

                cout << "[  " << slots[i] << "  ]";
            }
            cout << endl;
            cout << "CURRENT: " << player.current+1 << " -----> " << player.playerList.arr[player.current] << endl;
            cout << "PICK ONE OF THESE NUMBERS: [1,2,3]" << endl;
            cout << "> ";
        }

        void bossfight(){

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

        void classChoice(Player player,Display screen){

            cout << "You have choose the ";
            screen.pClass(player);
            cout << "  Class..." << endl;
            cout << "I wish you luck" << endl << endl;
        }

        void roll(Player player, int rolledNum){
            
            cout << endl << "NEW NUMBER IS " << rolledNum << endl;
            cout << "DO YOU WANT TO ADD IT TO YOUR LIST?" << endl;
            cout << "Instead of " << player.playerList.arr[player.current]  << endl;
            cout << endl << endl << "1 FOR YES, 0 FOR NO" << endl;
            cout << "> ";
        }


};

#endif //CLASSES_H