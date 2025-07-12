#include <stdio.h>
#include <stdlib.h>

#include "CRUD_Lista.h"

/*
    Considere listas que armazenam números inteiros e implemente uma função para criar uma
    cópia de uma lista encadeada passada como parâmetro. Essa função deve obedecer ao protótipo:

        PLista copia(PLista L);

    Obs: Use as funções de CRUD_Lista.c para testes dentro da função principal do seu código.

*/

PLista copia(PLista L) {
    PLista PtrL, head, tail;

    PtrL = L;
    head = tail = NULL;

    while (PtrL != NULL) {
        PLista novo_no = (PLista) malloc(sizeof(Lista));
        novo_no->info = PtrL->info;
        novo_no->prox = NULL;

        if (head == NULL)
            head = novo_no;
        else
            tail->prox = novo_no;

        tail = novo_no;
        PtrL = PtrL->prox;
    }

    return head;
}

int main(void) {
    PLista L, L_copia;

    L = lista_cria();

    L = lista_insere(L, 1);
    L = lista_insere(L, 2);
    L = lista_insere(L, 3);

    printf("Lista: ");
    lista_imprime(L);

    L_copia = lista_cria();

    L_copia = copia(L);

    printf("Lista copiada: ");
    lista_imprime(L_copia);

    lista_deleta(L);
    lista_deleta(L_copia);
    
    return 0;
}