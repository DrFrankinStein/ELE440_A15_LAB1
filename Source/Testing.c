#include <stdio.h>     
#include <stdlib.h>
#include <time.h>

#include "Testing.h"
#include "TriFusion.h"
#include "TriRapide.h"
#include "TriTas.h"
#include "TriPigeonnier.h"

const int K[NSIZE] = {10,20,30,40,50,60,70,80,90,100};
const int R[RSIZE] = {10^2,10^4,10^6,10^8};
const int D[DSIZE] = {0,25,50,75,100};

void printIntArray(int* T, int n)
{
    for(int i =0;i<n;i++)
    {
        printf("%i ", T[i]);
    }
    printf("\n\r");
    
}

int TestJulien(void)
{
    int T[20]={99,2,44,10,9,8,7,6,5,4,3,2,1,20,15,17,55,70,100,-5};
    printIntArray(T,20);
    TriRapide(T,0,19);
    printIntArray(T,20);
    
    //printf("%i \n\r", Infinite());
}

void TestAlexandre(void)
{
    int N = 50;
    int R = 100;
    int D = 75;
    /*
    printf("entrer N : ");
    scanf("%d", &N);
    printf("\nentrer R : ");
    scanf("%d", &R);
    printf("\nentrer D : ");
    scanf("%d", &D);
    */
    int T[N];
    
    GenererDonnees(T, N, R, D);
    
    printf("\nDesordre\n");
    printIntArray(T, N);
    
    TriPigeonnier(T, N, R);
    
    printf("\npigeonnier\n");
    printIntArray(T, N);
}

void GenererDonnees (int *T, int N,int R, int D)
{ 
    srand(time(NULL));
    int i;
    int m;
    int k;
    int L;
    int iExchange;
    int M = N/2;
    int Tp[M];
    for (i = 1; i <= M; i++)
    {
        Tp[i-1] = i;
    }

    for (i = 0; i < N; i++)
    {
        
        T[i] = (rand() % R);
    }
    
    printf("\nrandom\n");
    printIntArray(T, N);
    // Placer algorithme de notre choix ici pour trier les données.
    TriParTas(T, N);
    
    printf("\ntrie\n");
    printIntArray(T, N);
    
    m = M;
    for (i = 1; i <= ((M*D)/100); i++)
    {
        k = (rand() % m);
        L = Tp[k];
        Tp[k]=Tp[m-1];
        m = m - 1;
        iExchange = T[M-L];
        T[M-L] = T[M+L-1];
        T[M+L-1] = iExchange;
    }
}

int randInt(int min, int max)
{
    srand(time(NULL));
    int range = max-min;
    return (rand()%range)+min; 
}