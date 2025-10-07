## 7.0 Definição de Ponteiros em C

Em C, um **Ponteiro** é uma variável que armazena o **endereço de memória** de outra variável. Isso significa que, ao invés de armazenar um valor diretamente, o ponteiro armazena a posição onde o valor está localizado.

Vamos usar uma tabela para ilustrar como a variável `var` e o ponteiro `ptr` interagem:

| **Endereço de Memória** | **Nome da Variável** | **Valor** |
| :---------------------: | :------------------: | :-------: |
|         0x1000          |        `var`         |    10     |
|         0x2000          |        `ptr`         |  0x1000   |

Explicação dos elementos da tabela:

* **`var`**: Uma variável armazenando o valor `10`. O endereço de memória de `var` é `0x1000`.
* **`ptr`**: Um ponteiro armazenando o endereço de memória de `var`. O valor de `ptr` é `0x1000`, que é o endereço de `var`.

## 7.1 Declaração de um Ponteiro

Para declarar um ponteiro, usamos o operador `*` na declaração. Isso indica que a variável é um ponteiro que irá armazenar o endereço de uma variável do tipo especificado.

```c
int* ptr; // Ponteiro para um inteiro
```
Aqui, `ptr` é um ponteiro que pode armazenar o endereço de memória de uma variável do tipo `int`.

## 7.2 Atribuindo Endereço a um Ponteiro

Para que o ponteiro armazene o endereço de uma variável, usamos o operador `&`. Este operador é conhecido como "**endereço de**". Ele retorna o endereço de memória da variável.
```c
int var = 10;
int *ptr;
ptr = &var; // O ponteiro ptr agora armazena o endereço de var

```
## 7.3 Acessando o Valor Armazenado no Endereço

Para acessar o valor armazenado no endereço de memória apontado pelo ponteiro, usamos o operador `*` novamente, mas dessa vez como "desreferência". Isso significa acessar o valor no local para o qual o ponteiro aponta.
```c
int var = 10;
int *ptr;
ptr = &var; // p armazena o endereço de var

printf("%d", *ptr); // Exibe 10, pois *ptr acessa o valor de var
```
## 7.4 Ponteiros e Funções

Quando estudamos funções no Capítulo 6, falamos sobre **passagem de parâmetros por valor**, onde uma **cópia** do valor da variável é enviada para a função. Nesse caso, qualquer alteração dentro da função **não afeta** a variável original.

Agora, vamos aprender sobre **passagem por referência**, onde passamos o **endereço de memória** da variável. Isso permite que a função **modifique diretamente** o valor da variável original, pois tem acesso ao seu endereço na memória.

Exemplo de Passagem por Referência:
```c
#include <stdio.h>

void alteraValor(int* var) {
    *var = 20;  // Alterando o valor da variável original
}

int main() {
    int var = 10;
    alteraValor(&var);  // Passando o endereço de var (por referência)
    printf("Novo valor da variável: %d\n", var);
    return 0;
}
```
Aqui, passamos o **endereço** de `var` para a função `alteraValor()`. A função pode acessar e modificar o valor de `var` diretamente, porque ela tem acesso à sua posição na memória. Após a execução da função, `var` foi alterada para `20`.
