/* FUNÇÕES BÁSICAS PARA A MANIPULAÇÃO DE PILHAS - CRUD (Create, Read, Update, Delete) */

#include <stdio.h>
#include <stdlib.h>

/* Implementação de Pilhas com Listas Simplesmente Encadeadas */

struct lista {
    float info;
    struct lista* prox;
};

typedef struct lista Lista;
typedef struct lista* PLista;

/* A pilha nada mais é do que um ponteiro para o primeiro elemento da lista encadeada que lhe forma */
struct pilha {
    PLista prim;
};

typedef struct pilha Pilha;
typedef struct pilha* PPilha;

/* Função que cria uma olha inicialmente vazia */
PPilha pilha_cria (void) {
    PPilha p = (PPilha) malloc (sizeof(Pilha));
    p->prim = NULL;
    return p;
}

/* 
    Função que insere um novo elemento na pilha: 
        I) Cria um novo nó na lista que compoem essa pilha
        II) Atribui ao novo nó da lista o valor passado
        III) Faz o novo nó apontar para onde a pilha apontava (antigo primero elemento da pilha)
        IV) Faz a pilha apontar para o novo nó (novo primeiro elemento da pilha)
*/
void pilha_push (PPilha P, float elemento) {
    PLista novo = (PLista) malloc (sizeof(Lista));
    novo->info = elemento;
    novo->prox = P->prim;
    P->prim = novo;
}

/* Função que verifica se uma pilha está vazia:
    I) Uma pilha está vazia se o primeiro elemento para onde ela aponta é NULL    
*/
int pilha_vazia (PPilha P) {
    if (P->prim == NULL)
        return 1;
    else    
        return 0;
}

/*
    Função que desempinha (retira um elemento do topo da lista):
        I) Cria um nó para ajudar na manipulação do novo primeiro elemento da pilha
        II) Cria a variável que iráser retornada com o valor do elemento desempilhado
        III) Verifica se a lista já não está vazia
        IV) Caso não, guarda no nó que sai o valor do primeiro elemento da pilha (que irá ser desempilhado)
        V) E ponta a pilha para o seu termo posterior (proximo da pilha)
        VI) Libera a posição (topo da pilha)
*/
float pilha_pop (PPilha P) {
    PLista no_saindo = (PLista) malloc (sizeof(Lista));
    float info_sai;
    if (pilha_vazia(P)) {
        printf("Pilha vazia!");
        exit(1);
    }
    no_saindo = P->prim;
    info_sai = no_saindo->info;
    P->prim = no_saindo->prox;
    free(no_saindo);
    return info_sai;
}

/* Função que libera uma pilha 
    I) Libera toda a lista com os nós
    II) LIbera a pilha (ponteiro para o primeiro elemento)
*/
void pilha_libera (PPilha P) {
    PLista lista_aux = P->prim;
    while(lista_aux != NULL){
        PLista ref_prox = lista_aux->prox;
        free(lista_aux);
        lista_aux = ref_prox;
    }
    free(P);
}

/* Função que imprime os elementos da pilha (para testes)*/
void pilha_imprime (PPilha P) {
    PLista lista_aux = P->prim;
    while (lista_aux != NULL) {
        printf("%.2f\n", lista_aux->info);
        lista_aux =lista_aux->prox;
    }
}

int main (void) {
    /* Criando uma pilha e fazendo push */
    PPilha P;
    P = pilha_cria();
    pilha_push(P, 2);
    pilha_push(P, 3);
    pilha_push(P, 1);
    pilha_push(P, 2);
    pilha_push(P, 4);

    /* Imprimindo a pilha para teste*/
    printf("Pilha com todos os elementos empilhado:\n");
    pilha_imprime(P);

    /* Retirando um elemento do topo da lista (pop)*/
    float saiu = pilha_pop(P);

    /* Imprimindo novamente a lista*/
    printf("Após um pop:\n");
    pilha_imprime(P);


    /* Liberando a pilha */
    pilha_libera(P);

    printf("Fim do Programa\n");
    
    return 0;
}
