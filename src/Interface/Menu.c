#include <stdio.h>
#include <stdlib.h>



void DisplayMenu()
{
    int choice;
    printf("%s","Bienvenue, dans Maze & Mind game!\n");
    printf("1 - Nouvelle partie\n2 - Crédits\n3 - Quitter\n");//faire chcp 65001 dans un terminal avant d'executer le .exe pour faire de l'affichage utf-8
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        /* appellera la fonction reader et deplacement en boucle tant que pas victoire ou défaite*/
        printf("Nouvelle partie");
       
        break;
    case 2:
        printf("Voici les crédits :\nHugo Assoignon | Louise Hortier | Jacques Mudoy | Loïck Mercier\n");
        printf("Dernière modif : 7/6/23");
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
    DisplayMenu();
    return 0;
}
