#include <stdio.h>
#include <stdlib.h>

#include "CRUD_Lista.h"

/*
    Implemente uma função que recebe como parâmetro uma lista encadeada e inverta o encadeamento
    de seus nós, retornando a lista resultante. Após a execução dessa função, cada nós da lista 
    vai estar apontando para o nó que originalmente era seu antecessor, e o último nó da lista
    passará a ser o primeiro nó da lista inverdida, conforme o esboço abaixo:

        L: 1 -> 2 -> 3 -> 4 -> NULLL

        LR: 4 -> 3 -> 2 -> 1 -> NULL

    Essa função deve obdecer o seguinte protótipo:

        PLista inverte(Plista L);

    Obs: Use as funções de CRUD_Lista.c para testes dentro da função principal do seu código.

*/

PLista inverte(PLista L) {
    if (L == NULL) return NULL;

    PLista PtrL, head;

    head = NULL;

    for (PtrL = L; PtrL != NULL; PtrL = PtrL->prox)
        head = lista_insere(head, PtrL->info);

    return head;
}

int main (void) {

    PLista L, L_inver;

    L = lista_cria();

    L = lista_insere(L, 4);
    L = lista_insere(L, 3);
    L = lista_insere(L, 2);
    L = lista_insere(L, 1);

    printf("Lista: ");
    lista_imprime(L);

    L_inver = inverte(L);

    printf("Lista invertida: ");
    lista_imprime(L_inver);

    lista_deleta(L);
    lista_deleta(L_inver);

    return 0;
}