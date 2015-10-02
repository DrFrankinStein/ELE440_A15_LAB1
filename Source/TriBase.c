#include "TriBase.h"

//https://www.cs.usfca.edu/~galles/visualization/RadixSort.html
Barometre TriParBase(int *Donnees,int taille, int nbreChiffre)
{
    Barometre barometre;
    barometre.instructions=1;
    int positifChiffre[10], negatifChiffre[10],chiffre, base=1;
    int tmpDonnees[taille];
    barometre.memory=(2+10+10+2+taille+2)*sizeof(int)+4*sizeof(int*);

    for(int i=0; i<nbreChiffre;i++)
    {
        barometre.instructions++;
        for(int j =0; j<10;j++)//Initialisation des bases
        {
            barometre.instructions++;
            positifChiffre[j]=0; 
            negatifChiffre[j]=0;
        }
        
        for(int j=0; j<taille;j++)//Comptage des bases
        {
            barometre.instructions++;
            chiffre = (Donnees[j]/base)%10;
            if(Donnees[j]>=0)
            {
                positifChiffre[chiffre]++;
            }
            else
            {
                negatifChiffre[-chiffre]++;
            }
            barometre.instructions++;
        }
        
        for(int k=9;k>0;k--)//comptage des index negatifs
        {
            barometre.instructions++;
            negatifChiffre[k-1]+=negatifChiffre[k];
        }
        
        positifChiffre[0]= positifChiffre[0]+negatifChiffre[0]; //index des 0 positifs
        
        for(int k=1; k<10; k++) //comptage des index positifs
        {
            barometre.instructions++;
            positifChiffre[k]+=positifChiffre[k-1];
        }
        
        for(int j=taille-1; j>=0;j--)
        {
            barometre.instructions++;
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
            barometre.instructions++;
        }
        
        base*=10;
        for(int j =0; j<taille;j++)
        {
            barometre.instructions++;
            swap(&Donnees[j],&tmpDonnees[j]);
        }
    }
    return barometre;
}