/*

    Comando (simplificado): Calular o MDC de dois inteiros x e y de forma iterativa e de forma recursiva.

    Ocasião: Aula com Sabrina para Avaliação (AP1N1, 2025.2) 

*/

#include <stdio.h>

int mdc_recursivo(int x, int y) {

    x = x < 0 ? -x : x;
    y = y < 0 ? -y : y;

    if (x > y) {

        if (x % y == 0) return y;
        else return mdc_recursivo (y, x % y); 

    } else {

        if (y % x == 0) return x;
        else return mdc_recursivo (x, y % x); 

    }
}

int mdc_iterativo(int x, int y) {

    
    x = x < 0 ? -x : x;
    y = y < 0 ? -y : y;

    if (x > y) {

        while(y != 0) {
            int r = x % y;
            x = y;
            y = r;
        }

        return x;

    } else {

        while(x != 0) {
        int r = y % x;
            y = x;
            x = r;
        }

        return y;
    }
}

int main (void) {

    int x, y;

    scanf("%d %d", &x, &y);

    int mdc = mdc_iterativo(x, y);

    printf("mdc(%d, %d) = %d\n", x, y, mdc);

    return 0;
}