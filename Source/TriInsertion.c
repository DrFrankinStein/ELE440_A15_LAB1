#include "TriInsertion.h"

//source : https://fr.wikipedia.org/wiki/Tri_par_insertion
void TriParInsertion(int *Donnees,int taille)
{
    int tmp, j;
    //printIntArray(Donnees,taille);
    for(int i=1; i<=taille-1; i++)
    {
        tmp=Donnees[i];
        j=i;
        while(j>0&&Donnees[j-1]>tmp)
        {
            Donnees[j]=Donnees[j-1];
            j--;
        }
        Donnees[j]=tmp;
        //printIntArray(Donnees,taille);
	}
}
	