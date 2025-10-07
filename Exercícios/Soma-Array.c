/*
    Comando (Simplificado): Implementar soma recursiva e iterativa dos elementos de um array.

    Ocasião: Aula com Mariana Matias para Avaliação (ED, AP1N1, 2025.2)
*/

#include<stdio.h>
#include <stdlib.h>

int soma_recursiva(int* array, int n) {
    if (n == 0) return 0;
    return array[n - 1] + soma_recursiva(array, n-1);   
}

int soma_iterativa(int* array, int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) soma += array[i];
    return soma;
}

int main (void) {

    int max;
    scanf("%d", &max);

    int* array = (int*) malloc(max * sizeof(int));

    for (int i = 0; i < max; i++) scanf("%d", &array[i]);

    int n, soma;
    char c;
    scanf("%d %c", &n, &c);

    if (c == 'R') soma = soma_recursiva(array, n);
    else soma = soma_iterativa(array, n);

    printf("%c - Soma dos %d elementos: %d\n", c, n, soma);
    
    return 0;
}