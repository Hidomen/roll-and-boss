#include "classes.h"
#include "bossInit.h"


Player attack_OddCold(Player player,Boss oddcold){

    int attackRange[] = {1, 3, 5, 7, 9};
    int randomIndexInRange = getRandom(sizeof(attackRange) / sizeof(attackRange[0]) - 1);
    
    int scaledAttack = attackRange[randomIndexInRange];

    //Selects index of attack in playerList
    int targetNumberIndex = 0;
    do{
        targetNumberIndex = getRandom(player.listLength);

    }while(player.playerList.arr[targetNumberIndex] % 2 == 1); // not sure about 1

    //ATTACK
    player.playerList.arr[targetNumberIndex] = player.playerList.arr[targetNumberIndex] - (oddcold.power * scaledAttack);

    return player;
}