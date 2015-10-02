#include "TriTas.h"

Barometre TriParTas(int *T, int N)
{
    Barometre barometre;
    barometre.instructions=1;
    int i;
    int iNoeud;
    int iExchange;
    int iCompleted = 0;
    int iNoeudTop;
    
    barometre.memory=(6)*sizeof(int)+(1)*sizeof(int*);
    
    // pour le nombre de données que possède le tableau,
    for (i = 0; i < (N); i++)
    {
        // Pour le nombre de noeuds restant à trier,
        barometre.instructions++;
        for (iNoeud = 1; iNoeud <= N - iCompleted; iNoeud++)
        {
            barometre.instructions++;
			// Si le dernier noeud Possède deux feuilles,
            if ((2 * iNoeud) + 1 <= N - 1 - iCompleted) // Si la valeur de droite n'est pas bloqué
            {
                barometre.instructions++;
				// S'il faut échanger la feuille de droite
                if (T[iNoeud - 1] < T[2 * iNoeud] && T[(2 * iNoeud) - 1] < T[2 * iNoeud]) // Si il faut échanger le chiffre de droite
                {
                    barometre.instructions++;
                    // Échanger la valeur de la feuille de droite avec la valeur du noeud.
					iExchange = T[iNoeud - 1];
                    T[iNoeud - 1] = T[2 * iNoeud];
                    T[2 * iNoeud] = iExchange;
                }
                // Sinon s'il faut échanger avec la feuille de gauche
                else if (T[iNoeud - 1] < T[(2 * iNoeud) - 1])
                {
                    barometre.instructions++;
                    // Échanger la valeur de la feuille de gauche avec la valeur du noeud
                    iExchange = T[iNoeud - 1];
                    T[iNoeud - 1] = T[(2 * iNoeud) - 1];
                    T[(2 * iNoeud) - 1] = iExchange;
                }  
            }
            // Sinon si le noeud ne possède qu'une feuille,
            else if ((2 * iNoeud) <= N - 1 - iCompleted)
            {
                barometre.instructions++;
				// Sinon s'il faut échanger avec la feuille de gauche
                if (T[iNoeud - 1] < T[(2 * iNoeud) - 1]) // s'il faut échanger avec la feuille de gauche
                {
                    barometre.instructions++;
					// Échanger la valeur de la feuille de gauche avec la valeur du noeud
                    iExchange = T[iNoeud - 1];
                    T[iNoeud - 1] = T[(2 * iNoeud) - 1];
                    T[(2 * iNoeud) - 1] = iExchange;
                }
            }
            
            // Redescendre l'arbre pour vérifier si toutes les valeurs en
            // dessous de la valeur de la feuille sont encore plus petit que la
            // valeur de la feuille.
            
            iNoeudTop = iNoeud;
            while(iNoeudTop != 1)
            {
                barometre.instructions++;
                if (T[iNoeudTop - 1] > T[(iNoeudTop/2) - 1])
                {
                    barometre.instructions++;
                    iExchange = T[iNoeudTop - 1];
                    T[iNoeudTop - 1] = T[(iNoeudTop/2) - 1];
                    T[(iNoeudTop/2) - 1] = iExchange;
                }
                iNoeudTop = iNoeudTop/2;
            }
        }
        iExchange = T[0];
        T[0] = T[N-1-iCompleted];
        T[N-1-iCompleted] = iExchange;
        iCompleted++;
    }
    
    return barometre;
}