#include "TriFusion.h"

//LIVRE p. 27+30
unsigned long long Fusion(int *Donnees, int indexPremier, int indexDernier, int indexMilieu)
{
    unsigned long long barometre=1;
    int i,j,k;
    int n1= indexMilieu-indexPremier+1;
    int n2= indexDernier-indexMilieu;
    
    int L[n1];
    int R[n2];
    
    for(i=0; i<=n1-1;i++)
    {    
        L[i]=Donnees[indexPremier+i];
        barometre++;
    }
    for(j=0; j<=n2-1;j++)
    {
        R[j]=Donnees[indexMilieu + 1 +j];
        barometre++;
    }
    
    i=0;
    j=0;
    for(k=indexPremier;k<=indexDernier;k++)
    {
        barometre++;
        if(L[i]<=R[j])
        {
            if(i<n1)
            {
                Donnees[k]=L[i];
                i++; 
            }
            else
            {
                Donnees[k]=R[j];
                j++;
            }
            barometre++;
        }
        else
        {
            if(j<n2)
            {
                Donnees[k]=R[j];
                j++; 
            }
            else
            {
                Donnees[k]=L[i];
                i++;
            }
            barometre++;
        }    
    }
    return barometre;
}

unsigned long long TriParFusion(int *Donnees, int indexPremier, int indexDernier)
{
    unsigned long long barometre=1;
    if(indexPremier<indexDernier)
    {
       barometre++;
       int indexMilieu=(indexPremier+indexDernier)/2;
       barometre+=TriParFusion(Donnees,indexPremier, indexMilieu);
       barometre+=TriParFusion(Donnees,indexMilieu+1, indexDernier);   
       barometre+=Fusion(Donnees,indexPremier,indexDernier,indexMilieu);
    }
    return barometre;
}