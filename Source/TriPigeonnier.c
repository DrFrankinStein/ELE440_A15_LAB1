#include "TriPigeonnier.h"

void TriPigeonnier(int *iTableau, int DataCount, int iRang)
{
    iRang++;
    int iDenombrement[iRang];
    int i;
    int j; // itérateur du tableau à renvoyer.
    
    //Initialisation à zéro de tous les pigeonniers.
    for (i = 0; i < iRang; i++)
    {
        iDenombrement[i] = 0;
    }
    
    // Placer chaque valeurs dans leur pigeonnier respectif.
    for (i = 0; i < DataCount; i++)
    {
        iDenombrement[iTableau[i]]++;
    }
    
    j = 0; // initialiser l'indice du tableau trié à retourner.
    
    // remplacer le vieux tableau non trié avec les valeurs triées du pigeonnier.
    for (i = 0; i < iRang; i++)
    {
        while (iDenombrement[i] != 0)
        {
            iTableau[j] = i;
            j++;
            iDenombrement[i] = iDenombrement[i] - 1;
        }
    }
}