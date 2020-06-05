#include <stdio.h>
#include <string.h>

int numeros[6];
int estrelas[3];

int numberCheck(int n) {
    int i;
    int flag;
    for ( i = 0; i < 6; i++)
    {
        if (n == numeros[i]) {
            flag = 1;
        }
    }
    if (flag == 1) {
        return 0;
    }
    else {
        return 1;
    }
    
}

int getRandNum() {
    int n;
    do{
        n = (rand()%50)+1;
    }while (numberCheck(n) == 0);
    return n;
}

int starCheck(int s) {
    int i;
    int flag;
    for ( i = 0; i < 3; i++)
    {
        if (s == estrelas[i]) {
            flag = 1;
        }
    }
    if (flag == 1) {
        return 0;
    }
    else {
        return 1;
    }
    
}

int getRandStar() {
    int s;
    int flag;
    do{
        s = (rand()%3)+1;
        flag = starCheck(s);
    }while (flag == 0);
    return s;
}

int darEstrelas() {
    int i;
    int s;
    printf("\nEstrelas: ");
    for (i = 0; i < 3; i++) {
        s = getRandStar();
        printf("%d ", s);
    }
    
}

void main() {
    srand(time(0));
    darEstrelas();
}