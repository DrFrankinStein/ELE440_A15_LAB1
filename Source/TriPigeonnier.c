#include "TriPigeonnier.h"

Barometre TriPigeonnier(int *iTableau, int DataCount, int iRang)
{
    Barometre barometre;
    barometre.instructions=1;
    
    iRang++;
    int iDenombrement[iRang];
    int i;
    int j; // itérateur du tableau à renvoyer.
    
    barometre.memory = (2+iRang+2+1)*sizeof(int)+(2)*sizeof(int*);
    
    //initialisation à zéro de tous les pigeonniers.
    for (i = 0; i < iRang; i++)
    {
        barometre.instructions++;
        iDenombrement[i] = 0;
    }
    
    // Placer chaque valeurs dans leur pigeonnier respectif.
    for (i = 0; i < DataCount; i++)
    {
        barometre.instructions++;
        iDenombrement[iTableau[i]]++;
    }
    
    j = 0; // initialiser l'indice du tableau trié à retourner.
    
    // remplacer le vieux tableau non trié avec les valeurs triées du pigeonnier.
    for (i = 0; i < iRang; i++)
    {
        barometre.instructions++;
        while (iDenombrement[i] != 0)
        {
            barometre.instructions++;
            iTableau[j] = i;
            j++;
            iDenombrement[i] = iDenombrement[i] - 1;
        }
    }
    
    return barometre;
}