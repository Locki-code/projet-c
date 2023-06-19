#include "./Header/Deplacement.h"
#include "../Model/Level.c"
#include "../Model/Header/LibraryEnemy.h"
#include "../Model/LibraryEnemy.c"
#include "../Model/Enemy.c"
#include "./Combat.c"
#include <stdbool.h>

void move(Player player, Level level, LibraryEnemy enemyLib)
{
    char* message = "";
    while(player->health>0) {
        //system("cls");
        printMatrix(level->matrix, player);
        printf("%s\n", message);
        message = "";
        char movementWanted;
        char c[1];
        scanf_s("%s", c);
        switch(tolower(c[0])) {
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
                            message = ("Door open !");
                            continue;
                        }
                        else {
                            message = ("You can't open the door, key needed !");
                        }
                    case '!':
                        player->keys += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("Key Added !");
                        continue;
                    case '?':
                        message = ("You can't move here, Work In Progress !!!");
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
                        message = ("+ 1 Attack");
                        continue;
                    case '2':
                        player->defense += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("+ 1 Defense");
                        continue;
                    case '3':
                        player->health_max += 3;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("+ 3 Health max ");
                        continue;
                    case 'A':
                    case 'B':
                    case 'C':
                        if(true){}
                        /*char name[128];
                        snprintf(name, sizeof(name), "%c_%s_%d_%d", movementWanted, level->filename, player->y -1, player->x);;
                        Enemy mob = findByName(enemyLib, *name);
                        if(mob == NULL){
                            Enemy original = findByName(enemyLib, movementWanted);
                            addEnemy(
                                    enemyLib,
                                    CreateEnemy(*name, original->health, original->attack, original->defense)
                                    );
                            mob = findByName(enemyLib, *name);
                        }*/
                        Enemy mob = CreateEnemy('A', 5, 1, 1); // TODO : Get the right enemy
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
                        message = ("You can't move here");
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
                    case 'o':
                        if(player->keys >0){
                            player->keys -= 1;
                            setElement(level->matrix, player->y, player->x, ' ');
                            player->x -= 1;
                            setElement(level->matrix, player->y, player->x, '@');
                            message = ("Door open !");
                            continue;
                        }
                        else {
                            message = ("You can't open the door, key needed !");
                        }
                    case '!':
                        player->keys += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("Key Added !");
                        continue;
                    case '?':
                        message = ("You can't move here, Work In Progress !!!");
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
                        message = ("+ 1 Attack");
                        continue;
                    case '2':
                        player->defense += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("+ 1 Defense");
                        continue;
                    case '3':
                        player->health_max += 3;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x -= 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("+ 3 Health max");
                        continue;
                    case 'A':
                    case 'B':
                    case 'C':
                        if(true){}
                        Enemy mob = CreateEnemy('A', 5, 1, 1); // TODO : Get the right enemy
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
                        message = ("You can't move here");
                        continue;
                }
            case 's':
                movementWanted = getElement(level->matrix, player->y + 1, player->x);
                switch (movementWanted) {
                    case ' ':
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        continue;
                    case 'o':
                        if(player->keys >0){
                            player->keys -= 1;
                            setElement(level->matrix, player->y, player->x, ' ');
                            player->y += 1;
                            setElement(level->matrix, player->y, player->x, '@');
                            message = ("Door open !");
                            continue;
                        }
                        else {
                            message = ("You can't open the door, key needed !");
                        }
                    case '!':
                        player->keys += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("Key Added !");
                        continue;
                    case '?':
                        message = ("You can't move here, Work In Progress !!!");
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
                        message = ("+ 1 Attack");
                        continue;
                    case '2':
                        player->defense += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("+ 1 Defense");
                        continue;
                    case '3':
                        player->health_max += 3;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->y += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("+ 3 Health max");
                        continue;
                    case 'A':
                    case 'B':
                    case 'C':
                        if(true){}
                        Enemy mob = CreateEnemy('A', 5, 1, 1); // TODO : Get the right enemy
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
                        message = ("You can't move here");
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
                    case 'o':
                        if(player->keys >0){
                            player->keys -= 1;
                            setElement(level->matrix, player->y, player->x, ' ');
                            player->x += 1;
                            setElement(level->matrix, player->y, player->x, '@');
                            message = ("Door open !");
                            continue;
                        }
                        else {
                            message = ("You can't open the door, key needed !");
                        }
                    case '!':
                        player->keys += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("Key Added !");
                        continue;
                    case '?':
                        message = ("You can't move here, Work In Progress !!!");
                        continue;
                    case 'S':
                        player->health = player->health_max;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("Key Added !");
                        continue;
                    case '1':
                        player->attack += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("+ 1 Attack");
                        continue;
                    case '2':
                        player->defense += 1;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("+ 1 Defense");
                        continue;
                    case '3':
                        player->health_max += 3;
                        setElement(level->matrix, player->y, player->x, ' ');
                        player->x += 1;
                        setElement(level->matrix, player->y, player->x, '@');
                        message = ("+ 3 Health max");
                        continue;
                    case 'A':
                    case 'B':
                    case 'C':
                        if(true){}
                        Enemy mob = CreateEnemy('A', 5, 1, 1); // TODO : Get the right enemy
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
                        message = ("You can't move here");
                        continue;
                }
            default:
                message = ("Wrong keypress !");
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
