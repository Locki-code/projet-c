#include <stdlib.h>
#include <stdio.h>
#include "Header/MobReader.h"
#include <string.h>

//permet de découper un ligne en deux via le séparateur ":" et d'extraire le chiffre de la partie de droite
int getDigit(char * def){
    char * token = strtok(def, ":");
    char * value = strtok(NULL, ":");
    int val = atoi(value);
    return val;
}

//on lit chaque ligne et on extrait le chiffre du string pour créer l'Enemy
Enemy readMob(FILE * fp){
    int hp, att, def;
    //=================le nom du mob====================
    char nom = fgetc(fp);
    fgetc(fp);

    //=================les pv du mob====================
    char * pv = (char *)malloc(14);
    fgets(pv, 14, fp);
    hp=getDigit(pv);

    //=================l'atak du mob====================
    char * strength = (char *)malloc(14);
    fgets(strength, 14, fp);
    att = getDigit(strength);

    //=================la def du mob====================
    char * defense = (char *)malloc(14);
    fgets(defense, 14, fp);
    def = getDigit(defense);

    Enemy e = CreateEnemy(nom, hp, att, def);
    fgetc(fp);                  //permet de passer au mob suivant
    free(pv);
    free(strength);
    free(defense);
    return e;
}

//lit tous les mobs à partir de la fonction précedente (max 5 mobs)
LibraryEnemy readAllMobs(FILE * fp){
    Enemy tmp = CreateEnemy('O', 0, 0, 0);
    LibraryEnemy lib = CreateLibraryEnemy();
    for(int i=0; i<5; i++)
    {
        tmp = readMob(fp);
        addEnemy(lib, tmp);
    }
    return lib;
}

void printMob(Enemy en){
    printf("%c:\n%d\n%d\n%d\n\n", en->name, en->health, en->attack, en->defense);
}

//main de test
/*int main(){
    FILE * fp;
    fp = fopen("C:/Users/jacqu/Desktop/Projet-C/projet-c/config/enemy.mob", "r");
    LibraryEnemy l = readAllMobs(fp);
    printf("%c", l->tab[3]->name);
    fclose(fp);
    return 0;
}*/