#include <stdio.h>
#include <stdlib.h>

#include "CRUD_Lista.h"

/*
    Considere listas de valores interios e implemente uma função que receba como parãmtros uma
    lista encadeada e um valor inteiro n e divida a lista em duas, de forma que à segunda lista 
    começa no primeiro nó logo após a primeira ocorrência de n na lista original. O esboço a 
    seguir mostra o funcionamento desejado, adote n = 5:

        L: 3 -> 17 -> 5 -> 12 -> 1 -> NULL

        L1: 3 -> 17-> 5 -> NULL
        
        L2: 12 -> 1 -> NULL
    
    Essa função deve obdecer o seguinte protótipo: 

        PLista separa(PLista L, in n);

    A função deve retornar um ponteiro para a segunda subdivisão da lista original, enquanto
    L deve continuar apontando para o primeiro elemento da primeira subdivisão da lista.
    
    Obs: Use as funções de CRUD_Lista.c para testes dentro da função principal do seu código.

*/

PLista separa(PLista L, int n) {
    
    PLista PtrL, PtrL2, head, tail;
    
    PtrL2 = head = tail = NULL;
    PtrL = L;

    while (PtrL != NULL && PtrL->info != n) PtrL = PtrL->prox;

    if (PtrL == NULL)
        return NULL;
    
    PtrL2 = PtrL->prox;
    PtrL->prox = NULL;

    while (PtrL2 != NULL) {
        PLista novo_no = (PLista) malloc(sizeof(Lista));
        novo_no->info = PtrL2->info;
        novo_no->prox = NULL;

        if (head == NULL)
            head = novo_no;
        else
            tail->prox = novo_no;

        tail = novo_no;
        PtrL2 = PtrL2->prox;
    }

    return head;
}

int main(void) {
    PLista L1, L2;

    L1 = lista_cria();

    L1 = lista_insere(L1, 1);
    L1 = lista_insere(L1, 12);
    L1 = lista_insere(L1, 5);
    L1 = lista_insere(L1, 17);
    L1 = lista_insere(L1, 3);

    printf("Lista Original: ");
    lista_imprime(L1);

    L2 = lista_cria();

    L2 = separa(L1, 5);

    printf("Listas Separadas:\n");

    printf("Lista L1: ");
    lista_imprime(L1);


    printf("Lista 2: ");
    
    if (L2)
        lista_imprime(L2);
    else
        printf("NULL\n");

    lista_deleta(L1);
    lista_deleta(L2);
    
    return 0;
}


