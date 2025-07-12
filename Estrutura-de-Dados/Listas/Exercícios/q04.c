#include <stdio.h>
#include <stdlib.h>

#include "CRUD_Lista.h"

/*
    Implemente uma função que recebe duas listas encadeadas de valores inteiros e retorne
    a lista resultante da concatenação dessas duas listas recebidas como parâmetros, isto é,
    após a concatenação, o último elemento da primeira lista deve apontar para o primeiro elemen-
    to da segunda conforme o espoço:

    L1: 1 -> 2 -> 3 -> NULL

    L2: 4 -> 5 -> NULL

    LR: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    
    Essa função deve obdecer o seguinte protótipo: 

        PLIsta concatena(PLista L1, PLista L2);

    Obs: Use as funções de CRUD_Lista.c para testes dentro da função principal do seu código.

*/

PLista concatena(PLista L1, PLista L2) {
    
    PLista PtrL1, PtrL2, head, tail;
    
    PtrL1 = L1;
    PtrL2 = L2;

    head = tail = NULL;

    while (PtrL1 != NULL) {
        PLista novo_no = (PLista) malloc(sizeof(Lista));
        novo_no->info = PtrL1->info;
        novo_no->prox = NULL;

        if(head == NULL)
            head = novo_no;
        else
            tail->prox = novo_no;
        
        tail = novo_no;
        PtrL1 = PtrL1->prox;
    }

    while (PtrL2 != NULL) {
        PLista novo_no = (PLista) malloc(sizeof(Lista));
        novo_no->info = PtrL2->info;
        novo_no->prox = NULL;

        if(head == NULL)
            head = novo_no;
        else
            tail->prox = novo_no;
        
        tail = novo_no;
        PtrL2 = PtrL2->prox;
    }

    return head;
}


int main(void) {
    PLista L1, L2, LR;

    L1 = lista_cria();

    L1 = lista_insere(L1, 3);
    L1 = lista_insere(L1, 2);
    L1 = lista_insere(L1, 1);

    printf("Lista L1: ");
    lista_imprime(L1);

    L2 = lista_cria();
    L2 = lista_insere(L2, 5);
    L2 = lista_insere(L2, 4);

    printf("Lista 2: ");
    lista_imprime(L2);

    LR = concatena(L1, L2);

    printf("Lista Resultante: ");
    lista_imprime(LR);

    lista_deleta(L1);
    lista_deleta(L2);
    lista_deleta(LR);
    
    return 0;
}