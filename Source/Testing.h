/* 
 * File:   testing.h
 * Author: PPoucH
 *
 * Created on 11 septembre 2015, 10:57
 */

#ifndef TESTING_H
#define	TESTING_H

// Définition des constantes
    
#define DESORDRE_MIN 0
#define DESORDRE_MAX 100
#define NFACTOR 1000
#define NSIZE 10
#define RSIZE 4
#define DSIZE 5

extern const int K[NSIZE];
extern const int R[RSIZE];
extern const int D[DSIZE];
// Définition des fonctions

void GenererDonnees (int *T, int N,int R,int D);
void TestAlexandre(void);
int TestJulien(void);

#endif	/* TESTING_H */

