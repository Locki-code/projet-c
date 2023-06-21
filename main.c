//
// Created by Loïck on 17/05/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "src/Reader/Header/LevelReader.h"
#include "src/Reader/Header/MobReader.h"
#include "src/Reader/LevelReader.c"
#include "src/Reader/MobReader.c"
#include <assert.h>
#include "src/Model/Matrix.c"
#include "src/Model/Header/Player.h"
#include "src/Model/Player.c"
#include "src/Interface/Deplacement.c"

int main(int argc, char *argv[]) {
    while(true){
        char c[1];
        printf("Menu\n-------------\n New Game (N)\n Credits (C)\n Exit (E)\n-------------\n");
        scanf_s("%s", c);
        switch(tolower(c[0])) {
            case 'n':
                if(true){}
                Level level_1 = readLevelFile("config\\level1.level","level1.level");
                Player player = CreatePlayer();
                LibraryEnemy enemyLib = CreateLibraryEnemy();
                setElement(level_1->matrix, player->y, player->x, '@');
                move(player, level_1, enemyLib);
                printf("GAME OVER !!!\n\n");
                continue;
            case 'c':
                printf("C Project - 2023\n");
                printf("Created By :\n\tLouise Horter\n\tJacques Mudoy\n\tHugo Assoignon\n\tLoick Mercier\n");
                printf("Last Update : 21/06/2023\n");
                continue;
            case 'e':
                break;
            default:
                printf("Wrong choice !");
                continue;
        }
        break;
    }
}