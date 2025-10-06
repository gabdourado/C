/*
    Comando (simplificado): Você deve monitorar um estacionamento que só possui uma saída/entrada. Se 
    chega um novo carro e o estacionamento não está cheio, então o carro ocupa a última posição que 
    está disponível, mas se está cheio, ele vai embora, sem ao menos entrar. Se ao retirar um carro, 
    ele possui uma certa quantidade de carros na sua frente, estes saem e o carro pode sair, voltando 
    todos os demais seguindo a mesma ordem, mas avançando uma casa. O programa deve monitorar isso.

    Ocasião: Aula com Sabrina para Avaliação (AP1N1, 2025.2)

*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct Estacionamento {
    int vaga;
    char carros[10][8]; 
};

typedef struct Estacionamento estacionamento;

void estacionaCarro(estacionamento* E, char placa[8]) {
    if (E->vaga == 10) {
        printf("Estacionamento cheio.\n");
        exit(1);
    }

    strcpy(E->carros[E->vaga], placa);
    E->vaga += 1;

    printf("Carro: %s - %d/10 da vagas ocupadas\n", placa, E->vaga);
}

void retiraCarro(estacionamento* E, char placa[8]) {
    for (int i = 0; i < E->vaga; i++) {
        if (strcmp(E->carros[i], placa) == 0) {
            for (int j = i; j < E->vaga - 1; j++) strcpy(E->carros[j], E->carros[j+1]);
            
            printf("Carro: %s - Manobras: %d\n", placa, E->vaga - i - 1);
            
            E->vaga -= 1;
            break;
        }
    }
}

int main (void) {

    char s, p[8];
    estacionamento E = {0};

    for (int i = 0; i < 6; i++) {
        scanf(" %c %s", &s, p);

        if (s == 'E') {
            estacionaCarro(&E, p);
        } else {
            retiraCarro(&E, p);
        }
    }
    
    return 0;
}
