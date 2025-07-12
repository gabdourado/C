#include <stdio.h>
#include <stdlib.h>

#include "CRUD_Pilha.h"

/*
    Implemente uma função que recebe uma pilha como parâmetro e retorne o valor
    armazenado no seu topo, restaurando o conteúdo da pilha. Essa função deve obe-
    decer o seguinte protótipo:
    
        float topo(PPilha P);

    Obs: Use as funções de CRUD_Pilha.h para testes dentro da função principal do seu código.

*/

float topo(PPilha P) {
    float elemento;
    
    elemento = pilha_pop(P);
    pilha_push(P, elemento);

    return elemento;
}

int main (void) {
    float elemento_topo;
    PPilha P;

    P = pilha_cria();
    
    pilha_push(P, 2);
    pilha_push(P, 3);
    pilha_push(P, 1);
    pilha_push(P, 2);

    /* Imprimindo a pilha para teste*/
    printf("Pilha:\n");
    pilha_imprime(P);

    elemento_topo = topo(P);
    printf("O elemento do topo é: %.2f\n", elemento_topo);

    /* Imprimindo a pilha para teste*/
    printf("Pilha sem alterações:\n");
    pilha_imprime(P);


    /* Liberando a pilha */
    pilha_libera(P);

    
    return 0;
}