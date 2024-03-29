#include <stdio.h>
#include <stdbool.h>
#include "./Header/Combat.h"

//baisse les pv de l'ennemi et du joueur en fonction de la defense et de l'attaque des deux
bool executeRound(Player player, Enemy enemy)
{
    int damagePlayerToEnemy = (player->attack - enemy->defense <= 0) ? 1 : player->attack - enemy->defense;

    enemy->health = enemy->health - damagePlayerToEnemy;

    if(isEnemyDead(enemy))
    {
        return true;
    }
    else
    {
        int damageEnemyToPlayer = (enemy->attack - player->defense <= 0) ? 1 : enemy->attack - player->defense;

        player->health = player->health - damageEnemyToPlayer;
        return (isPlayerDead(player)) ? true : false ;
    } 
}

bool actionPlayer(Player player, Enemy enemy)
{
    char choice = '0';

    while(executeRound(player, enemy) == false){
        showStatsPlayer(player);
        showStatsEnemy(enemy);

        printf("Action\n----------\n Attack (A)\n Escape (E)\n----------\n");

        scanf_s("%c", &choice);
        fflush(stdin);

        printf("\n\n\n");
        if (choice == 'A' || choice == 'a')
        {
            printf("You're attacking\n\n");
        }
        
        else if (choice == 'E' || choice == 'e')
        {
            printf("Escape\n");
            break;
        }
    }
    return isEnemyDead(enemy) || isPlayerDead(player);
}