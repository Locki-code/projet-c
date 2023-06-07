#include <stdio.h>
#include "../Model/Header/Level.h"
#include "../Model/Header/Matrix.h"
#include <stdlib.h>
#include <string.h>
#include <locale.h>

FILE *fptr;

// Funtion removing spaces from string
char * removeSpacesFromStr(char *string)
{
    // non_space_count to keep the frequency of non space characters
    int non_space_count = 0;

    //Traverse a string and if it is non space character then, place it at index non_space_count
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ')
        {
            string[non_space_count] = string[i];
            non_space_count++;//non_space_count incremented
        }
    }

    //Finally placing final character at the string end
    string[non_space_count] = '\0';
    return string;
}

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
            char *token = strtok( removeSpacesFromStr(myString), ":");
            token = strtok(NULL, ":");
            if(cpt == 30){
                newLevel->filename_east = token;
            } else if (cpt == 31){
                newLevel->filename_south = token;
            } else if (cpt == 32){
                newLevel->filename_west = token;
            } else if (cpt == 33){
                newLevel->filename_north = token;
            }
        }
        cpt++;
    }
    newLevel->matrix = (Matrix) newMatrix(30, dataString);

// Close the file
    fclose(fptr);
    return newLevel;
}