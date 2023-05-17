#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Effect.h"

struct potion_ {
    char* name;
    Effect effect;
};

typedef struct potion_ * Potion;

Potion createPotion(char name, Effect effect);