#include <stdio.h>

void MCD(int, int);
int main(void){
    int a, b;

    puts("Inserire due numeri interi:");
    scanf("%d%d", &a, &b);
    MCD(a, b);
    return 0;
}
void MCD(int a, int b) {
    int c, num1=a, num2=b, MCD;
    if (a>b) {
            num1=a;
            num2=b;
    }
    else{
        num1=b;
        num2=a;
    }
    do{
        c=num1%num2;
        num1=num2;
        num2=c;
    } while(c!=0);
    printf("Il massimo comune di divisore fra %d e %d è %d", a, b, num1);
}