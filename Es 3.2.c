#include <stdio.h>
#include <ctype.h>

void checkFormat(FILE *);
int main()
{
    FILE *fIn;

    if ((fIn=fopen("../expr.txt", "r"))==NULL)
    {
        printf("Errore di apertura file \"exptr.txt");
    }
    else 
    {
        checkFormat(fIn);
    }
    fclose(fIn);
    return 0;
}
void checkFormat(FILE *fIn)
{
    char prev, next, chr, chr1;
    int lineIndx=1, openBrkCount=0, closedBrkCount=0;  

    prev=fgetc(fIn);
    next=fgetc(fIn);
    while (prev!=EOF)
    {
        if (prev=='\n')
        {
            if (openBrkCount!=closedBrkCount)
            {
                printf("Errore nella lettura delle parentesi (espressione %d)\n", lineIndx);
            }
            lineIndx++;
            openBrkCount=0;
            closedBrkCount=0;
        }
        else if (isdigit(prev)!=0)
        {
            chr=fgetc(fIn), chr1=next;
            if (chr1==' ' && (chr!='+' && chr!='-'&& chr!='/'&& chr!='*' && chr!=')'))
            {
                printf("Errore nella lettura di un numero (espressione %d)\n", lineIndx);
            }
            
        }
        else if (prev=='(')
        {
            openBrkCount++;
            if (prev=='(' && (next=='+'||next=='-'||next=='/'||next=='*' || next==')'))
            {
                printf("Errore nella lettura di un operando (espressione %d)\n", lineIndx);
            }
        }
        else if (prev==')') 
        {
            closedBrkCount++;
            chr=fgetc(fIn), chr1=next;
            if (chr1==' ' && (chr!='+' && chr!='-'&& chr!='/'&& chr!='*' && chr!=')'))
            {
                printf("Errore nella lettura di un numero (espressione %d)\n", lineIndx);
            }
        }
        else if (prev=='+'||prev=='-'||prev=='/'||prev=='*')
        {
            chr=fgetc(fIn), chr1=next;
            if (isdigit(chr)==0 && chr1!=')' && chr1!=' ' && isdigit(chr1)==0)
            {
                printf("Errore nella lettura di un operando (espressione %d)\n", lineIndx);
            }
            
        }
        if (isdigit(prev)==0 && prev!=')'&& prev!='+' && prev!='-'&& prev!='/' && prev!='*')
        {
            prev=next;
            next=fgetc(fIn);
        }
        else if (isdigit(prev)!=0 || prev==')'||prev=='+'||prev=='-'||prev=='/'||prev=='*')
        {
            prev=chr1;
            next=chr;
        }
    }
}