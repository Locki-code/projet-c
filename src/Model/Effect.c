#include "Header/Effect.h"

Effect createEffect(char name, bool health, bool attack, bool defense){
    Effect newEffect = (Effect *) malloc(sizeof(struct Effect));
    newEffect->name = &name;
    newEffect->health = health;
    newEffect->attack = attack;
    newEffect->defense = defense;
    return newEffect;
};