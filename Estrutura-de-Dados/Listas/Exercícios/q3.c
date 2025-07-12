#include <stdio.h>
#include <stdlib.h>

#include "CRUD_Lista.h"

/*
    Implemente uma função que tenha como valor de retorno um ponteiro para o último nó de uma
    lista encadeada. A função deve seguir o seguinte protótipo:

        PLista ultimo(PLista L);

    Obs: Use as funções de CRUD_Lista.c para testes dentro da função principal do seu código.

*/

PLista ultimo(PLista L) {

    if (L == NULL) return L;

    PLista PtrUltimo;

    for(PtrUltimo = L; PtrUltimo->prox != NULL; PtrUltimo = PtrUltimo->prox);

    return PtrUltimo;
}

int main(void) {
    PLista L, PtrUltimo;

    L = lista_cria();

    L = lista_insere(L, 1);
    L = lista_insere(L, 2);
    L = lista_insere(L, 3);
    L = lista_insere(L, 4);

    printf("Lista: ");
    lista_imprime(L);

    PtrUltimo = ultimo(L);

    if (!PtrUltimo){
        printf("Lista sem elementos\n");
        return 0;
    }

    printf("O último elemento é %d na posição de memória %p\n", PtrUltimo->info, PtrUltimo);

    lista_deleta(L);
    lista_deleta(PtrUltimo);
    
    return 0;
}