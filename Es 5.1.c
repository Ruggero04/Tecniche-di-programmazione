#include <stdio.h>
#define MAX 20

void conteggioTabella(int [][MAX], int, int);
int firstTeam(int [], int);

int main()
{
    FILE *fin;
    int tabella[MAX][MAX];
    int n, m;
    
    if ((fin=fopen("../inputEs5_1.txt", "r"))==NULL)
    {
        printf("Errore di apertura file!");
    }
    else
    {
        fscanf(fin, "%d%d", &n, &m);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                fscanf(fin, "%d", &tabella[i][j]);
            }
        }
        conteggioTabella(tabella, n, m);
    }
    return 0;
}
void conteggioTabella(int tabella[MAX][MAX], int n, int m)
{
    int gamecount[MAX]={0}; // Vettore per il conteggio delle partite
    int index; // Indice per il calcolo della capolista

    for (int j=0; j<m; j++)
    {
        for (int i=0; i<n; i++)
        {
            gamecount[i]+=tabella[i][j];
        }
        index=firstTeam(gamecount, n)+1;
        printf("La capolista al %d° giorno è la numero: %d\n", j+1, index);
    }
}
int firstTeam(int gamecount[MAX], int n)
{
    int max=0; // Variabile per il calcolo del punteggio massimo
    int maxInd; // Variabile per il calcolo dell'indice della prima

    for (int i=0; i<n; i++)
    {
        if (gamecount[i]>max)
        {
            max=gamecount[i];
            maxInd=i;
        }
    }
    return maxInd;
}