Potion createPotion(char name, Effect effect){
    Potion newPotion = malloc(sizeof(struct Potion));
    newPotion->name = name;
    newPotion->effect = effect;
    return newPotion;
};