#include <stdio.h>
#include <ctype.h>
#define SIZE 50

int decomprimi(FILE *, FILE *);
int comprimi(FILE *, FILE *);

int main() 
{
    char chr;
    int Pcount;
    FILE *fIn, *fOut;

    printf("Selezionare l'operazione da seguire\nComprimere (c) Decomprimere (d): ");
    scanf("%c", &chr);
    chr=tolower(chr);
    switch (chr) 
    {
        case 'c':
            if ((fIn=fopen("../sorgenteEs2_3.txt", "r"))==NULL || (fOut=fopen("../compresso.txt", "w"))==NULL)
            {
                printf("Errore di apertura file");
            }
            else 
            {
                Pcount=comprimi(fIn, fOut);
                printf("Operazione terminata: File compresso\nStampati %d caratteri", Pcount);
            }
            break;
        case 'd':
            if ((fIn=fopen("../compresso.txt", "r"))==NULL || (fOut=fopen("../decompresso.txt", "w"))==NULL)
            {
                printf("Errore di apertura file");
            }
            else 
            {
                Pcount=decomprimi(fIn, fOut);
                printf("Operazione terminata: File decompresso\nStampati %d caratteri", Pcount);
            }
            break;
        default:
            printf("Errore! Opzione \"%c\" non valida");
            break;
    }
    fclose(fIn);
    fclose(fOut);
    return 0;
}
int comprimi (FILE *fIn, FILE *fOut) 
{
    char riga[SIZE], prev, next; 
    int count, i, Pcount=0;

    while (!feof(fIn)) 
    {
        fgets(riga, SIZE, fIn);
        i=1;
        if (!feof(fIn)) 
        {
            prev=riga[0];
            while(i<SIZE && prev!='\0') 
            {
                next=riga[i];
                if(prev==next)
                {
                    count=0;
                    while(prev==next) 
                    {
                        count++;
                        prev=next;
                        next=riga[i+count];
                        if (count==9)
                        {
                            break;
                        }
                    }
                    fprintf(fOut, "%c", riga[i]);
                    fprintf(fOut, "%c", '$');
                    fprintf(fOut, "%d", count);
                    Pcount+=3;
                    i+=count;
                }
                else 
                {
                    fprintf(fOut,"%c", prev);
                    Pcount++;
                }
                prev=next;
                i++;
            }
        }
    }
    return Pcount;
}
int decomprimi(FILE *fIn, FILE *fOut) 
{
    char riga[SIZE], prev, next;
    int i, j, count, Pcount=0;

    while(!feof(fIn))
    {
        fgets(riga, SIZE, fIn);
        i=0;
        if(!feof(fIn))
        {
            while(i<SIZE && riga[i]!='\0')
            {
                if (riga[i]=='$')
                {
                    count=riga[i+1]-'0';
                    for(j=0;j<count; j++)
                    {
                        fprintf(fOut, "%c", riga[i-1]);
                        Pcount++;
                    }
                    i+=2;
                }
                else
                {
                    fprintf(fOut, "%c", riga[i]);
                    Pcount++;
                    i++;
                }
            }
        }
    }
    return Pcount;
}