int GenererDonnees (int N,int R, int D)
{
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

    int T[N];
    for (i = 0; i < N; i++)
    {
        T[i] = (rand() % R);
    }
    
    // Placer algorithme de notre choix ici pour trier les données.
    //TRI_QUELCONQUE(T, N, R)
    
    m = M;
    for (i = 1; i <= ((M*D)/100); i++)
    {
        k = (rand() % m);
        L = Tp[k];
        Tp[k]=Tp[m];
        m = m - 1;
        iExchange = T[M-L+1];
        T[M-L+1] = T[M+L];
        T[M+L] = iExchange;
    }
    
    return 1;
}
