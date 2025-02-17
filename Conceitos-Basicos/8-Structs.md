## 8.0 Definição de Structs em C

Em C, uma `struct` (ou estrutura) é um tipo de dado composto que permite **agrupar diferentes tipos de dados** sob um único nome. Cada elemento dentro de uma `struct` é chamado de **membro**.

## 8.1 Declaração de uma `struct`

A declaração de uma `struct` começa com a palavra-chave `struct`, seguida pelo nome da `struct` e os membros que ela conterá.

```c
struct pessoa {
    char nome[50];
    int idade;
};
```
## 8.2 Inicialização de uma `struct`

Uma `struct` pode ser inicializada no momento de sua criação ou depois. A inicialização é feita atribuindo valores aos membros.

* **Inicialização no momento da criação**

Você pode inicializar uma `struct` diretamente quando a declara, usando chaves `{}` para fornecer os valores para os membros, na ordem em que foram definidos.
```c
#include <stdio.h>

struct pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct pessoa p1 = {"João", 30};  // Inicialização no momento da criação
    
    return 0;
}
```

* **Inicialização depois da criação**

Você pode declarar uma `struct` primeiro e depois atribuir valores aos seus membros individualmente.
```c
#include <stdio.h>
#include <string.h>

struct pessoa {
    char nome[50];
    int idade;
};

int main() {
	struct pessoa p1;  // Declaração sem inicialização
	
	strcpy(p1.nome, "João");  // Atribuindo valor ao membro nome
	p1.idade = 30;  // Atribuindo valor ao membro idade

    return 0;
}
```
## 8.3 Acesso a Membros de uma `struct`

Para acessar os membros de uma `struct`, usamos o operador **`.` (ponto)**.
```c
#include <stdio.h>

struct pessoa {
    char nome[50];
    int idade;
};

int main() {
	struct pessoa p1 = {"João", 30};
	printf("Nome: %s, Idade: %d\n", p1.nome, p1.idade);
	
    return 0;
}
```

## 8.4 Uso de `typedef`

O `typedef` pode ser usado para criar um apelido para um tipo de dado. Ao usá-lo com `struct`, podemos simplificar a declaração de variáveis do tipo `struct`, tornando o código mais legível.

```c
struct pessoa {
    char nome[50];
    int idade;
};

typedef struct pessoa Pessoa; // Agora podemos usar 'Pessoa' diretamente

int main() {
	Pessoa p1 = {"João", 30};
	printf("Nome: %s, Idade: %d\n", p1.nome, p1.idade);
	
    return 0;
}
```

## 8.5 Uso de `structs` aninhadas

Em C, é possível **aninha** uma `struct` dentro de outra. Isso permite criar estruturas mais complexas, com um relacionamento hierárquico entre os dados.

```c
struct endereco {
    char rua[50];
    int numero;
};

struct pessoa {
    char nome[50];
    int idade;
    struct endereco residencia; // Struct aninhada
};
```

Devido à hierarquia entre as `structs`, o operador ponto (`.`) é utilizado para acessar seus membros. Quando uma `struct` é aninhada, usamos o ponto repetidamente para acessar os membros internos.

Exemplo de acesso na função `main()`
```c
int main() {
    // Inicializando a struct Pessoa com valores para o nome, idade e endereço
    struct pessoa p1 = {"João", 30, {"Rua A", 123}};
    
    // Acessando os membros da struct pessoa e da struct endereco
    printf("Nome: %s\n", p1.nome);
    printf("Idade: %d\n", p1.idade);
    printf("Endereço: %s, %d\n", p1.residencia.rua, p1.residencia.numero);
    
    return 0;
}
```

## 8.6 Arrays de Structs

Um **Array de Struct** é uma coleção de elementos onde cada elemento é uma `struct`. Isso é útil quando você tem várias instâncias de um tipo de estrutura e precisa armazená-las de forma organizada. 

No exemplo abaixo, criamos uma `struct` chamada `aluno` e, em seguida, um **array de structs** para armazenar informações de vários alunos (`turma`):

```c
#include <stdio.h>

// Definindo a struct aluno
struct aluno {
    char nome[50];
    int matricula;
    int idade;
};

int main() {
    // Criando um array de 3 alunos
    struct aluno turma[3] = {
        {"Gabriel", 12345, 20},
        {"Mariana", 67890, 22},
        {"João", 11223, 19}
    };
    
    // Exibindo os dados dos alunos
    for (int i = 0; i < 3; i++) {
        printf("Nome: %s\n", turma[i].nome);
        printf("Matrícula: %d\n", turma[i].matricula);
        printf("Idade: %d\n\n", turma[i].idade);
    }
    
    return 0;
}
```
