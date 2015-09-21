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
    int T[16] = {1, 20, 40, 31, 65, 73, 28, 49, 23, 65, 47, 68, 65, 92, 12, 8};
    
    //Initialisation des variables
    
    //Initialisation de la matrice N

    for(i = 0; i < NSIZE; i++)
    {
        N[i] = NFACTOR * K[i];
    }
    
    
    TriParTas(T, 16);
    
    for (i = 0; i < 16; i++)
    {
        printf("%i\n",T[i]);
    }
    
    
    /*
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
                    T1[] = GenererDonnees(n, r, d);
                    TriParInsertion(T1, n, r);
                    TriPigeonnier(T1, n, r);
                    TriRapide(T1, n, r);
                    TriParFusion(T1, n, r);
                    TriParTas(T1, n, r);
                    TriParBase(T1, n, r);
                }
            }
        }
    }
    */
    
    return (EXIT_SUCCESS);
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




