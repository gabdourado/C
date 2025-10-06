/*
    Comando (simplificado):

    Crie um programa em C que gerencie um sistema de controle de tesouros piratas, onde cada baú contém moedas 
    de ouro. O programa deve ler um número N de baús e N valores inteiros representando a quantidade de moedas. 
    Utilize aritmética de ponteiros para acessar e imprimir os valores dos baús, e implemente uma função, que 
    recebe um ponteiro de ponteiro para o array e substitui o maior valor por -1, indicando que o baú foi 
    saqueado. Após a execução, o programa deve exibir o array atualizado.

    Ocasião: Aula com Sabrina para Avaliação (AP1N1, 2025.2)

*/

#include <stdio.h>
#include <stdlib.h>

void imprime(int* baus, int n) {
    for (int i = 0; i < n; i++) 
        printf("%d ", baus[i]);
    printf("\n");
}

int idx_maior(int* baus, int n) {
    int maior = baus[0];
    int idx = 0;
    for(int i = 0; i < n; i++) {
        if(baus[i] > maior) {
            maior = baus[i];
            idx = i;
        }
    }
    return idx;
}

void roubar_maior(int* baus, int n) {
    int bau_roubado = idx_maior(baus, n);
    baus[bau_roubado] = -1;
}

int main (void) {

    int n;
    scanf("%d", &n);

    int* baus = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &baus[i]);
    }

    printf("Baús:\n");
    imprime(baus, n);

    roubar_maior(baus, n);

    printf("Baús após saque:\n");
    imprime(baus, n);

    free(baus);

    return 0;
}