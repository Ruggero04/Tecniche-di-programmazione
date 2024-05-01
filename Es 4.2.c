#include <stdio.h>
#define MAXN 30

void ruota(int [], int, int, int); 
void stampavettore(int [], int);

int main()
{
    int V[MAXN];    // Vettore di massimo 30 interi.
    int P;         // Variabile delle posizioni.
    int dir;      // Direzione di spostamento. 
    int N;       // Variabile del numero di interi da considerare.
    int fine=0; // Variabile logica per la scelta della direzione.
    do
    {
        printf("\nInserire il valore di lunghezza N del vettore (Max 30): ");
        scanf("%d", &N);
        if (N>MAXN)
        {
            printf("\nValore di N:%d fuori intervallo", N);
            continue;
        }
        printf("Inserire il valore P<N dello spostamento (P=0 per concludere): ");
        scanf("%d", &P);
        if (P>=N)
        {
            printf("\nValore di P:%d fuori intervallo", P);
            continue;
        }
        else if (P<=0)
        {
            fine=1;
        }
        printf("Inserire sinistra (+1) o destra (-1): ");
        scanf("%d", &dir);
        if (dir!=1 && dir!=-1)
        {
            printf("\nValore di dir:%d non acettabile", dir);
            continue;
        }
        if (!fine)
        {
            printf("Inserire i valori del vettore: ");
            for (int count=0; count<N; count++)
            {
                scanf("%d", &V[count]);
            }
            ruota(V, N, P, dir);
            stampavettore(V, N);
        }
    } while (!fine);
    printf("\nProgramma Terminato");
    return 0;
}
void ruota(int V[MAXN], int N, int P, int dir) 
{
    int tmp; // variabile temporanea per lo scambio di valori.

    if (dir == 1) 
    { 
        for (int i=0; i<P; i++) // Sposto tutti gli elementi del vettore a sinistra per P volte
        {
            tmp = V[0];
            for (int j=0; j<N-1; j++)
            {
                V[j] = V[j+1];
            }
            V[N-1] = tmp;
        }
    } 
    else 
    {  
        for(int i=0; i<P; i++) // Sposto tutti gli elementi del vettore a destra per P volte
        {
            tmp = V[N-1];
            for(int j=N-1; j>0; j--)
            {
                V[j] = V[j-1];
            }
            V[0] = tmp;
        }
    }
}
void stampavettore(int V[MAXN], int N)
{
    printf("Vettore ruotato:\n");
    for (int i=0; i<N; i++)
    {
        printf("%d ", V[i]);
    }
}