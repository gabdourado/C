/*
    Comando (Simplificado): Implementar Fiboancci de forma recursiva.

    Ocasião: Aula com Mariana Matias para Avaliação (ED, AP1N1, 2025.2)
*/

#include<stdio.h>

int fib(int n) {
    
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    return fib(n - 1) + fib(n - 2);
}

int main (void) {

    int n;
    scanf("%d", &n);

    printf("F(%d) = %d\n", n, fib(n));

    return 0;
}