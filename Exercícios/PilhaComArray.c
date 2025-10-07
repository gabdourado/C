/*
    Comando (Simplificado): Criar uma pilha usando array, de tamanho máximo 10 e implementar funções:
    
        - p_cria: Cria e inicializa o tamanho atual da pilha
        - p_vazia: Verifica se a pilha está vazia
        - p_cheia: Verifica se a pilha está cheia
        - push: Adiciona um elemento no topo
        - pop: Retira um elemento to topo
        - imprime: Imprime todos os elementos da pilha (seguindo a política LIFO)
        - topo: Retorna o elemento do topo (sem alterar a pilha)
        - size_atual: Retorna a quantidade de elementos da pilha
        - dispo: Retorna a quantidade de espaços disponívis na pilha
        - libera: Libera a pilha alocada dinamicamente

*/

#include <stdio.h>
#include <stdlib.h>

#define max 10

struct pilha {
    int n;
    int vet[max];
};

typedef struct pilha Pilha;

Pilha* p_cria(void) {
    Pilha* p = (Pilha*) malloc (sizeof(Pilha));
    p->n = 0;
    return p;
}

int p_vazia(Pilha* p) {
    return (p->n == 0);
}

int p_cheia(Pilha* p) {
    return (p->n == max);
}

void push(Pilha* p, int elemento) {
    if (p_cheia(p)) {
        printf("Pilha cheia!\n");
        exit(1);
    }

    p->vet[p->n] = elemento;
    p->n++;
}

int pop(Pilha* p) {
    int out;
    if (p_vazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }

    out = p->vet[p->n - 1];
    p->n--;

    return out;
}

void imprime(Pilha* p) {
    while(!p_vazia(p)) {
        int topo = pop(p);
        printf("%d\n", topo);
    }
}

int topo(Pilha* p) {
    if(p_vazia(p)) {
        printf("Pilha vazia!");
        exit(1);
    }

    int out = pop(p);
    push(p, out);
    return out;
}

int size_atual(Pilha* p) {
    return(p->n);
}

int dispo(Pilha* p) {
    return (max - p->n);
}

void libera(Pilha* p) {
    free(p);
}

int main(void) {

    Pilha* p = p_cria();

    push(p, 1);
    push(p, 2);
    push(p, 3);

    printf("O elemento do topo é: %d\n", topo(p));
    printf("Quantidade de elementos na pilha: %d\n", size_atual(p));
    printf("Capacidade atual: %d\n", dispo(p));

    int saiu = pop(p);
    printf("Removendo elemento do topo: %d\n", saiu);

    push(p, 10);

    imprime(p);

    libera(p);

    return 0;

}

