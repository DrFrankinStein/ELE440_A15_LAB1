#include "TriPigeonnier.h"

void TriPigeonnier(int *iTableau, int DataCount, int iRang)
{
    int iDenombrement[iRang+1];
    int i;
    int j;
    
    //initialisation à zéro de tous les pigeonniers.
    for (i = 0; i <= iRang; i++)
    {
        iDenombrement[i] = 0;
    }
    
    // dénombrement des différentes valeurs.
    for (i = 0; i < DataCount; i++)
    {
        iDenombrement[iTableau[i]]++;
    }
    
    // remplacer avec les valeurs triées.
    j = 0; // indice du tableau trié.
    for (i = 0; i <= iRang; i++)
    {
        if (iDenombrement[i] != 0)
        {
            iTableau[j] = i;
            j++;
            iDenombrement[i]--;
        }
    }
}