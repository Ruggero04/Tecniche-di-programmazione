# include <stdio.h>
# include <stdlib.h>

void calculate( float, float, char);
int check0division(char, float);

int main(void) {
    char operando;
    float op1, op2;

    puts("Inserire l'operatore: ");
    operando=fgetc(stdin);
    puts("Inserire i due operandi: ");
    scanf("%f%f", &op1, &op2);
    if (check0division!=0) {
        calculate(op1, op1, operando);
    }
    else {
        printf("Errore! Non è definita la divisione per zero");
    }
}
int chech0division(char operando, float op2) {
    if (operando='/' && op2==0) {
        return 0;
    }
    else {
        return 1;
    }
}
void calculate(float op1, float op2, char operando) {
    float result;
    int valid=1;

    switch(operando) {
        case '+':
            result=op1+op2;
            break;
        case '-':
            result=op1-op2;
            break;
        case '/':
            result=op1/op2;
            break;
        case '*':
            result=op1*op2;
            break;
        default:
            printf("Invalid operand");
            valid=0;
            break;
    }
    if (valid==1) {
        printf("The result of %g %c %g is %g", op1, operando, op2, result);
    }
}