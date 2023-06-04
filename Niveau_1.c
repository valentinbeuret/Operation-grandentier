#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> // Permet d’utiliser des variables de type booléen
#define Base 10 // La base 10 est la plus simple à utiliser
#define TailleMax 3 // Nombre maximum de Digits 

typedef struct 
{
    int Digits[TailleMax]; // Tableau pour stocker les Digits du "Grand Entier"
    int Taille; // Nombre de Digits significatifs dans le tableau
    bool Positif; // Indique si le Grand Entier est négatif (false) ou positif (true)
} GrandEntier;

void afficher_grand_entier(const GrandEntier *entier) 
{
    if (entier->Positif) 
    {
        printf("+");
    }
    else 
    {
        printf("-");
    }
    printf("%d", entier->Digits[entier->Taille - 1]);
    for (int i = entier->Taille - 2; i >= 0; i--) 
    {
        printf("%1d", entier->Digits[i]);
    }
    printf("\n");
}


bool Egal_A(GrandEntier A, GrandEntier B)
{
    GrandEntier resultat_egal = {0};
    resultat_egal.Postif = true;

    for (int i=0; i<TailleMax; i++)
    {
        if (A.Digits[i] == B.Digits[i])
        {
            resultat_egal.Postif = true;
        }
        else
        {
            resultat_egal.Postif = false;
            break;
        }
    }
    return resultat_egal;
}


bool Different_De(GrandEntier A, GrandEntier B)
{
    GrandEntier resultat_different = {0};
    resultat_different.Positif = false;

    for (int i=0; i<TailleMax; i++)
    {
        if (A.Digits[i] != B.Digits[i])
        {
            resultat_different.Positif = true;
        }
    }
    return 
}


bool Inferieur_A(GrandEntier A, GrandEntier B)
{   
    for (int i=TailleMax; i>0; i--)
    {
        if (B.Digits[i] > A.Digits[i])
        {
            return false;
        }
    }
    return true;
}

/*
GrandEntier Inferieur_Ou_Egal_A(GrandEntier A, GrandEntier B)
{
    GrandEntier resultat_inferieur_ou_egal = {0};

    if ((resultat_egal.Postif == true) || (resultat_inferieur.Positif == true))
    {
        resultat_inferieur_ou_egal.Positif = true;
    }
}

*/
GrandEntier Somme(GrandEntier A, GrandEntier B)
{
    GrandEntier resultat_somme = {0};
    resultat_somme.Positif = true;

    int retenue[TailleMax] = {0};
    resultat_somme.Taille = TailleMax;

    if (A.Positif == true && B.Positif  == true)
    {
        for (int i=0; i<TailleMax; i++)
        {
            int ret = 0;
            printf("%1d %1d %1d ",A.Digits[i], B.Digits[i], retenue[i]);
            if (A.Digits[i] + B.Digits[i] + retenue[i] >= Base)
            {
                resultat_somme.Digits[i] = (A.Digits[i] + B.Digits[i] + retenue[i]) % Base;
                ret = (A.Digits[i] + B.Digits[i] + retenue[i]) / Base;
                retenue[i+1] = ret;
                printf(" superieur a base donc %1d\n",resultat_somme.Digits[i]);
            }
            else
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

    bool inferieur = Inferieur_A(A,B);
    int taille_soustraction;
    if ((inferieur == false) && (A.Positif == true && B.Positif == true))
    {
        taille_soustraction = A.Taille;
        resultat_soustraction.Taille = taille_soustraction;
        for (int i=0; i<taille_soustraction; i++)
        {
            printf("%1d %1d",A.Digits[i], B.Digits[i]);
            if (A.Digits[i] < B.Digits[i])
            {
                printf("%1d superieur a %1d on ajoute base", B.Digits[i], A.Digits[i]);
                resultat_soustraction.Digits[i] = (A.Digits[i] + Base) - B.Digits[i];
                printf(" resultat : %1d\n", resultat_soustraction.Digits[i]);
                B.Digits[i+1]++;
            }
            else
            {
                resultat_soustraction.Digits[i] = A.Digits[i] - B.Digits[i];
                printf(" %1d inferieur ou egal a %1d resultat : %1d\n",B.Digits[i], A.Digits[i], resultat_soustraction.Digits[i]);
            }
        }
    }
    return resultat_soustraction;
}


GrandEntier Multiplication_test(GrandEntier A, GrandEntier B)
{
    GrandEntier resultat_multplication = {0};
    resultat_multplication.Positif = true;
    resultat_multplication.Taille = TailleMax;
    
    GrandEntier intermediaire_multplication = {0};
    intermediaire_multplication.Positif = true;
    intermediaire_multplication.Taille = TailleMax;

    for (int i=0; i<TailleMax; i++)
    {
        printf("i = %1d\n", i);
        for (int j=0; j<TailleMax; j++)
        {
            printf("j = %1d\n", j);
            intermediaire_multplication.Digits[i+j] = A.Digits[i] * B.Digits[j];
            printf("Int[%d] = A[i] * B[j] = %d\n", i+j, intermediaire_multplication.Digits[i+j]);
        }
        printf("intermediaire : \n");
        afficher_grand_entier(&intermediaire_multplication);
        resultat_multplication = Somme(resultat_multplication,intermediaire_multplication);

        for (int k=0; k<TailleMax; k++)
        {
            intermediaire_multplication.Digits[k] = 0;
        }
        afficher_grand_entier(&intermediaire_multplication);
        printf("final : \n");
        afficher_grand_entier(&resultat_multplication);
    }
    return resultat_multplication;
}
/*
GrandEntier Karatsuba(GrandEntier A, GrandEntier B)
{
    GrandEntier resultat_Karatsuba = {0};
    resultat_Karatsuba.Positif = true;

}
*/


/*
GrandEntier Modulo(GrandEntier A, GrandEntier B)
{
    GrandEntier resultat_modulo = {0};
    resultat_modulo.Positif = true;

    if (A.Positif == true && B.Positif == true)
    {
        int 
        if (resultat_egal.Positif == true || resultat_inferieur.Positif == false)
        {
            resultat_modulo.Digits[0] = 0;
        }

        for (int i=0; i<TailleMax; i++)
        {
            

        }


    }


    return resultat_modulo;
}
*/

int main()
{

    GrandEntier A = {0};
    A.Taille = TailleMax;
    A.Positif = true;
    for (int i=0; i<A.Taille; i++)
    {
        A.Digits[i] = rand()%10;
    }
    printf("Grand Entier A : ");
    afficher_grand_entier(&A);

    GrandEntier B = {0};
    B.Taille = TailleMax;
    B.Positif = true;
    for (int j=0; j<B.Taille; j++)
    {
        B.Digits[j] = rand()%10;
    }
    printf("Grand Entier B : ");
    afficher_grand_entier(&B);


    /*
    GrandEntier Som = Somme(A,B);
    printf("Somme : ");
    afficher_grand_entier(&Som);
    
    GrandEntier Sou = Soustraction(A,B);
    printf("Soustraction : ");
    afficher_grand_entier(&Sou);
    */
    GrandEntier Multi = Multiplication_test(A,B);
    printf("Multiplication : ");
    afficher_grand_entier(&Multi);

    return 0;
}

