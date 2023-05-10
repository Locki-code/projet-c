#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct potion_ {
    char* name;
    effect* effect;
}

typedef struct potion_ * Potion;

Potion createPotion(char name, effect effect);