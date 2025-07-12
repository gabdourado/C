#include <stdio.h>
#include <stdlib.h>
#include "CRUD_Lista.h"

/*
    Considere uma lista encadeada de valores inteiros e implemente uma função para retornar
    o número de nós da lista que possuem o campo info com valores maiores que n. Essa função 
    deve obedecer o seguinte protótipo:

        int maiores(PLista L, int n);

    Obs: Use as funções de CRUD_Lista.c para testes dentro da função principal do seu código.

*/

int maiores(PLista L, int n) {
    int qtd_maiores = 0;
    PLista PtrL;

    for (PtrL = L; PtrL != NULL; PtrL = PtrL->prox)
        if (PtrL->info > n)
            qtd_maiores++;

    return qtd_maiores;
}

int main(void) {
    int qtd_maiores, var;
    PLista L;

    L = lista_cria();

    L = lista_insere(L, 1);
    L = lista_insere(L, 2);
    L = lista_insere(L, 3);
    L = lista_insere(L, 4);
    L = lista_insere(L, 5);

    printf("Lista: ");
    lista_imprime(L);

    var = 2;

    qtd_maiores = maiores(L, var);

    printf("A quantidade de valores maiores que %d é: %d\n", var, qtd_maiores);

    lista_deleta(L);
    
    return 0;
}