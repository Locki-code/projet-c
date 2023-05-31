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

void isDead(Player p, Enemy e)
{
    char choice = '0';

    //Le joueur meurt, fin du jeu
    if (p->pv <= 0)
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
    else if (e->pv <= 0)
    {
        p->pv_max = p->pv_max + 1;
        p->attack = p->attack + 1;
        //retour à la carte
    }

    return;
}

//baisse les pv de l'ennemi et du joueur en fonction de la defense et de l'attaque des deux
void pvDown(Player p, Enemy e)
{
    //L'ennemi prend obligatoirement 1 de dégats même si sa défense est > à l'attaque du joueur
    if (e->defense - p->attack >= 0)
    {
        e->pv = e->pv - 1;
        isDead(p,e);

        //Le joueur prend obligatoirement 1 de dégats même si sa défense est > à l'attaque de l'ennemi
        if (p->defense - e->attack >= 0)
        {
            p->pv = p->pv - 1;
            isDead(p,e);
        }
        //Le joueur prend le nombre de dégats calculés en fonction de sa défense et de l'attaque de l'ennemi
        else
        {
            p->pv = p->pv - e->attack + p->defense;
            isDead(p,e);
        }    
    }
    //L'ennemi prend le nombre de dégats calculés en fonction de sa défense et de l'attaque du joueur
    else
    {
        e->pv = e->pv - p->attack + e->defense;
        isDead(p,e);

        //Le joueur prend obligatoirement 1 de dégats même si sa défense est > à l'attaque de l'ennemi
        if (p->defense - e->attack >= 0)
        {
            p->pv = p->pv - 1;
            isDead(p,e);
        }
        //Le joueur prend le nombre de dégats calculés en fonction de sa défense et de l'attaque de l'ennemi
        else
        {
            p->pv = p->pv - e->attack + p->defense;
            isDead(p,e);
        }
    }

    return;
}

void action(Player p, Enemy e)
{
    char choice = '0';

    printf("Action\n----------\n Attack (A)\n Escape (E)\n----------\n");

    pvDown(p, e);

    statsPlayer(p);
    statsEnemy(e);

    while(true)
    {
        scanf("%c", &choice);

        printf("\n\n\n");
        if (choice == 'A' || choice == 'a')
        {
            printf("You're attacking\n\n");
            pvDown(p, e);

            statsPlayer(p);
            statsEnemy(e);
        }
        
        else if (choice == 'E' || choice == 'e')
        {
            printf("Escape\n");
            break;
        }
    }
}
