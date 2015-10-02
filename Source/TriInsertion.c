#include "TriInsertion.h"

//source : https://fr.wikipedia.org/wiki/Tri_par_insertion
Barometre TriParInsertion(int *Donnees,int taille)
{
    int tmp, j;
    Barometre barometre;
    barometre.instructions=1;
    barometre.memory = 4*sizeof(int)+sizeof(int*);
    for(int i=1; i<=taille-1; i++)
    {
        barometre.instructions++;
        tmp=Donnees[i];
        j=i;
        while(j>0&&Donnees[j-1]>tmp)
        {
            barometre.instructions++;
            Donnees[j]=Donnees[j-1];
            j--;
        }
        Donnees[j]=tmp;
    }
    return barometre;
}
	