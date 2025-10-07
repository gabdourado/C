#include <stdio.h>
#include <stdlib.h>

#include "CRUD_Lista.h"

/*
    Considere listas que armazenam números inteiros e implemente uma função para testar se
    duas listas passadas como parâmetros são iguais. Essa função deve obedecer ao protótipo:

        int igual(PLista L1, PLista L2);

    Obs: Use as funções de CRUD_Lista.c para testes dentro da função principal do seu código.

*/

int comprimento(PLista L) {

    int comp = 0;
    PLista PtrL; 

   for (PtrL = L; PtrL != NULL; PtrL = PtrL->prox) comp++;

    return comp;
}

int igual(PLista L1, PLista L2) {

    if (comprimento(L1) != comprimento(L2)) return 0;

    PLista PtrL1, PtrL2;

    PtrL1 = L1;
    PtrL2 = L2;

    while (PtrL1 != NULL) {
        if (PtrL1->info != PtrL2->info)
            return 0;
        PtrL1 = PtrL1->prox;
        PtrL2 = PtrL2->prox;
    }
    return 1;
}

int main(void) {
    PLista L1, L2;

    L1 = lista_cria();

    L1 = lista_insere(L1, 1);
    L1 = lista_insere(L1, 2);
    L1 = lista_insere(L1, 3);

    printf("Lista L1: ");
    lista_imprime(L1);

    L2 = lista_cria();
    L2 = lista_insere(L2, 1);
    L2 = lista_insere(L2, 2);
    L2 = lista_insere(L2, 3);

    printf("Lista L2: ");
    lista_imprime(L2);

    if (igual(L1, L2))
        printf("As listas são iguais\n");
    else
        printf("As listas são diferentes\n");

    lista_deleta(L1);
    lista_deleta(L2);
    
    return 0;
}