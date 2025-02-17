## 1.0 Estrutura Sequencial em C

A **Estrutura Sequencial** é a forma mais simples de organizar as instruções em um programa. Nela, as **instruções** são **executadas uma após a outra**, na **ordem em que aparecem no código**, **sem desvios** ou **repetições**.

Um exemplo de Estrutura Sequencial Básica em C:

```c
#include <stdio.h> // Biblioteca padrão para entrada e saída

int main (void) {
    printf("Hello, World!\n"); // Exibe uma mensagem na tela
    return 0;
}
```

## 1.2 Bibliotecas em C

As **Bibliotecas** em C contêm funções prontas para serem usadas em programas. No exemplo acima, `#include <stdio.h>` importa a biblioteca **Standard Input Output (stdio)**, que permite usar funções como `printf()` para exibir mensagens na tela.

Outras Bibliotecas comuns:

- `<math.h>`: Funções matemáticas.
- `<stdlib.h>`: Alocação de memória, conversões.
- `<string.h>`: Manipulação de strings.

## 1.3 Fundamentos Básicos

### 1.3.1 Declaração de Variáveis

As **Variáveis** armazenam dados que podem ser manipulados ao longo da execução do programa. **Em C**, **toda variável precisa ser declarada com um tipo**. 

Exemplo de Declaração de Variáveis em C:

```c
int idade = 25;
float altura = 1.75;
char inicial = 'A';
```
A Linguagem C possui **quatro Tipos Básicos** que podem ser utilizados na declaração das variáveis: `int`, `float`, `double` e `char`. A partir desses tipos básicos, podem ser definidos outros, conforme apresentado na tabela a seguir.

|      Tipo       | Tamanho Aproximado |        Faixa de Valores        |
| :-------------: | :----------------: | :----------------------------: |
|     `char`      |       8 bits       |           -128 a 127           |
| `unsigned char` |       8 bits       |            0 a 255             |
|      `int`      |      16 bits       |        -32.768 a 32.767        |
| `unsigned int`  |      16 bits       |           0 a 65.535           |
|   `short int`   |      16 bits       |        -32.768 a 32.767        |
|     `long`      |      32 bits       | -2.147.483.648 a 2.147.483.647 |
| `unsigned long` |      32 bits       |       0 a 4.294.967.295        |
|     `float`     |      32 bits       |    3.4 × 10⁻³⁸ a 3.4 × 10³⁸    |
|    `double`     |      64 bits       |   1.7 × 10⁻³⁰⁸ a 1.7 × 10³⁰⁸   |
|  `long double`  |      80 bits       |  3.4 × 10⁻⁴⁹³² a 1.1 × 10⁴⁹³²  |

É importante ressaltar que, de acordo com o processador ou compilador C utilizado, o tamanho e a faixa de valores podem variar.

### 1.3.2 Declaração de Constantes

As **Constantes** são valores que não mudam durante a execução do programa. Em C, podem ser declaradas de duas formas:

1. Usando `#define`:
```c
#define PI 3.14159
```
2. Usando `const`:
```c
const float pi = 3.14159;
```
## 1.4 Operadores em C

Os **Operadores** são fundamentais em qualquer linguagem de programação, pois permitem realizar uma variedade de operações, como cálculos matemáticos, comparações e manipulação de dados.

### 1.4.1 Operadores Aritméticos

Os operadores aritméticos permitem realizar Operações Matemáticas:

|Operador|Operação|Exemplo|
|:-:|:-:|:-:|
|`+`|Adição|`c = a + b;`|
|`-`|Subtração|`c = a - b;`|
|`*`|Multiplicação|`c = a * b;`|
|`/`|Divisão|`c = a / b;`|
|`%`|Módulo|`c = a % b;`|

### 1.4.2 Operadores de Atribuição

Usados para Armazenar Valores em Variáveis:

|Operador|Significado|Exemplo|Equivalente|
|:-:|:-:|:-:|:-:|
|`=`|Atribuição simples|`a = 5;`|`a = 5;`|
|`+=`|Adição e atribuição|`a += 3;`|`a = a + 3;`|
|`-=`|Subtração e atribuição|`a -= 2;`|`a = a - 2;`|
|`*=`|Multiplicação e atribuição|`a *= 4;`|`a = a * 4;`|
|`/=`|Divisão e atribuição|`a /= 2;`|`a = a / 2;`|
|`%=`|Módulo e atribuição|`a %= 3;`|`a = a % 3;`|
|`++`|Incremento de 1 unidade|`a++;`|`a = a + 1;`|
|`--`|Decremento de 1 unidade|`a--;`|`a = a - 1;`|

## 1.5 Biblioteca Padrão do C

