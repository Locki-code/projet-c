#include "./Header/Deplacement.h"
#include "../Model/Header/Player.h"
#include "../Model/Header/Level.h"
#include "../Model/Level.c"
#include "../Model/Header/Enemy.h"
#include "../Model/Enemy.c"
#include "./Combat.c"
#include <stdbool.h>
#include "./Header/Combat.h"
#include "../Model/Header/Player.h"
#include "../Model/Player.c"

void move(Player player, Level level)
{
    while(player->health>0) {
        printMatrix(level->matrix);
        char movementWanted;
        char c[1];
        scanf_s("%s", c);
        switch(c[0]) {
            case 'z':
                movementWanted = getElement(level->matrix, player->y - 1, player->x);
                switch (movementWanted) {
                    case ' ':
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case 'o':
                        if(player->keys >0){
                            player->keys -= 1;
                            setElement(level->matrix, player->y, player->x, ' ');
                            player->y -= 1;
                            setElement(level->matrix, player->y, player->x, '@');
                            continue;
                        }
                        else {
                            printf("You can't open the door, key needed !");
                        }
                    case '!':
                        player->keys += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case 'S':
                        player->health = player->health_max;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case '1':
                        player->attack += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case '2':
                        player->defense += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case '3':
                        player->health_max += 3;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case 'A':
                    case 'B':
                    case 'C':
                        if(true){}
                        Enemy mob = CreateEnemy('A', 10, 6, 1); // TODO : Get the right enemy
                        if(actionPlayer(player, mob)){
                            if (isPlayerDead(player)){
                                break; // TODO : Game Over !!!
                            }
                            player->health_max += 1;
                            player->attack += 1;
                            setElement(level->matrix, player->y, player->x, ' ');
                            player->y -= 1;
                            setElement(level->matrix, player->y, player->x, '@');
                        }
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
                        continue;case 'o':
                        if(player->keys >0){
                            player->keys -= 1;
                            setElement(level->matrix, player->y, player->x, ' ');
                            player->x -= 1;
                            setElement(level->matrix, player->y, player->x, '@');
                            continue;
                        }
                        else {
                            printf("You can't open the door, key needed !");
                        }
                    case '!':
                        player->keys += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case 'S':
                        player->health = player->health_max;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case '1':
                        player->attack += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case '2':
                        player->defense += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case '3':
                        player->health_max += 3;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case 'A':
                    case 'B':
                    case 'C':
                        if(true){}
                        Enemy mob = CreateEnemy('A', 10, 6, 1); // TODO : Get the right enemy
                        if(actionPlayer(player, mob)){
                            if (isPlayerDead(player)){
                                break; // TODO : Game Over !!!
                            }
                            player->health_max += 1;
                            player->attack += 1;
                            setElement(level->matrix, player->y, player->x, ' ');
                            player->x -= 1;
                            setElement(level->matrix, player->y, player->x, '@');
                        }
                        continue;
                    default:
                        printf("You can't move here");
                        continue;
                }
            case 's':
                movementWanted = getElement(level->matrix, player->y + 1, player->x);
                switch (movementWanted) {
                    case ' ':
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;case 'o':
                        if(player->keys >0){
                            player->keys -= 1;
                            setElement(level->matrix, player->y, player->x, ' ');
                            player->y += 1;
                            setElement(level->matrix, player->y, player->x, '@');
                            continue;
                        }
                        else {
                            printf("You can't open the door, key needed !");
                        }
                    case '!':
                        player->keys += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case 'S':
                        player->health = player->health_max;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case '1':
                        player->attack += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case '2':
                        player->defense += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case '3':
                        player->health_max += 3;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case 'A':
                    case 'B':
                    case 'C':
                        if(true){}
                        Enemy mob = CreateEnemy('A', 10, 6, 1); // TODO : Get the right enemy
                        if(actionPlayer(player, mob)){
                            if (isPlayerDead(player)){
                                break; // TODO : Game Over !!!
                            }
                            player->health_max += 1;
                            player->attack += 1;
                            setElement(level->matrix, player->y, player->x, ' ');
                            player->y += 1;
                            setElement(level->matrix, player->y, player->x, '@');
                        }
                        continue;
                    default:
                        printf("Movement : %c", movementWanted);
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
                        continue;case 'o':
                        if(player->keys >0){
                            player->keys -= 1;
                            setElement(level->matrix, player->y, player->x, ' ');
                            player->x += 1;
                            setElement(level->matrix, player->y, player->x, '@');
                            continue;
                        }
                        else {
                            printf("You can't open the door, key needed !");
                        }
                    case '!':
                        player->keys += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case 'S':
                        player->health = player->health_max;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case '1':
                        player->attack += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case '2':
                        player->defense += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case '3':
                        player->health_max += 3;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case 'A':
                    case 'B':
                    case 'C':
                        if(true){}
                        Enemy mob = CreateEnemy('A', 10, 6, 1); // TODO : Get the right enemy
                        if(actionPlayer(player, mob)){
                            if (isPlayerDead(player)){
                                break; // TODO : Game Over !!!
                            }
                            player->health_max += 1;
                            player->attack += 1;
                            setElement(level->matrix, player->y, player->x, ' ');
                            player->x += 1;
                            setElement(level->matrix, player->y, player->x, '@');
                        }
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
