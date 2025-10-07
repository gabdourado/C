/* FUNÇÕES BÁSICAS PARA A MANIPULAÇÃO DE PILHAS - CRUD (Create, Read, Update, Delete) */

/* Implementação de Pilhas com Listas Simplesmente Encadeadas */
#include "CRUD_Pilha.c"

/* Função que cria uma olha inicialmente vazia */
PPilha pilha_cria (void);

/* 
    Função que insere um novo elemento na pilha: 
        I) Cria um novo nó na lista que compoem essa pilha
        II) Atribui ao novo nó da lista o valor passado
        III) Faz o novo nó apontar para onde a pilha apontava (antigo primero elemento da pilha)
        IV) Faz a pilha apontar para o novo nó (novo primeiro elemento da pilha)
*/
void pilha_push (PPilha P, float elemento);

/* Função que verifica se uma pilha está vazia:
    I) Uma pilha está vazia se o primeiro elemento para onde ela aponta é NULL    
*/
int pilha_vazia (PPilha P);

/*
    Função que desempinha (retira um elemento do topo da lista):
        I) Cria um nó para ajudar na manipulação do novo primeiro elemento da pilha
        II) Cria a variável que irá ser retornada com o valor do elemento desempilhado
        III) Verifica se a lista já não está vazia
        IV) Caso não, guarda no nó que sai o valor do primeiro elemento da pilha (que irá ser desempilhado)
        V) E ponta a pilha para o seu termo posterior (proximo da pilha)
        VI) Libera a posição (topo da pilha)
*/
float pilha_pop (PPilha P);

/* Função que libera uma pilha 
    I) Libera toda a lista com os nós
    II) LIbera a pilha (ponteiro para o primeiro elemento)
*/
void pilha_libera (PPilha P);

/* Função que imprime os elementos da pilha (para testes)*/
void pilha_imprime (PPilha P);