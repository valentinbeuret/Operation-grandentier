#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> // Permet d’utiliser des variables de type booléen
#define Base 10 // La base 10 est la plus simple à utiliser
#define TailleMax 1000 // Nombre maximum de Digits 

typedef struct 
{
    int Digits[TailleMax]; // Tableau pour stocker les Digits du "Grand Entier"
    int Taille; // Nombre de Digits significatifs dans le tableau
    bool Positif; // Indique si le Grand Entier est négatif (false) ou positif (true)
} GrandEntier;

void afficher_grand_entier(const GrandEntier *entier) 
{
    // Afficher le signe du grand entier
    if (entier->Positif) 
    {
        printf("+");
    }
    else 
    {
        printf("-");
    }
    // Afficher le premier Digit sans zéro de remplissage
    printf("%d", entier->Digits[entier->Taille - 1]);
    // Afficher les Digits restants du grand entier avec le zéro de remplissage approprié
    for (int i = entier->Taille - 2; i >= 0; i--) 
    {
        printf("%1d", entier->Digits[i]);
        // Sur certains compilateurs on peut juste mettre
        // printf("%d", entier->Digits[i]);
        // et l’affichage sera "correct" (i.e.: sans "espaces parasites")
    }
}

/*
void Somme()
{
    int bonne_taille;

    if (A->Positif && B->Positif)
    {
        for (int i=0; i<entier->Taille; i++)
        {
            if (A.Digits[i] + B.Digits[i] > Base)
            {

            }
            
        }
    }
    else
    {
        break;
    }

}
*/

void Soustraction()
{


    
}


void Multiplication()
{



}


int main()
{
    GrandEntier A = {0}; // Initialiser tous les éléments à 0
    // Chaque élément du tableau A.Digits
    // est "mis à 0", par sécurité

    A.Taille = 8;
    A.Positif = true;
    for (int i=0; i<A.Taille; i++)
    {
        A.Digits[i] = rand()%10;
    }
    afficher_grand_entier(&A);

    printf("\n");

    GrandEntier B = {0};
    B.Taille = 10;
    B.Positif = true;
    for (int i=0; i<B.Taille; i++)
    {
        B.Digits[i] = rand()%10;
    }
    afficher_grand_entier(&B);
    return 0;
}

