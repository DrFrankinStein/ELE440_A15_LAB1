#include "Testing.h"

const int K[NSIZE] = {10,20,30,40,50,60,70,80,90,100};
const int R[RSIZE] = {100,10000,1000000,100000000};
const int D[DSIZE] = {0,25,50,75,100};

int TestJulien(void)
{
    int nn=1000;
    int rr=10000;
    int dd=50;
    
    int T[nn];//={99,2,44,10,9,8,0,6,5,4,-3,2,1,20,15,-17,55,70,100,-5};
    /*
    srand(time(NULL));
    printf("\n\rTRI PAR BASE \n\n\r");
    GenererDonnees(T,nn,rr,dd);
    printIntArray(T,nn);
    TriParBase(T,nn,4);
    printIntArray(T,nn);
    
    printf("\n\rTRI PAR FUSION \n\n\r");
    GenererDonnees(T,nn,rr,dd);
    printIntArray(T,nn);
    TriParFusion(T,0,nn-1);
    printIntArray(T,nn);
    
    printf("\n\rTRI PAR INSERTION \n\n\r");
    GenererDonnees(T,nn,rr,dd);
    printIntArray(T,nn);
    TriParInsertion(T,nn);
    printIntArray(T,nn);
    
    printf("\n\rTRI PAR PIGEONNIER \n\n\r");
    GenererDonnees(T,nn,rr,dd);
    printIntArray(T,nn);
    TriPigeonnier(T,nn,rr);
    printIntArray(T,nn);
    
    printf("\n\rTRI RAPIDE \n\n\r");
    GenererDonnees(T,nn,rr,dd);
    printIntArray(T,nn);
    TriRapide(T,0,nn-1);
    printIntArray(T,nn);
    */
    printf("\n\rTRI PAR TAS \n\n\r");
    GenererDonnees(T,nn,rr,dd);
    printIntArray(T,nn);
    TriParTas(T,nn);
    printIntArray(T,nn);
    //TriParFusion(T,0,19);
    //TriParInsertion(T,20);
    //TriPigeonnier(T,20,100); //NON FONCTIONNEL AVEC NEGATIF
    //TriRapide(T,0,19);
    //TriParTas(T,20);
    
    //printIntArray(T,20);
    
    printf("\n\r");
    //writeDataFileInit("Test");
    //writeDataFile("Test", 50, 25, 50, 40);
}

void TestAlexandre(void)
{
    int N = 50;
    int R = 100;
    int D = 75;
    /*
    printf("entrer N : ");
    scanf("%d", &N);
    printf("\nentrer R : ");
    scanf("%d", &R);
    printf("\nentrer D : ");
    scanf("%d", &D);
    */
    int T[N];
    
    GenererDonnees(T, N, R, D);
    
    printf("\nDesordre\n");
    printIntArray(T, N);
    
    TriPigeonnier(T, N, R);
    
    printf("\npigeonnier\n");
    printIntArray(T, N);
}

void GenererDonnees (int *T, int N,int R, int D)
{ 
    srand(time(NULL));
    int i;
    int m;
    int k;
    int L;
    int iExchange;
    int M = N/2;
    int Tp[M];
    for (i = 1; i <= M; i++)
    {
        Tp[i-1] = i;
    }

    for (i = 0; i < N; i++)
    {
        
        T[i] = (rand() % (R+1));
    }
    
    //printf("\nrandom\n");
    //printIntArray(T, N);
    // Placer algorithme de notre choix ici pour trier les données.
    //TriParTas(T, N);
    TriRapide(T,0,N-1);
    
    //printf("\ntrie\n");
    //printIntArray(T, N);
    
    m = M;
    for (i = 1; i <= ((M*D)/100); i++)
    {
        k = (rand() % m);
        L = Tp[k];
        Tp[k]=Tp[m-1];
        m = m - 1;
        iExchange = T[M-L];
        T[M-L] = T[M+L-1];
        T[M+L-1] = iExchange;
    }
}

void writeDataFileInit(char * nomTri)
{
    FILE * file;
    char fileName[100];
    
    sprintf(fileName,"%s.txt",nomTri);
    
    file = fopen(fileName,"w");
    if(file)
    {
        fprintf(file,"%s\n\n",nomTri);
        fprintf(file,"Nombre de données, Intervalle des données, Taux de dispersion, nombre d'instructions, temps de traitement(us);\n");
    }
    fclose(file);
}

void writeDataFile(char * nomTri, int nbreDonnes, int rangeDonnees, int tauxDispersion,long long nbreInstructions, int tempsTraitement)//nom,Nombre de donnees, Range des donnees,taux de Dispersion, temps  
{
    FILE * file;
    char fileName[100];
    
    sprintf(fileName,"%s.txt",nomTri);
    
    file = fopen(fileName,"a");
    if(file)
    {
        //fprintf(file,"%s\n\n\r",nomTri);
        fprintf(file,"%i, %i, %i,%llu, %i;\n",nbreDonnes,rangeDonnees,tauxDispersion,nbreInstructions,tempsTraitement);
    }
    fclose(file);
}
