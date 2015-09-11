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
const int K[NSIZE] = {10,20,30,40,50,60,70,80,90,100};
const int R[RSIZE] = {10^2,10^4,10^6,10^8};
const int D[DSIZE] = {0,25,50,75,100};

// Définition des fonctions

int GenererDonnees (int n,int r,int d);
#endif	/* TESTING_H */

