/* 
 * File:   testing.h
 * Author: PPoucH
 *
 * Created on 11 septembre 2015, 10:57
 */

#ifndef TESTING_H
#define	TESTING_H

// Definition des constantes
    
#define DESORDRE_MIN 0
#define DESORDRE_MAX 100
#define NFACTOR 1000 //100
#define NSIZE 10
#define RSIZE 4
#define DSIZE 5

#include <stdio.h>
#include <stdlib.h>

#include "CommonFunc.h"
#include "TriBase.h"
#include "TriFusion.h"
#include "TriInsertion.h"
#include "TriPigeonnier.h"
#include "TriRapide.h"
#include "TriTas.h"
#include "CommonFunc.h"

extern const int K[NSIZE];
extern const int R[RSIZE];
extern const int D[DSIZE];
// Definition des fonctions

void GenererDonnees (int *T, int N,int R,int D);
void TestAlexandre(void);
int TestJulien(void);
void writeDataFileInit(char * nomTri);
void writeDataFile(char * nomTri, int nbreDonnes, int rangeDonnees, int tauxDispersion,unsigned long long nbreInstructions,unsigned long long memoireMax, int tempsTraitement);

#endif	/* TESTING_H */

