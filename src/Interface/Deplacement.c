#include "Header/Deplacement.h"
#include "../Model/Header/Player.h"
#include "../Model/Header/Level.h"
#include "../Model/Level.c"

void move(Player player, Level level)
{
    while(player->health>0) {
        printMatrix(level->matrix);
        char movementWanted;
        char c[1];
        scanf_s("%s", c);
        switch(c[0]) {
            case 'z':
                movementWanted = getElement(level->matrix, player->y + 1, player->x);
                switch (movementWanted) {
                    case ' ':
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    default:
                        printf("You can't move here");
                        continue;
                }
            case 'q':
                movementWanted = getElement(level->matrix, player->y, player->x - 1);
                switch (movementWanted) {
                    case ' ':
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    default:
                        printf("You can't move here");
                        continue;
                }
            case 's':
                movementWanted = getElement(level->matrix, player->y - 1, player->x);
                switch (movementWanted) {
                    case ' ':
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    default:
                        printf("You can't move here");
                        continue;
                }
            case 'd':
                movementWanted = getElement(level->matrix, player->y, player->x + 1);
                switch (movementWanted) {
                    case ' ':
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    default:
                        printf("You can't move here");
                        continue;
                }
            default:
                printf("Wrong keypress !");
                continue;
        }
    }
}

//fonction qi permet de tester le changement de position du joueur
void dispPos(Player player){
    system("cls");

    printf("%d \n%d \n", player->x, player->y);
    printf("Votre choix:");
}
