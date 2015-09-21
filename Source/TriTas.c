#include "TriTas.h"

void TriParTas(int *T, int N)
{
    int i;
    int iNoeud;
    int iExchange;
    int iCompleted = 0;
    int iNoeudTop;
    bool bBloque;
    
    for (i = 0; i < (N); i++)
    {
        bBloque = false;

        for (iNoeud = 1; iNoeud <= N - iCompleted; iNoeud++)
        {
            if ((2 * iNoeud) + 1 <= N - 1 - iCompleted) // Si la valeur de droite n'est pas bloqué
            {
                if (T[iNoeud - 1] < T[2 * iNoeud] && T[(2 * iNoeud) - 1] < T[2 * iNoeud]) // Si il faut échanger le chiffre de droite
                {
                    iExchange = T[iNoeud - 1];
                    T[iNoeud - 1] = T[2 * iNoeud];
                    T[2 * iNoeud] = iExchange;
                }
                else if (T[iNoeud - 1] < T[(2 * iNoeud) - 1]) // s'il faut échanger avec la feuille de gauche
                {
                    iExchange = T[iNoeud - 1];
                    T[iNoeud - 1] = T[(2 * iNoeud) - 1];
                    T[(2 * iNoeud) - 1] = iExchange;
                }  
            }
            else if ((2 * iNoeud) <= N - 1 - iCompleted) // Si seulement la valeur de gauche n'est pas bloqué
            {
                if (T[iNoeud - 1] < T[(2 * iNoeud) - 1]) // s'il faut échanger avec la feuille de gauche
                {
                    iExchange = T[iNoeud - 1];
                    T[iNoeud - 1] = T[(2 * iNoeud) - 1];
                    T[(2 * iNoeud) - 1] = iExchange;
                }
            }
            
            iNoeudTop = iNoeud;
            while(iNoeudTop != 1)
            {
                if (T[iNoeudTop - 1] > T[(iNoeudTop/2) - 1])
                {
                    iExchange = T[iNoeudTop - 1];
                    T[iNoeudTop - 1] = T[(iNoeudTop/2) - 1];
                    T[(iNoeudTop/2) - 1] = iExchange;
                }
                iNoeudTop = iNoeudTop/2;
            }
        }
        iExchange = T[0];
        T[0] = T[N-1-iCompleted];
        T[N-1-iCompleted] = iExchange;
        iCompleted++;
    }
}