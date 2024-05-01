# include<stdio.h>
# include<stdlib.h>
# include<ctype.h>
# define PI 3.14

void calculateArea(char, char, double);
int main(){
    char choice[6];

    puts("Digitare la scelta (Es Q D10): ");
    fgets(choice, 6, stdin);

    char figure=choice[0], operation=choice[2], value[3]={choice[3], choice[4], '\0'};
    double num=strtod(value, 0);

    calculateArea(figure, operation, num);
    return 0;
}
void calculateArea(char figure, char operation, double num) {
    figure=toupper(figure);
    operation=toupper(operation);
    float Area;

    switch(figure) {
        case 'Q':
            switch(operation) {
                case 'D':
                    Area=num*num/2;
                    break;
                case 'L':
                    Area=num*num;
                    break;
                default: 
                    printf("%c is not valid", operation);
                    break;
            }
            break;
        case 'C':
            switch(operation) {
                case 'D':
                    Area=PI*num*num/4;
                    break;
                case 'R':
                    Area=PI*num*num;
                    break;
                default: 
                    printf("%c is not valid", operation);
                    break;
            }
            break;
    }
    printf("The area is %.2f", Area);
}