#include "classes.h"


struct Boss{
    int health;
    int power;

    bool isRelease = false;
};

float Scale[] = {1.25,1.5,1.75,2};

#define BASIC 0
#define MEDIUM 1
#define HARD 2
#define EXTRA_HARD 3

Boss bossInit(Boss boss, Player player, int powerScale, int healthScale){

    boss.power = player.level * Scale[powerScale];
    boss.health = player.level * 100 * Scale[healthScale];

    return boss;
}

// Boss initOddCold (Player player){
//     Boss oddcold = bossInit(oddcold, player, MEDIUM, HARD);


//     return oddcold;
// }

// Boss evengelion(Player player){
//     Boss evengelion = bossInit(evengelion,player,MEDIUM,HARD);

//     return evengelion;
// }