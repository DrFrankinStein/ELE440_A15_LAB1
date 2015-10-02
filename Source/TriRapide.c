#include <stdint.h>

#include "TriRapide.h"

//https://fr.wikipedia.ord/Tri_rapide
int PartitionTableau(int* Tableau, int indexPremier, int indexDernier, int indexPivot, Barometre *barometre)
{
    //swap T[Dernier] et T[Pivot]
    barometre->instructions++;
    barometre->memory+=4*sizeof(int)+sizeof(int*);
    swap(&Tableau[indexDernier],&Tableau[indexPivot]);
    int j = indexPremier;
    for(int i=indexPremier;i<indexDernier;i++)
    {
        barometre->instructions++;
        if(Tableau[i]<=Tableau[indexDernier])
        {
            barometre->instructions++;
            swap(&Tableau[i], &Tableau[j]);
            j++;
        }
    }
    swap(&Tableau[indexDernier],&Tableau[j]);
    return j;
}

Barometre TriRapide(int* Donnees, int indexPremier, int indexDernier)
{
    Barometre barometre;
    barometre.instructions=1;    
    barometre.memory = 2*sizeof(int)+sizeof(int*);
    
    if(indexPremier<indexDernier)
    {
        Barometre tmp1,tmp2;
        int pivot;
        
        barometre.instructions++;
        barometre.memory+=sizeof(int);
        tmp1=barometre;
        tmp2.instructions=0;
        tmp2.memory=0;
        pivot= randInt(indexPremier, indexDernier);
        pivot= PartitionTableau(Donnees,indexPremier, indexDernier, pivot, &tmp2);
        barometre.instructions+=tmp2.instructions;
        barometre.memory = barometre.memory>tmp2.memory ? barometre.memory:tmp1.memory+tmp2.memory ;
        
        tmp2=TriRapide(Donnees, indexPremier, pivot-1);
        barometre.instructions+=tmp2.instructions;
        barometre.memory = barometre.memory>tmp2.memory ? barometre.memory:tmp1.memory+tmp2.memory ;
        
        tmp2=TriRapide(Donnees, pivot+1,indexDernier);
        barometre.instructions+=tmp2.instructions;
        barometre.memory = barometre.memory>tmp2.memory ? barometre.memory:tmp1.memory+tmp2.memory ;
    }
    return barometre;
}

