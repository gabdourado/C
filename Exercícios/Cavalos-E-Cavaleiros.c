/*
    Comando (simplificado): Dado uma competição de corrida de cavalos, o programa deve:

    1. Implementar as seguintes structs:
        
        - Cavalo: Nome, valocidade Mínima, Velocidade Máxima e Estamina
        - Cavaleiro: Nome e Cavalo

    2. Funções:

        - mostrarCavaleiro: Mostra informações do Cavaleiro
        - verificarCavaleiros: Verifica se dois Cavaleiros são iguais
        - distanciaPercorrida: Calcula a distância percorrida por um Caveleiro
        - compararCavaleiros: Compara a distância percorrida por dois Cavaleiros

    Ocasião: Aula com Sabrina para Avaliação (ED, AP1N1, 2025.2)

*/

#include <stdio.h>
#include <string.h>

struct Cavalo {
    char nome[10];
    float v_min;
    float v_max;
    float estamina;
};

typedef struct Cavalo cavalo;

struct Cavaleiro {
    char nome[10];
    cavalo c;
};

typedef struct Cavaleiro cavaleiro;

void mostrarCavaleiro(cavaleiro* C) {
    printf("Nome: %s\n", C->nome);
    printf("Cavalo: %s\n", C->c.nome);
    printf("V_min: %.2f, V_max: %.2f, Estamina: %.2f\n", C->c.v_min, C->c.v_max, C->c.estamina);
}

int verificarCavaleiros(cavaleiro* C1, cavaleiro* C2) {
    if (strcmp(C1->nome, C2->nome) == 0 || strcmp(C1->c.nome, C2->c.nome) == 0) return 0;
    return 1;
}

float distanciaPercorrida(cavaleiro* C, float t) {
    float dist;
    
    if (t <= C->c.estamina) dist = C->c.v_max * C->c.estamina;
    else dist = C->c.v_max * C->c.estamina + C->c.v_min * (t - C->c.estamina);

    return dist;
}

void compararCavaleiros (cavaleiro* C1, cavaleiro* C2, float t) {
    float dist1, dist2;
    
    dist1 = distanciaPercorrida(C1, t);
    dist2 = distanciaPercorrida(C2, t);

    printf("%s percorreu %.2f mestros\n", C1->nome, dist1);
    printf("%s percorreu %.2f mestros\n", C2->nome, dist2);

    if (dist1 > dist2) printf("Vencedor: %s\n", C1->nome);
    else if (dist1 < dist2) printf("Vencedor: %s\n", C2->nome);
    else printf("Empate!\n");
}

int main (void) {

    cavaleiro C1, C2;
    float time;

    scanf("%s", C1.nome);
    scanf("%s", C1.c.nome);
    scanf("%f %f %f", &C1.c.v_min, &C1.c.v_max, &C1.c.estamina);

    scanf("%s", C2.nome);
    scanf("%s", C2.c.nome);
    scanf("%f %f %f", &C2.c.v_min, &C2.c.v_max, &C2.c.estamina);

    scanf("%f", &time);

    mostrarCavaleiro(&C1);
    mostrarCavaleiro(&C2);

    if (verificarCavaleiros(&C1, &C2) == 0) printf("Epa, cavaleiros ou cavalos iguais!");
    else compararCavaleiros(&C1, &C2, time);

    return 0;
}