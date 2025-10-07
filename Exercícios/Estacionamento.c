/*
    Comando (simplificado): Você deve monitorar um estacionamento que só possui uma saída/entrada. Se 
    chega um novo carro e o estacionamento não está cheio, então o carro ocupa a última posição que 
    está disponível, mas se está cheio, ele vai embora, sem ao menos entrar. Se ao retirar um carro, 
    ele possui uma certa quantidade de carros na sua frente, estes saem e o carro pode sair, voltando 
    todos os demais seguindo a mesma ordem, mas avançando uma casa. O programa deve monitorar isso.

    Ocasião: Aula com Sabrina para Avaliação (AP1N1, 2025.2)

*/

#include <stdio.h>
#include <string.h>

#define max_size 10
#define size_placa 8

struct Carro {
    char placa[size_placa];
    int manobras;
};

typedef struct Carro carro;

struct Estacionamento {
    int vaga;
    carro carros[max_size]; 
};

typedef struct Estacionamento estacionamento;

void estacionaCarro(estacionamento* E, char placa[size_placa]) {
    if (E->vaga == max_size) {
        printf("Estacionamento cheio.\n");
        return;
    }

    strcpy(E->carros[E->vaga].placa, placa);
    E->carros[E->vaga].manobras = 0;
    E->vaga += 1;

    printf("Carro: %s - %d/%d da vagas ocupadas\n", placa, E->vaga, max_size);
}

void retiraCarro(estacionamento* E, char placa[size_placa]) {
    for (int i = 0; i < E->vaga; i++) {

        if (strcmp(E->carros[i].placa, placa) == 0) {
            
            for(int j = i + 1; j < E->vaga; j++) E->carros[j].manobras += 1;
            
            printf("Carro: %s - Manobras totais: %d\n", placa, E->carros[i].manobras);

            for (int j = i; j < E->vaga - 1; j++) E->carros[j] = E->carros[j + 1];
            
            E->vaga -= 1;
            break;
        }
    }
}

int main (void) {

    char s, p[size_placa];
    estacionamento E = {0};

    while (scanf(" %c %s", &s, p) != EOF) {

        if (s == 'E') {
            estacionaCarro(&E, p);
        } else {
            retiraCarro(&E, p);
        }
    }
    
    return 0;
}
