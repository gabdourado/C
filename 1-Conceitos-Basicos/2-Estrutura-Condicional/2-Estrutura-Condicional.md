## 2.0 Estrutura Condicional em C

As **Estruturas Condicionais** permitem que o **programa tome decisões baseadas em condições especificadas**. Elas são fundamentais para **controlar o fluxo** do programa dependendo do resultado de expressões com **Operadores Relacionais e Lógicos**.

## 2.1 Operadores Relacionais e Lógicos

Os **Operadores Relacionais** são usados para comparar dois valores e retornam um valor booleano (`verdadeiro` ou `falso`). 

| **Operador** | **Descrição**  | **Exemplo** |    **Resultado**     |
| :----------: | :------------: | :---------: | :------------------: |
|     `>`      |   Maior que    |   `5 > 3`   | Verdadeiro (`true`)  |
|     `<`      |   Menor que    |   `4 > 2`   |   False (`false`)    |
|     `>=`     | Maior ou igual |  `5 >= 5`   | Verdadeiro (`true`)  |
|     `<=`     | Menor ou igual |  `3 <= 2`   |   Falso (`false`)    |
|     `==`     |     Igual      |  `5 == 5`   | Verdadeiro (`false`) |
|     `!=`     |   Diferente    |  `5 != 5`   |   Falso (`false`)    |

Os **Operadores Lógicos** são usados para combinar ou inverter condições, retornando também um valor booleano. Eles ajudam a construir expressões mais complexas, onde é necessário verificar múltiplas condições ao mesmo tempo.

| **Operador** |                           **Descrição**                            |
| :----------: | :----------------------------------------------------------------: |
|     `&&`     | AND -  Será `true`somente se ambas as condições forem verdadeiras. |
|    \| \|     | OR - Será `true` se ao menos uma das condições forem verdadeiras.  |
|     `!`      |            NOT - Inverte o valor lógico de uma condição            |

Em **C**, os Operadores Relacionais e Lógicos **não retornam valores booleanos**, mas inteiros, onde `1` representa verdadeiro e `0` representa falso. Assim, ao usar esses operadores, o resultado será sempre um valor inteiro (`0` ou `1`), em vez de um valor booleano.

## 2.3 Estrutura `if`

A Estrutura `if` permite **executar um bloco de código** apenas se a **condição fornecida for verdadeira**. Caso contrário, o bloco de código é ignorado.

Observe o seguinte trecho de código e determine a saída:
```c
int idade = 20;

if (idade >= 18) {
    printf("Você é maior de idade.\n");
}
```
De fato, a **variável** `idade` é maior ou igual a `18`. Assim, a mensagem **será exibida na tela**.

## 2.4 Estrutura `if-else`

O `if-else` permite que o programa execute um bloco de código se a condição for verdadeira e outro bloco se for falsa.

Observe o seguinte trecho de código e determine a saída:
```c
int idade = 10;

if (idade >= 18) {
    printf("Você é maior de idade.\n");
} else {
    printf("Você é menor de idade.\n");
}
```
Nesse caso, a **variável** `idade` **não** é maior ou igual a `18`. Dessa forma, o bloco `else` será executado e a mensagem "Você é menor de idade." será **será exibida na tela**.

## 2.5 Estrutura `else-if`

O `else-if` permite verificar várias condições. Se a condição do `if` não for verdadeira, ele passa para a próxima condição no `else-if`.

Observe o seguinte trecho de código e determine a saída:
```c
int nota = 7;

if (nota >= 9) {
    printf("Aprovado com Distinção!\n");
} else if (nota >= 7) {
    printf("Aprovado!\n");
} else {
    printf("Reprovado.\n");
}
```
Aqui, a **variável** `nota` **não** é maior ou igual a `9`, então seguimos para a próxima linha, o `else-if`. Opa! A variável  **variável** `nota` é maior ou igual a `7`, dessa forma, o bloco `else-if` será executado e a mensagem "Aprovado!" será **será exibida na tela**.

## 2.6 Usando os Operadores Relacionais e Lógicos  

### 2.6.1 Usando o Operador AND `&&`

Observe o seguinte trecho de código e determine a saída:
```c
int idade = 30;

if (idade >= 18 && idade <= 65) {
    printf("Você está em idade produtiva.\n");
}
```
De fato, a **variável** `idade` é maior ou igual a `18` e também é menor ou igual `65`, assim, por se tratar do operador `&&` (AND), a  mensagem **será exibida na tela**.

### 2.6.2 Usando o Operador OR `||`

Observe o seguinte trecho de código e determine a saída:
```c
int idade = 12;

if (idade < 18 || idade > 65) {
    printf("Você está fora da faixa etária produtiva.\n");

```
 A **variável** `idade` é menor que `18` mas, não maior que é `65`. Porém, por se tratar da operação `||` (OR), como uma das condições é verdadeira, então a mensagem **será exibida na tela**.

### 2.6.3 Usando o Operador NOT `!`

Observe o seguinte trecho de código e determine a saída:
```c
int idade = 12;

if (!(idade < 18)) {
	printf("Você é maior de idade.\n");
}
```
 Note que a **variável** `idade` é menor que `18` o que tornaria a condição verdadeira, porém, com o  uso do operador `!` (NOT), a condição se torna falsa a mensagem **não será exibida na tela**.

## 2.7 Estrutura `switch-case`

O `switch-case` é uma alternativa para **múltiplas condições** quando queremos **testar a mesma variável com diferentes valores possíveis**. Ele é mais eficiente do que usar várias instruções `else-if`.
```c
int dia = 3;

switch (dia) {
    case 1:
        printf("Domingo\n");
        break;
    case 2:
        printf("Segunda-feira\n");
        break;
    case 3:
        printf("Terça-feira\n");
        break;
    default:
        printf("Dia inválido\n");
}
```
O `switch` compara uma variável com diferentes valores de `case` e executa o bloco correspondente. O `break` interrompe a execução para evitar o "fall-through", enquanto o `default` trata casos não previstos, executando um código padrão quando nenhum `case` corresponde.

## 2.8 Bônus: Estilo Ninja - Operador Ternário

O Operador Ternário é uma forma compacta de escrever um `if-else` simples. Ele tem a seguinte sintaxe:
```c
condição ? valor_se_verdadeiro : valor_se_falso;
```
Veja como ficaria o do Tópico `2.4` com o Operador Ternário:
```c
int idade = 20;

printf("Você é %s de idade.\n", (idade >= 18) ? "maior" : "menor");
```
