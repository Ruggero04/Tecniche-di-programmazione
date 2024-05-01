# include <stdio.h>

int main() {
    int x, y=3;
    float z;

    printf("Inserire un numero: ");
    scanf("%d",&x);
    z=(float) x/y;
    printf("%d/%d=%.3f", x, y, z);
    return 0;
}