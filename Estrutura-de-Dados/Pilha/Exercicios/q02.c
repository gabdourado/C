#include <stdio.h>
#include <stdlib.h>

#include "CRUD_Pilha.h"

/*
    Implemente uma função que receba duas pilhas, p1 e p2, e passe todos os elementos da pilha p2
    para o tipo da pilha p1. Observe o esboço a seguir:

    p1:            p2:
        1.0            2.0
        3.0            4.0
        5.0

    (após execução da função)

    p1:            p2:
        2.0
        4.0
        1.0
        3.0
        5.0
    
    Note que ao final dessa função, a pilha p2 vai estar vazia e a pilha p1 conterá 
    todos os elementos das duas pilhas.Essa função deve obedecer o seguinte protótipo:


        void concatena(PPilha P1, PPilha P2);

    Obs: Use as funções de CRUD_Pilha.h para testes dentro da função principal do seu código.

*/

void concatena(PPilha P1, PPilha P2) {
    PPilha P_aux;
    
    P_aux = pilha_cria();

    while (!pilha_vazia(P2)) pilha_push(P_aux, pilha_pop(P2));

    while (!pilha_vazia(P_aux)) pilha_push(P1, pilha_pop(P_aux));

    pilha_libera(P_aux);

}

int main (void) {
    PPilha P1, P2;

    P1 = pilha_cria();
    
    pilha_push(P1, 5.0);
    pilha_push(P1, 3.0);
    pilha_push(P1, 1.0);

    /* Imprimindo a pilha para teste*/
    printf("Pilha P1:\n");
    pilha_imprime(P1);

    P2 = pilha_cria();
    
    pilha_push(P2, 4.0);
    pilha_push(P2, 2.0);
    
    /* Imprimindo a pilha para teste*/
    printf("Pilha P2:\n");
    pilha_imprime(P2);

    concatena(P1, P2);

    /* Imprimindo a pilha para teste*/
    printf("Pilha P1 após a concatenação:\n");
    pilha_imprime(P1);

    pilha_libera(P1);
    pilha_libera(P2);

    return 0;
}
