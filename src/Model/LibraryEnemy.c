#include "Header/LibraryEnemy.h"

//constructeur
LibraryEnemy CreateLibraryEnemy()
{
    LibraryEnemy lib = malloc(sizeof(struct enemy_)*5);
    lib->count = 0;
    return lib;
}

//ajout dans la library
void addEnemy(LibraryEnemy lib, Enemy e){
    lib->tab[lib->count] = e;
    lib->count += 1;
}

//trouver un enemy en fonction de son nom
Enemy findByName(LibraryEnemy lib,  char name){
    for(int i = 0; i<=lib->count; i++)
    {
        if (name == lib->tab[i]->name)
        {
            return lib->tab[i];
        }

    }
    return NULL;
}

/*int main(){
    LibraryEnemy l = CreateLibraryEnemy();
    Enemy a = CreateEnemy('B', 2, 3, 4);
    Enemy f = CreateEnemy('O', 2, 3, 7);
    //printf("%c", a->name);
    addEnemy(l, a);
    addEnemy(l, f);
    Enemy yo = findByName(l, '8');
    printf("%d", yo->defense);
}*/