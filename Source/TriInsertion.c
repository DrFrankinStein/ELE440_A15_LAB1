#include "TriInsertion.h"

//source : https://fr.wikipedia.org/wiki/Tri_par_insertion
unsigned long long TriParInsertion(int *Donnees,int taille)
{
    int tmp, j;
    unsigned long long barometre=1;
    //printIntArray(Donnees,taille);
    for(int i=1; i<=taille-1; i++)
    {
        barometre++;
        tmp=Donnees[i];
        j=i;
        while(j>0&&Donnees[j-1]>tmp)
        {
            barometre++;
            Donnees[j]=Donnees[j-1];
            j--;
        }
        Donnees[j]=tmp;
        //printIntArray(Donnees,taille);
    }
    return barometre;
}
	