/* 
 * File:   Main.c
 * Author: PPoucH
 *
 * Created on 11 septembre 2015, 09:53
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "testing.h"

//PROTOTYPES
void TriParInsertion(int *Donnees,int taille);
void TriRapide(int* Donnees, int indexPremier, int indexDernier);

/*
 * 
 */
int main2(int argc, char** argv)
{
    //Déclaration des variables
    
    //int iSucces;
    int n;
    int d;
    int r;
    int N[NSIZE];
    
    //Initialisation des variables
    
    //Initialisation de la matrice N
    for(int i = 0; i < NSIZE; i++)
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
    
    for (int i = 1; i <= 10; i++)
    {
        n = N[i];
        int T1[n];
        for(int j = 1; j <= 4; j++)
        {
            r = R[j];
            for(int k = 1; k <= 5; k++)
            {
                d = D[k];
                for (int m = 1; m <= 10; m++)
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

void printIntArray(int* T, int n)
{
    for(int i =0;i<n;i++)
    {
        printf("%i ", T[i]);
    }
    printf("\n\r");
    
}

int main(int argc, char** argv)
{
    char z;
    int T[10]={10,9,8,7,6,5,4,3,2,1};
    printIntArray(T,10);
    TriRapide(T,0,9);
    printIntArray(T,10);
    return (EXIT_SUCCESS);
}

int GenererDonnees (int n,int r,int d)
{
    
}

//source : https://fr.wikipedia.org/wiki/Tri_par_insertion
void TriParInsertion(int *Donnees,int taille)
{
    int tmp, j;
    //printIntArray(Donnees,taille);
    for(int i=1; i<=taille-1; i++)
    {
        tmp=Donnees[i];
        j=i;
        while(j>0&&Donnees[j-1]>tmp)
        {
            Donnees[j]=Donnees[j-1];
            j--;
        }
        Donnees[j]=tmp;
        //printIntArray(Donnees,taille);
    }
}

void TriPigeonnier(int iDonnees,int n,int r)
{
    
}
            
//https://fr.wikipedia.ord/Tri_rapide
void swap(int *a, int *b)
{
    int tmp = *a;
    *a=*b;
    *b=tmp;
}
int randInt(int min, int max)
{
    srand(time(NULL));
    int range = max-min;
    return (rand()%range)+min; 
}
int PartitionTableau(int* Tableau, int indexPremier, int indexDernier, int indexPivot)
{
    //swap T[Dernier] et T[Pivot]
    swap(&Tableau[indexDernier],&Tableau[indexPivot]);
    int j = indexPremier;
    for(int i=indexPremier;i<indexDernier-1;i++)
    {
        if(Tableau[i]<=Tableau[indexDernier])
        {
            swap(&Tableau[i], &Tableau[j]);
            j++;
        }
    }
    swap(&Tableau[indexDernier],&Tableau[j]);
    return j+1;
}
void TriRapide(int* Donnees, int indexPremier, int indexDernier)
{
    int pivot;
    if(indexPremier<indexDernier)
    {
        pivot= randInt(indexPremier, indexDernier);
        pivot= PartitionTableau(Donnees,indexPremier, indexDernier, pivot);
        TriRapide(Donnees, indexPremier, pivot-1);
        TriRapide(Donnees, pivot+1,indexDernier);
    }
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