#include <stdio.h>
#include <stdlib.h>

#include "CRUD_Lista.h"

/*
    Implemente uma função que construa uma nova lista com a intercalação dos nós de outras listas
    passadas como parâmtros. Essa função deve retornar a lisat resultante, conforme moestradono 
    esboço abaixo: 

        L1: 1 -> 3 -> 5 -> 7 -> NULL

        L2: 2 -> 4-> 6 -> NULL

        LR: 1 -> 2 -> 3 -> 4 -> 4 -> 6 -> 7 -> NULL

    
    Essa função deve obdecer o seguinte protótipo: 

        PLIsta merge(PLista L1, PLista L2);

    Obs: Use as funções de CRUD_Lista.c para testes dentro da função principal do seu código.

*/


PLista merge(PLista L1, PLista L2) {

    if (L1 == NULL) return L2;
    if (L2 == NULL) return L1;

    PLista PtrL1, PtrL2, head, tail;

    PtrL1 = L1;
    PtrL2 = L2;
    head = tail = NULL;

    while (PtrL1 != NULL || PtrL2 != NULL) {
        if (PtrL1 != NULL) {
            PLista novo_no = (PLista) malloc (sizeof(Lista));
            novo_no->info = PtrL1->info;
            novo_no->prox = NULL;
        
            if (head == NULL)
                head = novo_no;
            else
                tail->prox = novo_no;

            tail = novo_no;
            PtrL1 = PtrL1->prox;
        }

        if (PtrL2 != NULL) {
            PLista novo_no = (PLista) malloc (sizeof(Lista));
            novo_no->info = PtrL2->info;
            novo_no->prox = NULL;
        
            if (head == NULL)
                head = novo_no;
            else
                tail->prox = novo_no;

            tail = novo_no;
            PtrL2 = PtrL2->prox;
        }
    }
    return head;
}

int main(void) {
    PLista L1, L2, LR;

    L1 = lista_cria();

    L1 = lista_insere(L1, 7);
    L1 = lista_insere(L1, 5);
    L1 = lista_insere(L1, 3);
    L1 = lista_insere(L1, 1);

    printf("Lista 1: ");
    lista_imprime(L1);

    L2 = lista_cria();

    L2 = lista_insere(L2, 6);
    L2 = lista_insere(L2, 4);
    L2 = lista_insere(L2, 2);

    printf("Lista 2: ");
    lista_imprime(L2);

    LR = lista_cria();

    LR = merge(L1, L2);

    printf("Lista Concatenada: ");
    lista_imprime(LR);

    lista_deleta(L1);
    lista_deleta(L2);
    lista_deleta(LR);

    return 0;
}