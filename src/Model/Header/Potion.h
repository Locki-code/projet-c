#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct potion_ {
    char* name;
    effect* effect;
}

typedef struct potion * potion_;

potion createPotion(char name, effect effect);