Como visto anteriormente, a biblioteca padrão do C é a `<stdio.h>` (**Standard Input Output**). Ela fornece funções essenciais para realizar tarefas comuns, como a manipulação de entrada e saída (**Input**/**Output**), permitindo que o programa interaja com o usuário.

### 1.5.1 Comandos de Saída (Output)

* O comando `printf()` é usado para exibir dados na tela:

```c
printf("Hello, World!\n");
```
* Exibindo com `printf()` o valor de **Variáveis** e **Contantes** na tela:
```c
int idade = 18;
printf("Parabéns! Você tem %d anos.\n", idade);
```
Para exibir o valor de uma Variável ou Constante, basta usar um **Especificador de Formato** correspondente ao tipo de dado, que é um símbolo precedido pelo caractere `%`.

A tabela abaixo mostra os principais especificadores de formato usados com o `printf()`, de acordo com o tipo de dado.

|  Tipo de Dado   | Especificador de Formato |       Exemplo de Uso       |
| :-------------: | :----------------------: | :------------------------: |
|     `char`      |           `%c`           | `printf("%c", caractere);` |
| `unsigned char` |           `%c`           | `printf("%c", caractere);` |
|      `int`      |           `%d`           |  `printf("%d", numero);`   |
| `unsigned int`  |           `%u`           |  `printf("%u", numero);`   |
|   `short int`   |          `%hd`           |  `printf("%hd", numero);`  |
|     `long`      |          `%ld`           |  `printf("%ld", numero);`  |
| `unsigned long` |          `%lu`           |  `printf("%lu", numero);`  |
|     `float`     |           `%f`           |  `printf("%f", numero);`   |
|    `double`     |          `%lf`           |  `printf("%lf", numero);`  |
|  `long double`  |          `%Lf`           |  `printf("%Lf", numero);`  |

### 1.5.2 Comandos de Entrada (Input)

O comando `scanf()` é utilizado para capturar dados do usuário:
```c
scanf("%d", &idade);
```
Note que no `scanf()` é necessário passar o **Endereço de Memória** da variável - usando o operador `&` -, para que o valor lido seja armazenado corretamente na Memória. Além disso, deve-se usar um **Especificador de Formato** adequado ao tipo de dado que estamos lendo, como mostrado na tabela anterior.

## 1.6 Bônus: Boas Práticas de Programação

**Boas práticas de programação** são um conjunto de técnicas e abordagens que visam melhorar a qualidade, a legibilidade e a manutenção do código, garantindo que ele seja eficiente, compreensível e fácil de modificar.

### 1.6.1 Bons Comentários

Comentários são essenciais para **Documentar** o código e torná-lo mais **Compreensível**. Eles ajudam outros programadores - ou você no futuro - a entender a lógica do código sem precisar analisá-lo linha por linha.
```c
// Comentário de linha: usado para descrever uma linha do código
/* Comentário de bloco: usado para descrever seções do código */

```
Porém, evite comentários óbvios ou redundantes.

### 1.6.2 Nome das Variáveis

Escolher **Nomes Claros** e **Descritivos** para as variáveis é fundamental. Isso ajuda na leitura do código e torna a manutenção mais fácil. Evite abreviações que possam gerar confusão.
```c
float salarioMensal;  // Usando camelCase para separação de palavras
int idade_usuario;     // Usando snake_case para separação de palavras
```
Para variáveis compostas, use convenções como `camelCase` ou `snake_case`, conforme o **padrão adotado pelo projeto**.

### 1.6.3 Indentacão

Uma boa **Indentação** é crucial para a **legibilidade do código**. A indentação correta facilita a visualização da estrutura de **controle e hierarquia**, tornando o **código mais organizado**.
```c
if (idade >= 18) {
    printf("Você é maior de idade.\n");
}
```

### 1.6.4 Consistência no Uso de Estilo

Manter um **estilo de codificação consistente** ajuda a evitar confusão e torna o código mais fácil de seguir. Ou seja, faça **uso consistente de maiúsculas e minúsculas**, **formatação** de funções, loop's, condicionais e blocos de código.

* **Evite Programar assim:**
```c
int SOMA(int X, int y) {  // Função e Variáveis com nomes inconsistente
	int Resultado;
    Resultado = X + y;    // Uso inconsistente de maiúsculas
	return Resultado;     
}
```
* **Programe assim:**
```c
int soma(int x, int y) { 
	int resultado; 
	resultado = x + y; 
	return resultado; 
}
```
### 1.6.5 Evitar Código Duplicado

Evite duplicação de código, o que torna o programa mais difícil de manter e **aumentar as chances de erros**. Utilize **funções** para **agrupar trechos de código que se repetem**.

* **Evite Programar assim:**
```c
// Exemplo de duplicação de código
if (x > 0) {
    // Código
}
if (y > 0) {
    // Código
}
```
* **Programe assim:**
```c
// Refatoração para evitar duplicação
void verificarValor(int z) {
    if (z > 0) {
        // Código
    }
}
```
### 1.6.6 Evitar Hardcoding

**Evite usar valores fixos diretamente no código** (**hardcoding**). Em vez disso, **use variáveis** **ou constantes** nomeadas para melhorar a flexibilidade e clareza.

* **Evite Programar assim:**
```c
// Evite isso:
#include <stdio.h>
int main() {
    int temperatura = 25;
    if (temperatura > 38) { // Uso de HardCoding
        printf("Está quente!\n");
    } else {
        printf("Não está quente.\n");
    }
    return 0;
}
```
* **Programe assim:**
```c
#include <stdio.h>
#define TEMPERATURA_MAX 38
int main() {
    int temperatura = 25;
    if (temperatura > TEMPERATURA_MAX) { // Uso de uma Constante
        printf("Está quente!\n");
    } else {
        printf("Não está quente.\n");
    }
    return 0;
}
```
