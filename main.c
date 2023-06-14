//
// Created by Loïck on 17/05/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "src/Reader/Header/LevelReader.h"
#include "src/Reader/LevelReader.c"
#include <assert.h>
#include "src/Model/Matrix.c"
#include "src/Model/Header/Player.h"
#include "src/Model/Player.c"
#include "src/Interface/Deplacement.c"

int main(int argc, char *argv[]) {
    Level level = readLevelFile("config\\level1.level","level1.level");
    Player player = CreatePlayer();
    setElement(level->matrix, player->y, player->x, '@');
    move(player, level);
    //wprintf("%lc", getElement(level->matrix, 0, 1));
    //Matrix matrix = newMatrix(5, "##^###   #<   >#   ###v##");
    //printMatrix(level->matrix);
}