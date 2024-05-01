#include <stdio.h>
#include <ctype.h>
#define lenght 80
#define N_numeri 10
#define N_lettere 26

int codifica(FILE *, FILE*); //Prototipo per funzioni di codifica file
char numCode(char, int *);
char alphCode(char, char);

int decodifica(FILE*, FILE*); //Prototipo per funzioni di decodifica file
char numDecode(char, int *);
char alphDecode(char, char);


int main()
{
    FILE *fin, *fout;
    char nome_file_input[lenght], nome_file_output[lenght];
    int scelta, result;

    printf("Scegliere un opzione\n1. Codifica\n2. Decodifica\nScelta: ");
    scanf("%d", &scelta);
    printf("Inserire il nome del file in input: \n");
    scanf("%s", nome_file_input);
    printf("Inserire il nome del file in output: \n");
    scanf("%s", nome_file_output);
    if ((fin=fopen(nome_file_input, "r"))==NULL)
    {
        printf("Errore di apertura file input%s\n", nome_file_input);
    }
    if ((fout=fopen(nome_file_output, "w"))==NULL)
    {
        printf("Errore di apertura file input%s\n", nome_file_output);
    }
    switch(scelta)
    {
        case 1:
            result=codifica(fin, fout);
            printf("Codifica completata. %d caratteri scritti nel file di output.\n", result);
            break;
        case 2:
            result=decodifica(fin, fout);
            printf("Decodifica completata. %d caratteri scritti nel file di output.\n", result);
            break;
        defalut:
            printf("Scelta non valida");
            break;
    }
    return 0;
}
char numCode(char chr, int *k)  //Funzione per la codifica dei numeri
{
    char num;

    num=chr-'0';
    num=(num+(*k))%N_numeri;
    (*k)++;
    num+='0';
    return num;
}
char alphCode(char chr, char prevchar) //Funzione per la codifica alfabetica
{
    char h;

    if (isupper(prevchar)!=0)
    {
        h=prevchar-'A';
    }
    else 
    {
        h=prevchar-'a';
    }
    if (isupper(chr)!=0)
    {
        chr=(chr-'A'+h)%26 +'A';
    }
    else
    {
        chr=(chr-'a'+h)%26 +'a';
    }
    return chr;
}
int codifica (FILE *fin, FILE *fout)  //codifica del file; suddivisa in più funzioni singole
{
    char chr, prevChr;
    int k=0;

    prevChr=' ';
    while ((chr=fgetc(fin))!=EOF)
    {
        if (isdigit(chr)!=0)
        {
            chr=numCode(chr, &k);
        }
        else if (isalpha(chr)!=0 && isalpha(prevChr)!=0)
        {
            chr=alphCode(chr, prevChr);
        }
        fputc(chr, fout);
        prevChr=chr;
    }
    return ftell(fout);
}
char numDecode(char chr, int *k) // Funzione per la decodifica dei numeri
{
    int num;

    num=chr-'0';
    num=(num-(*k)+10)%N_numeri;
    num+='0';
    (*k)++;
    return num;
}
char alphDecode(char chr, char prevchar) // Funzione per la decodifica dei caratteri alfabetici
{
    char h;

    if (isupper(prevchar)!=0)
    {
        h=prevchar-'A';
    }
    else 
    {
        h=prevchar-'a';
    }
    if (isupper(chr)!=0)
    {
        chr = (chr - 'A' - h + N_lettere)%26 +'A';
    }
    else
    {
        chr = (chr - 'a' - h + N_lettere)%26 +'a';
    }
    return chr;
}
int decodifica (FILE *fin, FILE *fout) // Decodifica file; suddivisa in sotto-funzioni
{
    char chr, prevchar;
    int k=0;

    prevchar=' ';
    while((chr=fgetc(fin))!=EOF)
    {
        if (isdigit(chr)!=0)
        {
            chr=numDecode(chr, &k);
        }
        else if (isalpha(chr)!=0 && isalpha(prevchar)!=0)
        {
            chr=alphDecode(chr, prevchar);
        }
        fputc(chr, fout);
        prevchar=chr;
    }
    return ftell(fout);
}