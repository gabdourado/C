#include <stdio.h>
#include <stdlib.h>

#include "CRUD_Lista.h"

/*
    Implemente uma função que tenha como valor de retorno o comprimento de uma lista
    encadeada, isto é, que calcule o número de nós de uma lista. Essa função deve obdecer
    o seguinte protótipo: 

        int comprimento(PLista L);

    Obs: Use as funções de CRUD_Lista.c para testes dentro da função principal do seu código.

*/

int comprimento(PLista L) {

    int comp = 0;
    PLista PtrL; 

   for (PtrL = L; PtrL != NULL; PtrL = PtrL->prox) comp++;

    return comp;
}

int main(void) {
    int comp;
    PLista L;

    L = lista_cria();

    L = lista_insere(L, 1);
    L = lista_insere(L, 2);
    L = lista_insere(L, 3);
    L = lista_insere(L, 4);

    printf("Lista: ");
    lista_imprime(L);

    comp = comprimento(L);

    printf("O Comprimento da lista é: %d\n", comp);

    lista_deleta(L);
    
    return 0;
}