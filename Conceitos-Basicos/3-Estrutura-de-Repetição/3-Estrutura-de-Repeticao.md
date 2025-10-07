## 3.0 Estrutura de Repetição em C

As **Estruturas de Repetição** permitem executar um bloco de código múltiplas vezes, com base em uma condição.

## 3.1 Estrutura `for`

O loop `for` é ideal quando sabemos **quantas vezes** queremos repetir um bloco de código. Ele é composto por **três partes**:
1. **Inicialização**: Atribui um valor inicial à variável de controle (`i`), esta que será responsável pelo número de repetições.
2. **Condição**: Uma expressão relacional que determina se o loop continuará ou será encerrado. Quando for **falsa**, a repetição termina.
3. **Incremento/Decremento**: Modifica a variável de controle (`i`), garantindo que a condição se torne **falsa** em algum momento, evitando um loop infinito.

Observe o seguinte trecho de código e determine a saída:

```c
for (int i = 1; i <= 5; i++) {
    printf("Número: %d\n", i);
}
```
Este código imprime os números de `1` a `5`.

## 3.2 Estrutura `while`

O loop `while` executa um bloco de código **enquanto** uma condição for verdadeira. Neste tipo de estrutura, o **teste condicional ocorre no início**. Isso significa que, se a condição for **falsa logo na primeira verificação**, o bloco de código **nunca será executado**.

Observe o seguinte trecho de código:
```c
int contador = 1;
while (contador <= 5) {
    printf("Contador: %d\n", contador);
    contador++;
}
```
Se `contador` já fosse maior que `5` na primeira verificação, **o bloco interno nem rodaria**. Como `contador` começa em `1`, ele será incrementado a cada iteração até atingir `6`, momento em que a condição se torna falsa e o loop termina.

## 3.3 Estrutura `do-while`

O loop `do-while` é semelhante ao `while`, mas garante que o bloco seja executado **pelo menos uma vez**, pois a verificação da condição acontece depois da primeira execução.
```c
int contador = 1;
do {
    printf("Contador: %d\n", contador);
    contador++;
} while (contador <= 5);
```
Se `contador` já fosse maior que `5`, o loop ainda assim **executaria pelo menos uma vez** antes da verificação da condição. Como `contador` começa em `1`, ele será incrementado a cada iteração até atingir `6`, momento em que a condição se torna falsa e o loop termina.

## 3.4 Controle de Fluxo 

Os comandos `break` e `continue` controlam a execução dos loop's, permitindo interromper ou pular iterações.
### 3.4.1 Usando `break`

O `break` interrompe imediatamente a execução de um loop, saindo dele.

Observe o seguinte trecho de código e determine a saída:
```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        break;  // Para o loop quando i for 5
    }
    printf("%d\n", i);
}
```
Aqui, o loop para quando `i` chega a `5` e não em `10` como seria o normal. Imprimindo os números de `1` até `4`.

### 3.4.2 Usando `continue`

O `continue` faz com que o loop **pule** a iteração atual e vá para a próxima.

```c
for (int i = 1; i <= 5; i++) {
    if (i == 3) {
        continue;  // Pula o número 3
    }
    printf("%d\n", i);
}
```
Neste caso, serão impressos os números de `1` até `5`, porém o número `3` não será impresso.
