#include <stdio.h>

void calcola(FILE *);
int somma(int, int, int);
int differenza(int , int , int);
int moltiplicazione(int, int, int);
int divisione(int, int, int);

int main(void)
{
    FILE *fIn;

    if ((fIn=fopen("../numeri.txt", "r"))==NULL)
    {
        printf("Errore apertura file");
    }
    else
    {
        calcola(fIn);
    }
    fclose(fIn);
    return 0;
}
int somma(int num, int X1, int X2)
{
    if (num==X1+X2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int moltiplicazione(int num,int X1,int X2)
{
    if (num==X1*X2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int differenza(int num, int X1, int X2)
{
    if (num==X1-X2)
    {
        return 1;
    }
    else if (num==X2-X1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int divisione(int num,int X1,int X2)
{
    if((X1==0 || X2==0) && num!=0)
    {
        return 0;
    }
    else if (num == (float) X1/X2)
    {
        return 1;
    }
    else if (num == (float) X2/X1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void calcola(FILE *fIn)
{
    int max, min, num, X1, X2, scartati;
    
    fscanf(fIn, "%d", &X2);
    fscanf(fIn, "%d", &X1);
    if (X2>X1)
    {
        max=X2;
        min=X1;
    }
    else
    {
        max=X1;
        min=X2;
    }
    while (!feof(fIn))
    {
        fscanf(fIn, "%d", &num);
        if (somma(num, X1, X2)==0 && moltiplicazione(num, X1, X2)==0 && divisione(num, X1, X2)==0 && differenza(num, X1, X2)==0)
        {
            scartati++;
            printf("Scartato: %d\n", num);
            fscanf(fIn, "%d", &X2);
            fscanf(fIn, "%d", &X1);
        }
        else 
        {
            X2=X1;
            X1=num;
        }
        if (num>max)
        {
            max=num;
        }
        if (num<min)
        {
            min=num;
        }
    }
    printf("Numero massimo: %d\nNumero minimo: %d\nNumeri scartati: %d", max, min, scartati);
}