#include "TriRapide.h"

//https://fr.wikipedia.ord/Tri_rapide
void swap(int *a, int *b)
{
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

int randInt(int min, int max)
{
    srand(time(NULL));
    int range = max-min;
    return (rand()%range)+min; 
}

int PartitionTableau(int* Tableau, int indexPremier, int indexDernier, int indexPivot)
{
    //swap T[Dernier] et T[Pivot]
    swap(&Tableau[indexDernier],&Tableau[indexPivot]);
    int j = indexPremier;
    for(int i=indexPremier;i<indexDernier-1;i++)
    {
        if(Tableau[i]<=Tableau[indexDernier])
        {
            swap(&Tableau[i], &Tableau[j]);
            j++;
        }
    }
    swap(&Tableau[indexDernier],&Tableau[j]);
    return j+1;
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

