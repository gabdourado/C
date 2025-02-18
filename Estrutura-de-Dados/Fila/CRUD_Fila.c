/* FUNÇÕES BÁSICAS PARA A MANIPULAÇÃO DE FILAS - CRUD (Create, Read, Update, Delete) */

#include <stdio.h>
#include <stdlib.h>

/* Implementação de Filas utilizando Listas Simplesmente Encadeadas */
struct lista {
    int info;
    struct lista* prox;
};

typedef struct lista Lista;
typedef struct lista* PLista;

/* Definição da struct fila */
struct fila {
    PLista ini;
    PLista fim;
};

typedef struct fila Fila;
typedef struct fila* PFila;

/* Função de criação de uma Fila vazia */
PFila fila_cria (void) {
    PFila F = (PFila) malloc (sizeof(Fila));
    F->ini = F->fim = NULL;
    return F;
}

/* 
    Função que insere um novo elemento no fim da fila (enqueue):
        I) Caso a fila esteja vazia, o elemento inserido é o primeiro, logo, ele é o inicio e o fim da fila
        II) Caso a fila não esteja vazia, fazemos o elemento anterior (antigo final) apontar para o novo final
        III) O novo final aponta para onde o antigo apontava (NULL)
        IV) O ponteiro final aponta para o novo final
*/
void fila_enqueue (PFila F, int elemento) {
    PLista novo_no = (PLista) malloc (sizeof(Lista));
    novo_no->info = elemento;
    novo_no->prox = NULL;
    if (F->fim != NULL) {
        F->fim->prox = novo_no; /* A fila não estava vazia, o antigo fim aponta para o novo fim */
    }
    else { /* A fila estava vazia, o novo elemento é o inicio e o fim*/
        F->ini = novo_no;
    }
    F->fim = novo_no; /* Atualizo o fim da fila */
}

/* Função que verifica se uma fila está vazia:
    I) Uma fila está vazia se o primeiro elemento para onde ela aponta é NULL    
*/
int fila_vazia (PFila F) {
    if (F->ini == NULL)
        return 1;
    else    
        return 0;
}

/*
    Função que remove um elemento do início da fila (dequeue):
        I) Crio uma variável auxiliar para guardar a referencia para o proximo elemento da fila
        II) Faço a fila apontar para o meu segundo elemento (ini->prox)
        III) Removo o meu novo elemento     

*/
int fila_dequeue (PFila F) {
    PLista no_sai;
    int info_sai;
    if (fila_vazia(F)) {
        printf("Fila vazia\n");
        exit(1);
    }
    no_sai = F->ini;
    info_sai = no_sai->info;
    F->ini = no_sai->prox;
    if (F->ini == NULL) { /* A lista ficou vazia */
        F->fim = NULL;
    }
    free(no_sai);
    return info_sai;
}

/* Função que libera uma fila 
    I) Libera toda a lista com os nós
    II) LIbera a fila (ponteiro para o primeiro elemento)
*/
void fila_libera (PFila F) {
    PLista lista_aux = F->ini;
    while (lista_aux != NULL) {
        PLista ref_prox = lista_aux->prox;
        free(lista_aux);
        lista_aux = ref_prox;
    }
    free(F);
}

/* Função que imprime uma fila (para testes) */
void fila_imprime (PFila F) {
    PLista lista_aux = F->ini;
    while (lista_aux != NULL) {
        printf("%d\t", lista_aux->info);
        lista_aux = lista_aux->prox;
    }
    printf("\n");
}

int main (void) {
    /* Criando uma fila e atribuindo três elementos a ela*/
    PFila fila1 = fila_cria();
    fila_enqueue (fila1, 1);
    fila_enqueue (fila1, 2);
    fila_enqueue (fila1, 3);

    /* Mostrando a fila com os três elementos */
    printf("Minha fila com todos os elementos:\n");
    fila_imprime(fila1);

    /*removendo o elemento do inicio da fila */
    int removido;
    removido = fila_dequeue(fila1);
    printf("Removendo o elemento do inicio da fila:\n");
    fila_imprime(fila1);

    /* Adicionando mais um elemento ao fim da fila */
    printf("Adicionando mais um elemento ao final da fila:\n");
    fila_enqueue (fila1, 4);
    fila_imprime(fila1);

    /* Deletando até acabar todos os elementos */
    printf("Removendo gradativamente:\n");
    removido = fila_dequeue(fila1);
    fila_imprime(fila1);
    removido = fila_dequeue(fila1);
    fila_imprime(fila1);
    removido = fila_dequeue(fila1);
    fila_imprime(fila1);
    removido = fila_dequeue(fila1);

    /* Libera toda a fila (que já ta vazia)*/
    fila_libera(fila1);

    printf("Fim do Programa!\n");

    return 0;
}
