#include "TriFusion.h"

//LIVRE p. 27+30
void Fusion(int *Donnees, int indexPremier, int indexDernier, int indexMilieu)
{
    int i,j,k;
    int n1= indexMilieu-indexPremier+1;
    int n2= indexDernier-indexMilieu;
    
    int L[n1];
    int R[n2];
    
    for(i=0; i<=n1-1;i++)
        L[i]=Donnees[indexPremier+i];

    for(j=0; j<=n2-1;j++)
        R[j]=Donnees[indexMilieu + 1 +j];
    
    i=0;
    j=0;
    for(k=indexPremier;k<=indexDernier;k++)
    {
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
        }    
    }
}

void TriParFusion(int *Donnees, int indexPremier, int indexDernier)
{
    if(indexPremier<indexDernier)
    {
       int indexMilieu=(indexPremier+indexDernier)/2;
       TriParFusion(Donnees,indexPremier, indexMilieu);
       TriParFusion(Donnees,indexMilieu+1, indexDernier);   
       Fusion(Donnees,indexPremier,indexDernier,indexMilieu);
    }
}