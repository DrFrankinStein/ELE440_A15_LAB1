#include "TriFusion.h"

int Infinite(void)
{
    
    int inf = 1<<((sizeof(int)*8)-1);
    return ~inf;
}

void Fusion(int *Donnees, int indexPremier, int indexDernier, int indexMilieu)
{
    int n1= indexMilieu-indexPremier+1;
    int n2= indexDernier-indexMilieu;
    
    int L[n1];
    int R[n2];
    
    for(int i=0; i<=n1-1;i++)
        L[i]=Donnees[indexPremier+i];

    for(int j=0; j<=n2-1;j++);
        //R[j]=Donnees[];
}

void TriParFusion(int *Donnees, int indexPremier, int indexDernier)
{
    
}