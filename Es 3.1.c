#include <stdio.h> 
#include <ctype.h>
#define SIZE 80

void codificaFile(FILE *, FILE *);
void formattaFile(FILE *, FILE *);

int main(void)
{
    FILE *fIn, *fOut;

    if ((fIn=fopen("../inputEs3_1.txt", "r"))==NULL || (fOut=fopen("../testo1.txt", "w"))==NULL)
    {
        printf("Errore di apertura file!\n");
    }
    else
    {
        codificaFile(fIn, fOut);
        printf("Codifica eseguita correttamente\n");
        fclose(fIn);
        fclose(fOut);
        if ((fIn=fopen("../testo1.txt", "r"))==NULL || (fOut=fopen("../testoEs3_1.txt", "w"))==NULL)
        {
            printf("Errore di apertura file!");
        }
        else {
            formattaFile(fIn, fOut);
            fclose(fIn);
            fclose(fOut);
            remove("../testo1.txt");
            printf("Formattazione eseguita correttamente");
        }
    return 0;
    }
}
void codificaFile(FILE *fIn, FILE *fOut)
{
    char prev, next;
    
    prev=fgetc(fIn); 
    while (prev!=EOF)
    {
        next=fgetc(fIn);
        if (isdigit(prev)!=0)
        {
            fprintf(fOut, "%c", '*');
        }
        else if (ispunct(prev)!=0)
        {
            fprintf(fOut, "%c", prev);
            if (isspace(next)==0 &&  next!='\n')
            {
                fprintf(fOut, "%c", ' ');
            }
            if (prev=='.'||prev=='!'||prev=='?')
            {
                if (next=='\n')
                {
                    fprintf(fOut, "%c", next);
                    next=fgetc(fIn);
                 }
                if (isalpha(next)!=0 && islower(next)!=0)
                {
                    next=toupper(next);
                        fprintf(fOut, "%c", next);
                    next=fgetc(fIn);
                }
            }
        }
        else
        {
            fprintf(fOut, "%c", prev);   
        }
        prev=next;
    }     
}
void formattaFile(FILE *fIn, FILE *fOut)
{
    int counter=0, i;
    char chr;

    chr=fgetc(fIn);
    while (chr!=EOF)
    {
        counter++;
        if (counter>25)
        {
            fprintf(fOut, "%s", "| c:25\n");
            if(chr!='\n')
            {
                fprintf(fOut, "%c", chr);
            }
            counter=0;
        }
        else if (chr=='\n' && counter<26)
        {
            for ( i=counter; i<25; i++)
            {
                fprintf(fOut, "%c", ' ');
            }
            fprintf(fOut,"| c:%d\n", counter);
            counter=0;
        }
        else
        {
            fprintf(fOut, "%c", chr);
        }
        chr=fgetc(fIn);
    }
}