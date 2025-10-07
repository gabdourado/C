/* FUNÇÕES BÁSICAS PARA A MANIPULAÇÃO DE LISTAS ENCADEADAS - CRUD (Create, Read, Update, Delete) */

#include "CRUD_Lista.c"

/*
    Função que cria uma lista vazia:
    I) Retorno NULL pois a lista a princípio não tem nenhum nó
*/
PLista lista_cria (void);

/* 
    Função que insere um novo nó na lista:
    I) Aloco dinamicamente um espaço na memória para o novo nó
    II) Coloco a informação dentro do nó
    III) Faço o novo nó apontar para o antigo primeiro nó (agora segundo nó)
    IV) Retorno o novo primeiro nó
 */
PLista lista_insere (PLista L, int elemento);

/*
    Função que retira um elemento da lista:
    I) Percorre a lista até encontrar o elemento ou não
    II) Caso não encontre, basta retornar a lista sem alterações
    III) Caso encontre, o elemento pode estar no início da lista, no meio (entre dois nós) ou no fim
    IV) Caso esteja no início, basta fazer o novo primeiro nó ser o nó para onde o primeiro apontava e liberar o antigo primeiro nó
    V) Caso esteja no meio ou no fim, basta fazer o seu nó anterior apontar para onde ele apontava e liberar o nó
*/
PLista lista_remove (PLista L, int elemento);
/*
    Função que deleta toda a lista:
    I) Preciso guardar a referência para o elemento seguinte e em seguida apagar o atual
    II) Repeto esse processo até chegar onde o último elemento aponta, ou seja, NULL
*/
void lista_deleta(PLista L);

/*
    Função que imprime os nós de uma lista:
    I) Usar uma variável auxliar (lista auxiliar) para percorrer a lista
    II) Percorrer mostrando cada alemento até chegar onde o último elemento aponta, ou seja, NULL
*/
void lista_imprime (PLista L);