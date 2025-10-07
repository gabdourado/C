## 4.0 Definição de Arrays

Um **Array** - ou vetor - é uma Estrutura de Dados que armazena **múltiplos valores de mesmo tipo** em uma única variável. Ele permite que você armazene uma coleção de dados de maneira contígua (lado à lado), acessando cada valor por um **índice**.

Observe abaixo um **exemplo visual** de um array de `5` números inteiros:


| **Valor**  | 10  | 20  | 30  | 40  | 50  |
| :--------: | :-: | :-: | :-: | :-: | :-: |
| **Índice** |  0  |  1  |  2  |  3  |  4  |

Note que cada valor possui um índice, indo de `0` até `4`, pois num array, os índices vão sempre de `0` até `n-1`, onde `n` é o tamanho do array. 

O índice é como um **endereço** que nos permite acessar cada valor.

## 4.1 Declaração de um Array

Para declarar um Array em C, você deve **especificar o tipo** de dados que ele armazenará e o **número de elementos** entre colchetes.

Por exemplo, para declarar o array apresentado anteriormente, a sintaxe de declaração é:
```C
int array[5];
```
## 4.2 Atribuindo Valores ao Array
Em C, os valores podem ser atribuídos a um **array** de duas maneiras: durante a **declaração** do array ou posteriormente, usando um **índice**. Vamos entender cada uma dessas formas.

* **Atribuindo Valores na Declaração**

Quando você declara um array, é possível já atribuir valores diretamente a ele. Essa abordagem é útil quando você conhece os valores que quer armazenar no array desde o início.
```c
int array[5] = {10, 20, 30, 40, 50};
```
* **Atribuindo Valores Posteriormente**

Você também pode atribuir valores a cada elemento do array após a declaração, usando o índice correspondente.
```c
int array[5];

array[0] = 10;
```
## 4.3 Acessando Valores do Array
Para acessar os valores de um **array**, você utiliza o índice de cada elemento.

Veja o código abaixo para exibir os três primeiros elementos de um array:
```c
int array[5] = {10, 20, 30, 40, 50};

printf("O valor no índice 0 é: %d\n", array[0]);  // 10
printf("O valor no índice 1 é: %d\n", array[1]);  // 20
printf("O valor no índice 2 é: %d\n", array[2]);  // 30

```
## 4.4 Loop's e Arrays

Quando trabalhamos com **arrays**, muitas vezes precisamos percorrer todos os seus elementos para **exibir valores**, **modificá-los** ou **realizar cálculos**. Para isso, podemos utilizar **loop's**, como `for`, para facilitar essa manipulação.

Por exemplo, o código a seguir **preenche** um array com `5` números inteiros:
```c
int array[5];

for (int i = 0; i < 5; i++) {
	scanf("%d", &array[i]);
}
```
Para **exibir** os elementos de um array de tamanho `5`, basta seguir a lógica do código anterior, veja:
```c
int array[5] = {10, 20, 30, 40, 50};

printf("Elementos do Vetor:\n")

for (int i = 0; i < 5; i++) {
	printf("%d ", array[i]);
}
```
## 4.5 Definição de Matrizes

Uma **Matriz** é uma **Estrutura de Dados bidimensional**, ou seja, uma coleção de valores de mesmo tipo, organizados em **linhas** e **colunas**. Onde cada elemento pode ser acessado por meio dos índices da linha e da coluna correspondentes.

Observe abaixo um **exemplo visual** de uma matriz de `2` linhas e `3` colunas formada por números inteiros:


|             | **Coluna 0** | **Coluna 1** | **Coluna 2** |
| :---------: | :----------: | :----------: | :----------: |
| **Linha 0** |      10      |      20      |      30      |
| **Linha 1** |      40      |      50      |      60      |

Note que cada valor na **matriz** possui dois índices, um para a **linha** - indo de `0` até `1` - e outro para a **coluna** - indo de `0` até `2` - , pois em uma matriz, as linhas são numeradas de `0` até `m-1`, e as colunas de `0` até `n-1`, onde `m` é o número total de linhas e `n` é o número total de colunas.

Os índices funcionam como **endereços** que nos permitem acessar cada valor dentro da matriz, identificando sua posição exata com `[linha][coluna]`.

### 4.6 Declaração de uma Matriz

Para declarar uma **matriz** em C, especificamos o **tipo de dado** e o **número de linhas e colunas** entre colchetes:

Por exemplo, para declarar a matriz apresentada anteriormente, a sintaxe de declaração é:
```c
int matriz[2][3];
```
### 4.7 Atribuindo Valores à Matriz

Os valores podem ser atribuídos à matriz **diretamente na declaração** ou **individualmente**, usando os índices:

* **Atribuindo Valores na Declaração**

Quando você declara uma matriz, é possível já atribuir valores diretamente a ela. Essa abordagem é útil quando você conhece os valores que quer armazenar na matriz desde o início.
```c
int matriz[2][3] = {
    {10, 20, 30}, 
    {40, 50, 60}
};
```
* **Atribuindo Valores Posteriormente**

Você também pode atribuir valores a cada elemento da matriz após a declaração, usando o índice correspondente.
```c
int matriz[2][3];

matriz[0][0] = 10;
```
### 4.8 Acessando Valores da Matriz
Para acessar valores dentro da matriz, usamos os índices `[linha][coluna]`:
```c
int matriz[2][3] = {
    {10, 20, 30}, 
    {40, 50, 60}
};

printf("O valor da posição [0][1] é: %d\n", matriz[0][1]);  // 20
printf("O valor da posição [1][2] é: %d\n", matriz[1][2]);  // 60
```
## 4.9 Loop's e Matrizes

Assim como ocorre nos Arrays, quando trabalhamos com **matrizes**, precisamos percorrer todos os seus elementos para **exibir valores**, **modificá-los** ou **realizar cálculos**. 

Com **matrizes**, temos **duas dimensões**, ou seja, precisamos percorrer **linhas** e **colunas**. Para isso, utilizamos **dois loop's aninhados**:

- O primeiro (`for` externo) percorre as **linhas**.
- O segundo (`for` interno) percorre as **colunas**.

Por exemplo, o código a seguir **preenche** uma matriz de `2` linhas e `3` colunas: 
```c
int matriz[2][3];

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        scanf("%d", &matriz[i][j]);
    }
}
```
E o código a seguir **imprime** os elementos de uma matriz de `2` linhas e `3` colunas: 
```c
int matriz[2][3] = {
    {10, 20, 30},
    {40, 50, 60}
};

printf("Elementos da Matriz:\n");

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d ", matriz[i][j]);
    }
    printf("\n");
}
```
