/*

    Comando (simplificado): Calular o MDC de dois inteiros x e y de forma iterativa e de forma recursiva.

    Ocasião: Aula com Sabrina para Avaliação (AP1N1, 2025.2) 

*/

#include <stdio.h>

void normalizar(int* x, int* y) {
    *x = x < 0 ? -(*x) : *x;
    *y = *y < 0 ? -(*y) : *y;
}

int mdc_recursivo(int x, int y) {

    normalizar(&x, &y);

    if (x == 0) return y;
    if (y == 0) return x;

    if (x > y)
        return mdc_recursivo (y, x % y); 
    else 
        return mdc_recursivo (x, y % x);
}

int mdc_iterativo(int x, int y) {

    normalizar(&x, &y);

    while(y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }

    return x;

}

int main (void) {

    int x, y, mdc;
    char c;

    scanf("%d %d %c", &x, &y, &c);

    if (c == 'R') mdc = mdc_iterativo(x, y);
    else mdc = mdc_recursivo(x, y);

    printf("%c - mdc(%d, %d) = %d\n", c, x, y, mdc);

    return 0;
}