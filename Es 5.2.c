#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200
#define PAROLA 50

typedef struct dizionario
{
    char token[PAROLA]; // Token di codifica delle parola 
    char sequenza[PAROLA]; // Sequenza di caratteri costituente la parola codificata
} diz;

int compileDict(diz[]); // Funzione per la compilazione del dizionario per le sostituzioni;
void linescan(char[], int, diz[], FILE*); // Funzione per scansionare linearmente la riga;
int compare(char[], int , int, char[]); // Funzione per il confronto della singola parola con la stringa del dizionario;

int main()
{
    FILE *fin, *fout;
    diz Dict[MAX]; // Vettore di struct per costruire il dizionario;
    char nomefile[MAX]; // Vettore stringa per il nome del file;
    char riga[MAX]; // Vettore stringa per ogni riga del testo;
    int numElm; //

    printf(("Inserire il nome del file sorgente: "));
    scanf("%s", nomefile);
    if ((fin=fopen(nomefile, "r"))==NULL ||(fout=fopen("../ricodificato5_2.txt", "w"))==NULL)
    {
        printf("Errore di apertura file input");
        exit(-1);
    }
    else
    {
        numElm=compileDict(Dict);
        while (!feof(fin))
        {
            if (!feof(fin))
            {
                fgets(riga, MAX, fin);
                linescan(riga, numElm, Dict, fout);
            }
        }
    }
    fclose(fin);
    return 0;
}
int compileDict(diz Dict[MAX])
{
    int numElm; // Variabile per il numero di sostituzioni
    FILE *ind; // Input file per il file dizionario

    if ((ind=fopen("../dizionario.txt", "r"))==NULL)
    {
        printf("Errore apertura file dizionario");
        exit(-1);
    }
    else
    {
        fscanf(ind, "%d", &numElm);
        for(int i=0; i<numElm; i++)
        {
            fscanf(ind, "%s %s", Dict[i].token, Dict[i].sequenza);
        }
        fclose(ind);
        return numElm;
    }
}
int compare(char riga[MAX], int i, int len, char parola[PAROLA]) 
{
    for (int j=0; j<len; j++)
    {
        if (riga[i+j]!=parola[j])
        {
            return 0;
        }
    }
    return 1;
}
void linescan(char riga[MAX], int numElm, diz Dict[MAX], FILE *fout)
{
    int i, j;
    int Trovato; // Variabile logica per la codifica
    int len;

    for (i=0; riga[i]!='\0'; i++)
    {
        Trovato=0;
        for (j=0; j<numElm;  j++)
        {
            len=strlen(Dict[j].sequenza);
            if (compare(riga, i, len, Dict[j].sequenza)==1)
            {
                Trovato=1;
                break;
            }
        }
        if (Trovato)
        {
            fprintf(fout, "%s", Dict[j].token);
            i=i+len-1;
        }
        else
        {
            fprintf(fout, "%c", riga[i]);
        }
    }
}