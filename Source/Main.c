/* 
 * File:   Testing.c
 * Author: PPoucH
 *
 * Created on 11 septembre 2015, 09:53
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Testing.h"
#include <time.h>
#include <windows.h>
#include "CommonFunc.h"
/*
 * 
 */
//https://msdn.microsoft.com/en-us/library/windows/desktop/ms644905(v=vs.85).aspx
//http://www.songho.ca/misc/timer/timer.html
int main(int argc, char** argv)
{

    //Declaration des variables
   
    int i; //iterateur pour nombre de donnees
    int j; //iterateur pour taille des nombres
    int k; //iterateur pour degre de desordre
    int n;
    int d;
    int r;
    int m;
    int N[NSIZE];
    
    
    LARGE_INTEGER start, end, average, frequency;
    Barometre barometre, avrgBarometre;
    char nomTest[50] = "TriPigeonnier";
    
    //Initialisation des variables
    
    QueryPerformanceFrequency(&frequency);
    
    //Initialisation de la matrice N

    for(i = 0; i < NSIZE; i++)
    {
        N[i] = NFACTOR * K[i];
    }
    
    writeDataFileInit(nomTest);
    int T1[N[NSIZE-1]];
    
    for (i = 1; i <= NSIZE; i++)
    {
        n = N[i-1];
        //int T1[n];
        printf("Nombre de donnees = %i (%i/%i)\n\r",n,i,NSIZE);
        for(j = 1; j <= RSIZE; j++)
        {
            r = R[j-1];
            printf("  Intervalle de donnees = %i (%i/%i)\n\r    Taux de desordre=\n\r",r,j,RSIZE);
            for(k = 1; k <= DSIZE; k++)
            {
                d = D[k-1];
                printf("      (%i/%i) [%i%%] : ",k,DSIZE,d);
                average.QuadPart = 0;
                avrgBarometre.instructions = 0;
                avrgBarometre.memory = 0;
                for (m = 1; m <= 10; m++)
                {
                    GenererDonnees(T1, n,r,d);
                    QueryPerformanceCounter(&start);
                    
                    //barometre=TriParBase(T1,n,2*j+1);
                    //barometre=TriParFusion(T1,0,n-1);
                    //barometre=TriParInsertion(T1,n);
                    //barometre=TriRapide(T1,0,n-1);
                    //barometre = TriPigeonnier(T1,n,r);
                    barometre=TriParTas(T1,n);
                                        
                    QueryPerformanceCounter(&end);
                    writeDataFile(nomTest, n, r, d,barometre.instructions,barometre.memory, (int)((1000000*(end.QuadPart-start.QuadPart))/frequency.QuadPart));
                    //writeDataFile(nomTest, n, r, d,barometre, 0);
                    
                    average.QuadPart+=end.QuadPart-start.QuadPart;
                    avrgBarometre.instructions+=barometre.instructions;
                    avrgBarometre.memory+=barometre.memory;
                    
                    //printf("%i ", (int)((1000000*(end.QuadPart-start.QuadPart))/frequency.QuadPart));
                    //printf("%llu ", barometre);
                }
                printf("~%llu instr. ~%llukB ~%i us\n\r",avrgBarometre.instructions/10,(avrgBarometre.memory)/(10*1000),(int)((average.QuadPart*1000000)/(10*frequency.QuadPart)));
                //printf("~%llu instr. ~%i us\n\r",avrgBarometre/10,0);
            }
        }
    }
    
    printf("int=%i bits long=%i bits long long=%i bits\n\r",sizeof(int)*8,sizeof(long)*8, sizeof(long long)*8);
    //TestJulien();
    //TestAlexandre();
    return (EXIT_SUCCESS);
}

