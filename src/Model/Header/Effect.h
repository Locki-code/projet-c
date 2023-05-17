#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct effect_ {
    char* name;
    bool health;
    bool attack;
    bool defense;
}

typedef struct effect_ * Effect;

Effect createEffect(char name, bool health, bool attack, bool defense);

