#include <stdio.h>
#include <stdbool.h>
#include "Model/Header/Player.h"
#include "Model/Header/Enemy.h"

void statsPlayer(Player player)
{
    system("cls");

    int pv = player->pv;
    int attack = player->attack;
    int defense = player->defense;

    printf("------------\n pv : %d\n attack : %d\n defense : %d\n------------", pv, attack, defense);
}

void statsEnemy(Enemy enemy)
{
    system("cls");

    int pv = enemy->pv;
    int attack = enemy->attack;
    int defense = enemy->defense;

    printf("------------\n pv : %d\n attack : %d\n defense : %d\n------------", pv, attack, defense);
}

void isDead(Player p, Enemy e)
{
    if (p->pv <= 0)
    {
        //fin du jeu
    }
    else if (e->pv <= 0)
    {
        //retour à la carte
    }

    return;
}

void damageCalculation(bool attacker, Player p, Enemy e) //attacker = false enemy, attacker = true player
{
    int startpv_player = p->pv;
    int startpv_enemy = e->pv;

    while (startpv_player == p->pv && startpv_enemy == e->pv)
    {
        if (attacker)
        {
            if (e->defense - p->attack >= 0)
            {
                e->pv = e->pv - 1;
                attacker = false;
                isDead(p,e);
            }
            else
            {
                e->pv = e->pv - p->attack + e->defense;
                attacker = false;
                isDead(p,e);
            }
        }
        else
        {
            if (p->defense - e->attack >= 0)
            {
                p->pv = player->pv - 1;
                attacker = true;
                isDead(p,e);
            }
            else
            {
                p->pv = p->pv - e->attack + p->defense;
                attacker = true;
                isDead(p,e);
            }
        }
    }
}

void action(Player p, Enemy e)
{
    char choice = '';
    bool attacker = true;

    printf("----------\n Attack (A)\n Escape (E)\n----------");

    scanf("%c", choice);

    while (choice != 'E' || choice != 'e')
    {
        damageCalculation(attacker, p, e);
        scanf("%c", choice);
    }

    CreatePlayer
    statsPlayer()
    
}

int main()
{

}