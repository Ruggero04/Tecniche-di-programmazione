# include <stdio.h>

void fibbonacci(int);
int main() {
    int N;

    puts("Inserire un numero N di termini della serie da visualizzare:");
    scanf("%d", &N);
    fibbonacci(N);
    return 0;
}
void fibbonacci(int N) {
    int xi1=1, xi2=0, xi, i;

    if (N<=0) {
        printf("Errore! Il numero deve essere positivo");
    }
    else if (N==1){
        printf("0");
    }
    else if (N==2) {
        printf("0 1");
    }
    else {
        printf("%d %d", xi2, xi1);
        for(i=2; i<=N; i++) {
            xi=xi1+xi2;
            printf(" %d", xi);
            xi2=xi1;
            xi1=xi;
        }
    }
}