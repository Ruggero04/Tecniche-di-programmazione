#include <stdio.h>
#define SIZE 30

int sottosequenze(int []);
void stampavettore(int [], int, int, int *);

int main()
{
    int V[SIZE]; // Vettore di numeri 
    int num, i=0;

    printf("Inserire 30 numeri nell'array:\n");
    while (i<SIZE)
    {
        scanf("%d", &num);
        V[i]=num;
        i++;
    }
    sottosequenze(V);
    return 0;
}
int sottosequenze(int V[])
{
    int inizio, fine;// "inizio" serve per calcolare da dove considerare il sottovettore, similmente "fine".
    int Trovato=1;  // Variabile logica per non iniziallizare "inizio" ad ogni valore i-esimo non nullo.
    int passo=1, k=1;  // Contatori del passo dell'intervallo di stampa e del numero di sottovettori.

    for (int j=0; j<SIZE; j++) 
    {
        if (V[j]!=0 && passo<3)
        {
            if (Trovato!=0) // Inizzializza la variabile "inizio" all'inizio del sottovettore da considerare.
            {
                inizio=j;
                Trovato=0;
            }
            passo++;
        }
        else if (V[j]==0 || passo==3)
        {
            fine=j+1;
            if (i==3 && V[fine]!=0) // Verifica che si sia considerato un sottovettore di lunghezza tre
            {                      //  e che l'elemento finale non sia nullo.
                stampavettore(V, inizio, i, &k);
            }
            passo=1;       // Reimposto le condizioni di ricerca del sottovettore.
            Trovato=1;
        }
    }
    return 0;
}
void stampavettore(int V[], int inizio, int passo, int *k)
{
    printf("\n%d° Sottovettore:\n", (*k));
    for (int i=inizio; i<inizio+passo; i++)
    {
        printf("%d", V[i]);
    }
    (*k)++;
    printf("\n");
}