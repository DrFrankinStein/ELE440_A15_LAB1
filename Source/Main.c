/* 
 * File:   Testing.c
 * Author: PPoucH
 *
 * Created on 11 septembre 2015, 09:53
 */

#include <stdio.h>
#include <stdlib.h>
#include "testing.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    
    
    //Déclaration des variables
    
    int iSucces;
    int i;
    int j;
    int k;
    int n;
    int d;
    int r;
    int m;
    int N[NSIZE];
    
    //Initialisation des variables
    
    //Initialisation de la matrice N
    for(i = 0; i < NSIZE; i++)
    {
        N[i] = NFACTOR * K[i];
    }
    
    /* Entrez le nombre de nombres entier à trier.
    
    do
    {
        printf("Entrez la valeur de N (Le nombre d'entiers a trier) [ENTIER POSITIF]: ");
        iSucces = scanf("%d", &N);
    }
    while(iSucces < 0 || N < 0);
    
    // Entrer le plus grand nombre entier possible dans la liste.
    
    do
    {
        printf("Entrez la valeur de R (Le plus grand nombre entier possible dans la liste) [ENTIER POSITIF]: ");
        iSucces = scanf("%d", &R);
    }
    while(iSucces < 0 || R < 0);
    
    // Entrer le degré de désordre dans la liste d'entiers
    
    do
    {
        printf("Entrez la valeur de D (pourcentage de désordre dans la liste) [%i à %i]: ",DESORDRE_MIN, DESORDRE_MAX);
        iSucces = scanf("%d", &D);
    }
    while(iSucces < 0 || D < DESORDRE_MIN || D > DESORDRE_MAX);
     */
    printf("%i",K[1]);
    
    for (i = 1; i <= 10; i++)
    {
        n = N[i];
        int T1[n];
        for(j = 1; j <= 4; j++)
        {
            r = R[j];
            for(k = 1; k <= 5; k++)
            {
                d = D[k];
                for (m = 1; m <= 10; m++)
                {
                    //T1[] = GenererDonnees(n, r, d);
                    //TriParInsertion(T1, n, r);
                    //TriPigeonnier(T1, n, r);
                    //TriRapide(T1, n, r);
                    //TriParFusion(T1, n, r);
                    //TriParTas(T1, n, r);
                    //TriParBase(T1, n, r);
                }
            }
        }
    }
    return (EXIT_SUCCESS);
}

int GenererDonnees (int n,int r,int d)
{
    
}

void TriParInsertion(int iDonnees,int n, int r)
{
    
}

void TriPigeonnier(int iDonnees,int n,int r)
{
    
}
                    
void TriRapide(int iDonnees, int n, int r)
{
    
}
void TriParFusion(int iDonnees, int n, int r)
{
    
}
void TriParTas(int iDonnees, int n, int r)
{
    
}
void TriParBase(int iDonnees, int n, int r)
{
    
}