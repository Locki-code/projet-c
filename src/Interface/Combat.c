#include <stdio.h>
#include <stdbool.h>
#include "./Header/Combat.h"

void statsPlayer(Player player)
{
    int pv = player->pv;
    int attack = player->attack;
    int defense = player->defense;

    printf("Player\n------------\n pv : %d\n attack : %d\n defense : %d\n------------\n", pv, attack, defense);

    return;
}

void statsEnemy(Enemy enemy)
{
    int pv = enemy->pv;
    int attack = enemy->attack;
    int defense = enemy->defense;

    printf("Enemy\n------------\n pv : %d\n attack : %d\n defense : %d\n------------\n", pv, attack, defense);

    return;
}

void isDead(Player player, Enemy enemy)
{
    char choice = '0';

    //Le joueur meurt, fin du jeu
    if (player->pv <= 0)
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
        player->pv_max = player->pv_max + 1;
        player->attack = player->attack + 1;
        //retour à la carte
    }

    return;
}

//baisse les pv de l'ennemi et du joueur en fonction de la defense et de l'attaque des deux
void pvDown(Player player, Enemy enemy)
{
    //L'ennemi prend obligatoirement 1 de dégats même si sa défense est > à l'attaque du joueur
    if (enemy->defense - player->attack >= 0)
    {
        enemy->pv = enemy->pv - 1;
        isDead(player,enemy);

        //Le joueur prend obligatoirement 1 de dégats même si sa défense est > à l'attaque de l'ennemi
        if (player->defense - enemy->attack >= 0)
        {
            player->pv = player->pv - 1;
            isDead(player,enemy);
        }
        //Le joueur prend le nombre de dégats calculés en fonction de sa défense et de l'attaque de l'ennemi
        else
        {
            player->pv = player->pv - enemy->attack + player->defense;
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
            player->pv = player->pv - 1;
            isDead(player,enemy);
        }
        //Le joueur prend le nombre de dégats calculés en fonction de sa défense et de l'attaque de l'ennemi
        else
        {
            player->pv = player->pv - enemy->attack + player->defense;
            isDead(player,enemy);
        }
    }

    return;
}

void action(Player player, Enemy enemy)
{
    char choice = '0';

    printf("Action\n----------\n Attack (A)\n Escape (E)\n----------\n");

    pvDown(player, enemy);

    statsPlayer(player);
    statsEnemy(enemy);

    while(true)
    {
        scanf("%c", &choice);

        printf("\n\n\n");
        if (choice == 'A' || choice == 'a')
        {
            printf("You're attacking\n\n");
            pvDown(player, enemy);

            statsPlayer(player);
            statsEnemy(enemy);
        }
        
        else if (choice == 'E' || choice == 'e')
        {
            printf("Escape\n");
            break;
        }
    }
}