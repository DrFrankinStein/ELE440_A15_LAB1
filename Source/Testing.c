#include "Testing.h"
#include "TriFusion.h"
#include "TriRapide.h"

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

int GenererDonnees (int N,int R, int D)
{
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

    int T[N];
    for (i = 0; i < N; i++)
    {
        T[i] = (rand() % R);
    }
    
    // Placer algorithme de notre choix ici pour trier les données.
    //TRI_QUELCONQUE(T, N, R)
    
    m = M;
    for (i = 1; i <= ((M*D)/100); i++)
    {
        k = (rand() % m);
        L = Tp[k];
        Tp[k]=Tp[m];
        m = m - 1;
        iExchange = T[M-L+1];
        T[M-L+1] = T[M+L];
        T[M+L] = iExchange;
    }
    
    return 1;
}