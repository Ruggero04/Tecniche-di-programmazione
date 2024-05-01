#include <stdio.h>
#define MAX_SIZE 20

void stampaMatrice(int [][MAX_SIZE], int, int, int);
void sottomatrice(int [][MAX_SIZE], int, int, int);
int sommaMatrice(int [][MAX_SIZE], int, int, int);

int main()
{
    FILE *fIn;
    char nome_input[MAX_SIZE + 1]; // Stringa con il nome del file in input
    int matrix[MAX_SIZE][MAX_SIZE]; // Matrice di numeri ottenuta dal file
    int nc, nr, dim;
    int fine=0; // Variabile logica per l'uscita dal do-while

    printf("Inserire il nome del file input ( Max 20 caratteri ): ");
    scanf("%s", nome_input);
    if ((fIn=fopen(nome_input, "r"))==NULL)
    {
        printf("Errore! Impossibile aprire il file");
        return 1;
    }
    else 
    {
        fscanf(fIn, "%d%d", &nr, &nc);
        for (int i=0; i<nr; i++)
        {
            for (int j=0; j<nc; j++)
            {
                fscanf(fIn, "%d ", &matrix[i][j]);
            }
        }
        printf("La matrice è:\n");
        for (int i=0; i<nr; i++)
        {
            for (int j=0; j<nc; j++)
            {
                printf("% d ", matrix[i][j]);
            }
            printf("\n");
        }
        do
        {
            printf("Inserire una dimensione compresa tra 1 ed il minimo fra %d e %d: ", nr, nc);
            scanf("%d", &dim);
            if ((dim>=nr && dim>=nc) || dim<=0)
            {
                printf("Dimensione non adatta\n");
                fine = 1;
            }
            else
            {
                sottomatrice(matrix, nr, nc, dim);
            }
        } while(!fine);
        printf("Programma Terminato");
    }
    fclose(fIn);
    return 0;
}
void stampaMatrice(int matrix[MAX_SIZE][MAX_SIZE], int r0, int c0, int dim)
{
    for (int i=r0; i<r0+dim; i++)
    {
        for (int j=c0; j<c0+dim; j++)
        {
            printf("% d ", matrix[i][j]);
        }
        printf("\n");
   }
   printf("\n");
}
int sommaMatrice(int matrix[MAX_SIZE][MAX_SIZE], int r0, int c0, int dim)
{
    int sum;

    for (int i=r0; i<r0+dim; i++)
    {
        for (int j=c0; j<c0+dim; j++)
        {
            sum+=matrix[i][j];
        }
   }
   return sum;
}
void sottomatrice(int matrix[MAX_SIZE][MAX_SIZE],int nr, int nc, int dim)
{
    int sum, maxi, maxj, maxsum; // Variabile per la memorizazione degli elementi

    for (int i=0; i<=nr-dim; i++)
    {
        for (int j=0; j<=nc-dim; j++)
        {
            stampaMatrice(matrix, i, j, dim);
            sum=sommaMatrice(matrix, i, j, dim );
            if ((i==0 && j==0) || maxsum<sum)
            {
                maxi=i;
                maxj=j;
                maxsum=sum;
            }
        }
    }
    printf("La sottomatrice con somma degli elementi massima (%d) è: \n", sum);
    stampaMatrice(matrix, maxi, maxj, dim);
}