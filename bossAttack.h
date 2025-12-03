#include "classes.h"
#include "bossInit.h"

Player attack_OddCold(Player player,Boss oddcold){

    int attackRange[] = {1,3,5,7,9};

    int randomIndexInRange = rand() % ( ( sizeof(attackRange) / sizeof(attackRange[0]) ) - 1) ;
    int scaledAttack = attackRange[randomIndexInRange];


    //Selects index of attack in playerList
    int pListIndex = 0;
    do{
        pListIndex = rand() % player.listLength;


    }while(player.playerList.arr[pListIndex] % 2 == 1); // not sure about 1


    //ATTACK
    player.playerList.arr[pListIndex] = player.playerList.arr[pListIndex] - (oddcold.power * scaledAttack);



    return player;
}