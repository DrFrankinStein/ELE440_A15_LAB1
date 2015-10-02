#include "TriPigeonnier.h"

Barometre TriPigeonnier(int *iTableau, int DataCount, int iRang)
{
    Barometre barometre;
    barometre.instructions=1;
    
    iRang++;
    int iDenombrement[iRang];
    int i;
    int j;
    
    barometre.memory = (2+iRang+2+1)*sizeof(int)+(2)*sizeof(int*);
    
    //initialisation à zéro de tous les pigeonniers.
    for (i = 0; i < iRang; i++)
    {
        barometre.instructions++;
        iDenombrement[i] = 0;
    }
    
    // dénombrement des différentes valeurs.
    for (i = 0; i < DataCount; i++)
    {
        barometre.instructions++;
        iDenombrement[iTableau[i]]++;
    }
    
    // remplacer avec les valeurs triées.
    j = 0; // indice du tableau trié.
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