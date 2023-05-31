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
        player->pos->y += 1;
        break;
    case 'q':
        player->pos->x -= 1;
        break;
    case 's':
        player->pos->y -= 1;
        break;
    case 'd':
        player->pos->x += 1;
        break;
    default:
        break;
    }

}

void dispPos(Player player){
    system("cls");
    printf("%d \n %d", player->pos->x, player->pos->x);
}



int main(){
    Player p1 = CreatePlayer(10, 10);
    printf("%d \n %d", p1->pos->x, p1->pos->x);

    /*while(1)
    {
        dispPos(p1);
        move(p1);
    }*/
}


