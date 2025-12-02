#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


typedef enum {Oddian = 1,Evengelion,Prime,Random,OneNumMan,Listed} playerClass;

#define MAX_LENGTH 20


class List{

    private:
    int front,rear,current;
    
    
    public:
    
        int arr[MAX_LENGTH];
        
        void display(int listLength){
            //check if its empty or not

            cout << "UR LIFE LIST" << endl;


            for(int i = 0; i < listLength; i++){ //just for debugging
                if(i % 5 == 0 && i != 0){
                    cout << endl;
                }

                cout << arr[i] << " ";
            }
            cout << endl;
        }
        


};




struct Player{

    char *name;
    int listLength;
    int level;
    int power;
    int remainingCell;
    playerClass pClass;
    // ClassFunc classFunc;
    List playerList;
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
            cout << "1 TO 4" << endl;
        }

        void turn(){

            
        }

        void shop(){



        }

        void bossfight(){



        }

        void playerClass(Player player){
                //elim ilen yapcam artık enum printlemiyor direkt
            switch (player.pClass)
            {
            case 1:
                cout << "Oddian";
                break;
            
            case 2:
                break;
            
            case 3:
                break;

            case 4:
                break;
            }

        }

        void classChoice(Player player,Display screen){

            cout << "You have choose the ";
            screen.playerClass(player);
            cout << "  Class..." << endl;
            cout << "I wish you luck" << endl << endl;



        }


};