# include <stdio.h>
# include <string.h>
# include <stdlib.h>


typedef struct operation {
    char operand;
    float op1;
    float op2;
} op;

float calculate(op );
int operandCheck(char );
int zeroDivisionCheck(char, float);
unsigned int i=0;

int main(void) {
    FILE *fpRead, *fpWrite;
    char line[50];
    float result;
    op Operation;

    if ((fpRead=fopen("../operation.txt", "r"))==NULL) {
        printf("Errore! Impossibile aprire il file \"operation.txt\"");
    }
    if ((fpWrite=fopen("..//result.txt", "w"))==NULL) {
        printf("Errore! Impossibile aprire il file \"result.txt\"");
    }
    else {
        while (!feof(fpRead)) {
            i+=1;
            fgets(line, 50, fpRead);
            Operation.operand=line[0];
            Operation.op1=strtod(strtok(&line[2], " "), 0);
            Operation.op2=strtod(strtok(NULL, " "), 0);
            if (operandCheck(Operation.operand)==0 || zeroDivisionCheck(Operation.operand, Operation.op2)==0)
            {
                printf("Errore! Operando errato %c alla riga %d", Operation.operand, i);
                continue;
            }
            else
            {
                result=calculate(Operation);
                fprintf(fpWrite, "%c %.2f\n", Operation.operand, result);
            }
        }
    }
    return 0;
}
float calculate(op Operation) {
    float result; 

    if (Operation.operand=='+') {
            result=Operation.op1 + Operation.op2;
        } 
    else if (Operation.operand=='-')
            result=Operation.op1 - Operation.op2;
    else if (Operation.operand=='/') {
            result=Operation.op1 / Operation.op2;
        }
    else {
            result=Operation.op1 * Operation.op2;
    }
    return result;
}
int operandCheck(char operand){
    if (operand!='*'  && operand!='/' && operand!='-' && operand!='+') {
        return 0;
    }
    else {
        return 1;
    }
}
int zeroDivisionCheck(char operand, float value) {
    if (operand=='/' && value==0) {
        return 0;
    }
    else {
        return 1;
    }
}