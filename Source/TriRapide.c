#include "TriRapide.h"

//https://fr.wikipedia.ord/Tri_rapide
int PartitionTableau(int* Tableau, int indexPremier, int indexDernier, int indexPivot, unsigned long long *barometre)
{
    //swap T[Dernier] et T[Pivot]
    *barometre++;
    swap(&Tableau[indexDernier],&Tableau[indexPivot]);
    int j = indexPremier;
    for(int i=indexPremier;i<indexDernier;i++)
    {
        *barometre++;
        if(Tableau[i]<=Tableau[indexDernier])
        {
            *barometre++;
            swap(&Tableau[i], &Tableau[j]);
            j++;
        }
    }
    swap(&Tableau[indexDernier],&Tableau[j]);
    return j;
}

unsigned long long TriRapide(int* Donnees, int indexPremier, int indexDernier)
{
    unsigned long long barometre=1;
    int pivot;
    if(indexPremier<indexDernier)
    {
        barometre++;
        pivot= randInt(indexPremier, indexDernier);
        pivot= PartitionTableau(Donnees,indexPremier, indexDernier, pivot, &barometre);
        barometre+=TriRapide(Donnees, indexPremier, pivot-1);
        barometre+=TriRapide(Donnees, pivot+1,indexDernier);
    }
    return barometre;
}

