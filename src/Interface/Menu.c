#include <stdio.h>
#include <stdlib.h>

void affichemenu()
{
    int choix;
    printf("1 - Nouvelle partie\n2 - Crédits\n3 - Quitter\n");
    scanf("%d",&choix);
    switch(choix)
    {
    case 1:
        /* appellera la fonction d'interface de la nouvelle partie, pour tester ; print nouvelle partie */
        printf("Nouvelle partie");
       
        break;
    case 2:
        printf("Voici les crédits :\nHugo Assoignon | Louise Hortier | Jacques Mudoy | Loïck Mercier\n");
        printf("Dernière modif : 31/5/23");
        break;
    case 3:
        printf("Vous avez mis fin au jeu !!");//exit qui termine le porgramme avec le code succès qui correspond à la valeur 0 lors du return
        exit(EXIT_SUCCESS);
        break;
    default:
    printf("erreur");
        break;
    }
}

int main()
{
    affichemenu();
    return 0;
}
