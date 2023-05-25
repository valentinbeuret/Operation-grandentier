#include <stdio.h>
#include <stddef.h>
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
    }
    printf("\n");
}


GrandEntier Somme(GrandEntier A, GrandEntier B)
{
    GrandEntier resultat_somme = {0};
    resultat_somme.Positif = true;

    int taille_somme;
    if (A.Taille >= B.Taille)
    {
        taille_somme = A.Taille;
    }
    else
    {
        taille_somme = B.Taille;
    }
    
    taille_somme++;
    int retenue[TailleMax] = {0};
    resultat_somme.Taille = taille_somme;

    if (A.Positif == true && B.Positif  == true)
    //printf("A et B sont positifs\n");
    {
        for (int i=0; i<taille_somme; i++)
        {
            int ret = 0;
            printf("%1d %1d %1d ",A.Digits[i], B.Digits[i], retenue[i]);
            if (A.Digits[i] + B.Digits[i] + retenue[i] >= Base)
            {
                resultat_somme.Digits[i] = (A.Digits[i] + B.Digits[i] + retenue[i]) % Base;
                ret = resultat_somme.Digits[i] / Base;
                retenue[i+1] = ret;
                printf(" superieur a base donc %1d\n",resultat_somme.Digits[i]);
            }
            else // cas sans retenu car inférieur à 10
            {
                resultat_somme.Digits[i] = A.Digits[i] + B.Digits[i] + retenue[i];
                printf(" inferieur a base donc %1d\n",resultat_somme.Digits[i]);
            }
        }
    }
    return resultat_somme;
}


GrandEntier Soustraction(GrandEntier A, GrandEntier B)
{
    GrandEntier resultat_soustraction = {0};
    resultat_soustraction.Positif = true;

    int taille_soustraction;
    if (((A.Taille == B.Taille) || (A.Taille > B.Taille)) && (A.Positif == true && B.Positif == true))
    {
        if (A.Digits[A.Taille] >= B.Digits[B.Taille]) // verifier si le dernier digits de A est plus grand que le dernier digits de B
        {
            taille_soustraction = A.Taille;
            for (int i=0; i<taille_soustraction; i++)
            {
                printf("%1d %1d",A.Digits[i], B.Digits[i]);
                if (A.Digits[i] < B.Digits[i])
                {
                    printf("%1d superieur a %1d on ajoute base", B.Digits[i], A.Digits[i]);
                    resultat_soustraction.Digits[i] = (A.Digits[i] + Base) - B.Digits[i];
                    printf(" resultat : %1d\n", resultat_soustraction.Digits[i]);
                    B.Digits[i+1]++;
                    //printf("verification du digits de B superieur : %1d\n", B.Digits[i+1]);
                }
                else
                {
                    resultat_soustraction.Digits[i] = A.Digits[i] - B.Digits[i];
                    printf(" %1d inferieur ou egal a %1d resultat : %1d\n",B.Digits[i], A.Digits[i], resultat_soustraction.Digits[i]);
                }
            }
        }
    }
    /*
    resultat_soustraction.Taille = taille_soustraction;

    if (A.Positif == true && B.Positif == true)
    {
        for (int i=0; i<taille_soustraction; i++)
        {
            printf("%1d %1d",A.Digits[i], B.Digits[i]);
            if (A.Digits[i] < B.Digits[i])
            {
                printf("%1d superieur a %1d on ajoute base", B.Digits[i], A.Digits[i]);
                resultat_soustraction.Digits[i] = (A.Digits[i] + Base) - B.Digits[i];
                printf(" resultat : %1d\n", resultat_soustraction.Digits[i]);
                B.Digits[i+1]++;
                //printf("verification du digits de B superieur : %1d\n", B.Digits[i+1]);
            }
            else
            {
                resultat_soustraction.Digits[i] = A.Digits[i] - B.Digits[i];
                printf(" %1d inferieur ou egal a %1d resultat : %1d\n",B.Digits[i], A.Digits[i], resultat_soustraction.Digits[i]);
            }
        }
    }
    */
    return resultat_soustraction;
}

/*
GrandEntier Multiplication()
{
   GrandEntier resultat_multplication = {0};



}
*/

int main()
{
    GrandEntier A = {0};
    A.Taille = 8;
    A.Positif = true;
    for (int i=0; i<A.Taille; i++)
    {
        A.Digits[i] = rand()%10;
    }
    printf("Grand Entier A : ");
    afficher_grand_entier(&A);

    GrandEntier B = {0};
    B.Taille = 8;
    B.Positif = true;
    for (int j=0; j<B.Taille; j++)
    {
        B.Digits[j] = rand()%10;
    }
    printf("Grand Entier B : ");
    afficher_grand_entier(&B);
    
    GrandEntier Som = Somme(A,B);
    afficher_grand_entier(&Som);
    
    GrandEntier Sou = Soustraction(A,B);
    afficher_grand_entier(&Sou);

    return 0;
}

