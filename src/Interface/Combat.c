#include <stdio.h>
#include <stdbool.h>
#include "./Header/Combat.h"

void isDead(Player player, Enemy enemy)
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
    else if (enemy->pv <= 0)
    {
        player->health_max = player->health_max + 1;
        player->attack = player->attack + 1;
        //retour à la carte
    }

    return;
}

//baisse les pv de l'ennemi et du joueur en fonction de la defense et de l'attaque des deux
void executeRound(Player player, Enemy enemy)
{
    //L'ennemi prend obligatoirement 1 de dégats même si sa défense est > à l'attaque du joueur
    if (enemy->defense - player->attack >= 0)
    {
        enemy->pv = enemy->pv - 1;
        isDead(player,enemy);

        //Le joueur prend obligatoirement 1 de dégats même si sa défense est > à l'attaque de l'ennemi
        if (player->defense - enemy->attack >= 0)
        {
            player->health = player->health - 1;
            isDead(player,enemy);
        }
        //Le joueur prend le nombre de dégats calculés en fonction de sa défense et de l'attaque de l'ennemi
        else
        {
            player->health = player->health - enemy->attack + player->defense;
            isDead(player,enemy);
        }
    }
    //L'ennemi prend le nombre de dégats calculés en fonction de sa défense et de l'attaque du joueur
    else
    {
        enemy->pv = enemy->pv - player->attack + enemy->defense;
        isDead(player,enemy);

        //Le joueur prend obligatoirement 1 de dégats même si sa défense est > à l'attaque de l'ennemi
        if (player->defense - enemy->attack >= 0)
        {
            player->health = player->health - 1;
            isDead(player,enemy);
        }
            //Le joueur prend le nombre de dégats calculés en fonction de sa défense et de l'attaque de l'ennemi
        else
        {
            player->health = player->health - enemy->attack + player->defense;
            isDead(player,enemy);
        }
    }


    return;
}

void actionPlayer(Player player, Enemy enemy)
{
    char choice = '0';

    printf("Action\n----------\n Attack (A)\n Escape (E)\n----------\n");

    executeRound(player, enemy);

    showStatsPlayer(player);
    showStatsEnemy(enemy);

    while(true)
    {
        scanf("%c", &choice);

        printf("\n\n\n");
        if (choice == 'A' || choice == 'a')
        {
            printf("You're attacking\n\n");
            executeRound(player, enemy);

            showStatsPlayer(player);
            showStatsEnemy(enemy);
        }
        
        else if (choice == 'E' || choice == 'e')
        {
            printf("Escape\n");
            break;
        }
    }
}