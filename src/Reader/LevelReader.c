#include <stdio.h>
#include "../Model/Header/Level.h"
#include "Header/LevelReader.h"

FILE *fptr;

Level ReadLevelFile(char* filename) {
// Open a file in read mode
    fptr = fopen(filename, "r");

// Store the content of the file
    char myString[100];

// Read the content and store it inside myString
    fgets(myString, 100, fptr);

// Print the file content
    printf("%s", myString);

// Close the file
    fclose(fptr);
}