#include "Header/Deplacement.h"
#include "../Model/Header/Player.h"
#include "../Model/Header/Level.h"

void move(Player player)
{
    char c = '0';
    scanf("%c", &c);
    switch (c)
    {
    case 'z':
        player->y += 1;
        break;
    case 'q':
        player->x -= 1;
        break;
    case 's':
        player->y -= 1;
        break;
    case 'd':
        player->x += 1;
        break;
    default:
        break;
    }

}

//fonction qi permet de tester le changement de position du joueur
void dispPos(Player player){
    system("cls");

    printf("%d \n%d \n", player->x, player->y);
    printf("Votre choix:");
}
