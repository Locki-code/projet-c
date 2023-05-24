#include <stdlib.h>
#include <stdio.h>
#include "Header/MobReader.h"
#include <string.h>

//sert juste à passer à la ligne suivante
void skipline(FILE *fp_, int t)
{
    while(t != '\n')
    {
        t = fgetc(fp_);
    }
}

//retourne la valeur de la ligne courante (ex:"attaque : 10" retourne 10)
int getValue(FILE *fp_, int t)
{
    int val;
    while(t != ':')
    {
        t = fgetc(fp_);
    }
    char tempVal[10] = "";
    while(t != '\n')
    {
        t = fgetc(fp_);
        char tp = t;
        strncat(tempVal, &tp, 1);
        val = atoi(tempVal);
    }
    return val;
}

//retourne la liste des mob dans un fichier.mob
Enemy * readMobFile(char * nameFile)
{
    Enemy * tab = malloc(sizeof(struct enemy_)*20);
    FILE * fp;
    fopen_s(&fp, nameFile, "r");
    int txt = 0;
    int it = 0;
    //la boucle permet de changer le fichier .mob en valeurs, puis les stocker dans la struct Enemy
    //on obtient donc un tableau de mob
    while(txt != EOF)
    {
        txt = fgetc(fp);
        char name = txt;
        int pv = getValue(fp, txt);
        int str = getValue(fp, txt);
        int att = getValue(fp, txt);
        //printf("%c:%d, %d, %d\n", name, pv, str, att);
        tab[it] = CreateEnemy(name, pv, str, att);
        //printf("%c:%d, %d, %d\n", tab[it]->name, tab[it]->pv, tab[it]->defense, tab[it]->attack);
        txt = fgetc(fp);
        if(txt != EOF)
            skipline(fp, txt);

        it+=1;
    }
    return tab;
}