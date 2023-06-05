#include <stdio.h>
#include "../Model/Header/Level.h"
#include "../Model/Header/Matrix.h"
#include <stdlib.h>
#include <string.h>
#include <locale.h>

FILE *fptr;

char* removeChar(char *str, char c) {
    int i, j;
    int len = strlen(str);
    for (i = j = 0; i < len; i++) {
        if (str[i] != c) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    return str;
}

Level readLevelFile(char* filename) {
    Level newLevel = (Level) malloc(sizeof(struct level_));
    newLevel->filename = filename;
    char myString[100];
    char dataString[3000] = "";

// Open a file in read mode
    fptr = fopen(filename, "r");

// Read the content and print it
    int cpt = 0;
// Store the content of the file
    while(fgets(myString, 100, fptr)) {
        //printf("%s","oui");
        if(cpt < 30) {
            myString[strcspn(myString, "\n")] = '\0';
            strcat(dataString, myString);
        } else {
            if(cpt == 30){
                newLevel->filename_east = ";";
            } else if (cpt == 31){
                newLevel->filename_south = ";";
            } else if (cpt == 32){
                newLevel->filename_west = ";";
            } else if (cpt == 33){
                newLevel->filename_north = ";";
            }
        }
        cpt++;
        printf("%s", myString);
    }
    newLevel->matrix = (Matrix) newMatrix(30, dataString);

// Close the file
    fclose(fptr);
    return newLevel;
}