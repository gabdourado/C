## 6.0 Funções em C 

Uma **Função** em C é um bloco de código reutilizável que executa uma tarefa específica. Ela permite dividir um programa grande em partes menores, tornando o código mais **organizado, modular e reutilizável**.

As funções seguem a seguinte sintaxe em C:
```c
tipo_retorno nome_da_funcao (tipo parametro1, tipo parametro2, ...) {
    // Bloco de código que executa alguma operação
    return valor; // (Opcional, depende do tipo de retorno)
}
```
Explicação dos elementos:

* **`tipo_retorno`**: Define o tipo de dado que a função retorna (`int`, `float`, `char`, `void`, etc.). Se a função **não retorna nada**, usamos `void`. 
 * **`nome_da_funcao`**: Nome que identificará a função. Deve ser único e seguir as regras de nomenclatura da linguagem C.
* **`parâmetros`**: São valores de entrada que podem ser passados para a função. Eles podem existir ou não, dependendo do objetivo da função.
 * **`return`**: Define o valor retornado pela função. Se o tipo de retorno for `void`, o `return` não é necessário.

## 6.1 Tipos de Funções

Em C, as funções podem ser classificadas de acordo com **a presença de parâmetros** e **a existência de retorno**. Essas combinações nos permitem estruturar melhor o código, dependendo da necessidade do programa.

### 6.1.1 Função sem retorno e sem parâmetro

Este tipo de função **não recebe valores de entrada (parâmetros) e não retorna nenhum valor**. Normalmente, é usada para executar uma tarefa específica, como exibir uma mensagem na tela.

```c
void saudacao() {
    printf("Olá! Bem-vindo ao programa.\n");
}
```
### 6.1.2 Função sem retorno e com parâmetros

Neste caso, **a função recebe valores de entrada (parâmetros), mas não retorna nada**. É útil quando queremos modificar algo ou exibir informações baseadas nos valores fornecidos.

```c
void imprimirNome(char nome[]) {
    printf("Olá, %s! Seja bem-vindo.\n", nome);
}
```

### 6.1.3 Função com retorno e sem parâmetro

Aqui, **a função não recebe parâmetros, mas retorna um valor**. Isso é útil quando queremos calcular ou obter um valor dentro da função e utilizá-lo em outras partes do programa.
```c
int obterNumero() { 
	return 42; 
}
```
### 6.1.4 Função com retorno e com parâmetro

Esse é o tipo mais completo de função, onde **recebemos valores como entrada (parâmetros) e retornamos um valor como saída**. Isso é ideal para cálculos e operações que precisam de entrada e saída.
```c
int somar(int a, int b) { 
	return a + b; 
}
```

## 6.2 Usando Funções na `main()`

A função `main()` é o ponto de entrada de um programa em C. Dentro dela, podemos chamar outras funções para organizar melhor o código e torná-lo mais modular, evitando repetições desnecessárias e facilitando a manutenção do programa.

### 6.2.1 Chamando Função sem retorno e sem parâmetro

A função `saudacao()` apenas imprime uma mensagem na tela quando chamada na `main()`.
```c
#include <stdio.h>

// Função sem parâmetros e sem retorno
void saudacao() {
    printf("Olá! Bem-vindo ao programa.\n");
}

int main() {
    saudacao();  // Chamando a função dentro da main
    return 0;
}
```
### 6.2.1 Chamando Função com retorno e com parâmetro
Aqui, a função `soma()` recebe dois números como parâmetros e retorna a soma deles para a `main()`.
```c
#include <stdio.h>

// Função que recebe dois inteiros e retorna a soma
int soma(int a, int b) {
    return a + b;
}

int main() {
    int resultado = soma(10, 20);  // Chamando a função com argumentos
    printf("A soma é: %d\n", resultado);
    return 0;
}
```
Note que, ao chamar a função `soma()` na `main()`, seu retorno precisa ser armazenado em uma variável para que possamos usá-lo posteriormente, seja para exibição ou para outras operações.

## 6.3 Funções Recursivas

Uma **função recursiva** é uma função que **chama a si mesma** para resolver um problema. Esse conceito é útil quando um problema pode ser dividido em subproblemas menores de mesma natureza.

Para que a recursão funcione corretamente, a função precisa ter **dois elementos essenciais**:

1. **Caso base**: A condição que encerra a recursão, evitando chamadas infinitas.
2. **Chamada recursiva**: A função chama a si mesma, reduzindo o problema a um caso mais simples.

Confira a implementação recursiva em C para calcular o fatorial de um número:
```c
int fatorial(int n) {
    if (n == 0)  // Caso base
        return 1;
    return n * fatorial(n - 1); // Chamada recursiva
}
```
