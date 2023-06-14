#include <stdio.h>
#include <stdbool.h>
#include "./Header/Combat.h"

/*void isDead(Player player, Enemy enemy)
{
    char choice = '0';

    //Le joueur meurt, fin du jeu
    if (player->health <= 0)
    {
        system("cls");
        printf("You died\n\n\nExit(X)");

        while (true)
        {
            scanf("%c", &choice);

            if (choice == 'X' || choice == 'x')
            {
                exit(EXIT_SUCCESS);
                break;
            }
        }
    }
    //L'ennemi meurt, retour à la carte et ajout des bonus permanents
    else if (enemy->health <= 0)
    {
        player->health_max = player->health_max + 1;
        player->attack = player->attack + 1;
        //retour à la carte
    }

    return;
}*/

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

    while(executeRound(player, enemy) == false)
    {
        showStatsPlayer(player);
        showStatsEnemy(enemy);

        printf("Action\n----------\n Attack (A)\n Escape (E)\n----------\n");

        scanf("%c", &choice);
        fflush(stdin);

        printf("\n\n\n");
        if (choice == 'A' || choice == 'a')
        {
            printf("You're attacking\n\n");
        }
        
        else if (choice == 'E' || choice == 'e')
        {
            printf("Escape\n");
            return false;
            break;
        }
    }
    return isEnemyDead(enemy) || isPlayerDead(player);
}

void main()
{
    Player player = CreatePlayer();
    Enemy enemy = CreateEnemy('A', 10, 6, 1);

    actionPlayer(player, enemy);
}