#include <stdio.h>
#include <stdlib.h>

#include "CRUD_Lista.h"

/*
    Considere listas de valores inteiros e implemente uma função que receba como parâmetros
    uma lista encadeada e um valor inteiro n, retire da lista todas as ocorrẽncias de n e 
    retorne a lista resultante. Essa função deve obdecer o seguinte protótipo: 

        PLIsta retira(PLista L1, int n);

    Obs: Use as funções de CRUD_Lista.c para testes dentro da função principal do seu código.

*/

PLista retira(PLista L, int n) {
    PLista PtrL;
    PLista head;

    for (PtrL = L; PtrL != NULL; PtrL = PtrL->prox)
        if (PtrL->info != n)
            head = lista_insere(head, PtrL->info);
    
    return head;
}

int main(void) {
    int n;
    PLista L, nova_L;

    L = lista_cria();

    L = lista_insere(L, 1);
    L = lista_insere(L, 2);
    L = lista_insere(L, 3);
    L = lista_insere(L, 4);

    printf("Lista: ");
    lista_imprime(L);

    nova_L = lista_cria();

    n = 2;
    nova_L = retira(L, n);

    printf("Lista após remoção da(s) ocorrência(s) de %d: ", n);
    lista_imprime(nova_L);

    lista_deleta(L);
    lista_deleta(nova_L);
    
    return 0;
}