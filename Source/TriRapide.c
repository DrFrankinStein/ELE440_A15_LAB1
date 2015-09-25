#include "TriRapide.h"

//https://fr.wikipedia.ord/Tri_rapide
int PartitionTableau(int* Tableau, int indexPremier, int indexDernier, int indexPivot)
{
    //swap T[Dernier] et T[Pivot]
    swap(&Tableau[indexDernier],&Tableau[indexPivot]);
    int j = indexPremier;
    for(int i=indexPremier;i<indexDernier;i++)
    {
        if(Tableau[i]<=Tableau[indexDernier])
        {
            swap(&Tableau[i], &Tableau[j]);
            j++;
        }
    }
    swap(&Tableau[indexDernier],&Tableau[j]);
    return j;
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

