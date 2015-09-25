#include "TriBase.h"

//https://www.cs.usfca.edu/~galles/visualization/RadixSort.html
void TriParBase(int *Donnees,int taille, int nbreChiffre)
{
    
    int positifChiffre[10], negatifChiffre[10],chiffre, base=1;
    int tmpDonnees[taille];

    for(int i=0; i<nbreChiffre;i++)
    {
        for(int j =0; j<10;j++)//Initialisation des bases
        {
            positifChiffre[j]=0; 
            negatifChiffre[j]=0;
        }
        
        for(int j=0; j<taille;j++)//Comptage des bases
        {
            chiffre = (Donnees[j]/base)%10;
            if(Donnees[j]>=0)
            {
                positifChiffre[chiffre]++;
            }
            else
            {
                negatifChiffre[-chiffre]++;
            }
        }
        
        for(int k=9;k>0;k--)//comptage des index negatifs
        {
            negatifChiffre[k-1]+=negatifChiffre[k];
        }
        
        positifChiffre[0]= positifChiffre[0]+negatifChiffre[0]; //index des 0 positifs
        
        for(int k=1; k<10; k++) //comptage des index positifs
        {
            positifChiffre[k]+=positifChiffre[k-1];
        }
        
        for(int j=taille-1; j>=0;j--)
        {
            chiffre = (Donnees[j]/base)%10;
            if(Donnees[j]>=0)
            {
                positifChiffre[chiffre]--;
                tmpDonnees[positifChiffre[chiffre]]=Donnees[j];
            }
            else
            {
                negatifChiffre[-chiffre]--;
                tmpDonnees[negatifChiffre[-chiffre]]=Donnees[j];
            }
        }
        
        base*=10;
        for(int j =0; j<taille;j++)
        {
            swap(&Donnees[j],&tmpDonnees[j]);
        }
    }
}