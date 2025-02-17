## 5.0 Definição de Strings em C

Em C, uma **string** é representada como um **array de caracteres**, terminando sempre com o **caractere especial** `\0`. Esse caractere indica onde a string termina na memória.

Observe abaixo um **exemplo visual** de uma string em C:


| **Valor**  |  L  |  I  |  N  |  U  |  X  | `\0` |
| :--------: | :-: | :-: | :-: | :-: | :-: | :--: |
| **Índice** |  0  |  1  |  2  |  3  |  4  |  5   |

Cada caractere da string ocupa uma posição no array, e os índices funcionam como **endereços** que permitem acessar cada caractere individualmente.

Note que, embora a palavra **"LINUX"** tenha **5** letras, a string precisou de **6** posições na memória. Isso acontece pois, em C,  como dito anteriormente, toda string deve terminar com o caractere especial **`\0`**, que sinaliza o fim da sequência de caracteres.

## 5.1 Declaração de uma String em C

Para declarar uma **String** em C, utilizamos a mesma sintaxe de declaração de um **Array** comum, pois em C, uma string nada mais é do que um **conjunto de caracteres armazenados sequencialmente na memória**, finalizado pelo caractere especial `\0` (nulo).

Por exemplo, para declarar a string apresentado anteriormente, a sintaxe de declaração é:
```c
char string[6];
```

## 5.2 Atribuindo Valores à String

Assim como nos arrays, existem duas formas de atribuir valores a uma string: **na declaração** ou **posteriormente**.

*  **Atribuindo Valores na Declaração**

Podemos inicializar a string diretamente ao declará-la:
```c
char nome[] = "Linux";
```
O compilador calcula automaticamente o tamanho necessário, adicionando o `\0` ao final. Essa string ocupa **6 espaços na memória**: 5 para os caracteres e 1 para o terminador.

Outra forma equivalente seria:
```c
char nome[] = {'L', 'i', 'n', 'u', 'x', '\0'};
```
*  **Atribuindo Valores Posteriormente**

Também podemos declarar a string e atribuir valores a cada posição manualmente:
```c
char nome[6];

nome[0] = 'L';
nome[1] = 'i';
nome[2] = 'n';
nome[3] = 'u';
nome[4] = 'x';
nome[5] = '\0'; // Sempre necessário para indicar o fim da string
```

## 5.3 Acessando Valores de uma String

Podemos acessar caracteres individuais de uma string da mesma forma que em um array, utilizando o índice:
```c
char nome[] = "Linux";

printf("O primeiro caractere é: %c\n", nome[0]); // L
printf("O segundo caractere é: %c\n", nome[1]);  // i
printf("O terceiro caractere é: %c\n", nome[2]); // n
```
Essa abordagem permite manipular cada caractere separadamente, como em operações de modificação ou busca dentro da string.

## 5.4 Entradas e Saídas com Strings

### 5.4.1 Recebendo Strings do Usuário

Diferente de variáveis numéricas, a leitura de **strings** exige atenção especial. O uso de `scanf` para capturar strings pode causar problemas, pois ele **lê apenas até o primeiro espaço**, ignorando o restante da entrada.

* **Usando `scanf()`**

Se a string não contiver espaços, podemos usar `scanf()` normalmente:
```c
char str[20];

scanf("%s", str);  
```
* **Usando `gets()`**

A função `gets()` permite ler frases inteiras, incluindo espaços, mas **não é segura**, pois pode causar estouro de buffer.
```c
char str[50];  

gets(str);  // Não recomendado!  
```
* **Usando `fgets()`**

A função `fgets` é a forma mais segura de ler strings, pois permite limitar o número de caracteres capturados:
```c
char str[50];  

fgets(str, 50, stdin);  
```

### 5.4.2 Exibindo Strings na Tela

Após armazenar a string, podemos exibi-la com `printf()` ou `puts()`:
* **Usando `printf()`**
```c
char mensagem[] = "Olá, mundo!";

printf("%s", mensagem)
```
* **Usando `puts()`**
```c
char mensagem[] = "Olá, mundo!";

puts(mensagem);
```


## 5.5 Biblioteca `string.h`

A biblioteca `<string.h>` fornece funções úteis para trabalhar com strings, iremos estudar algumas a seguir.

### 5.5.1 Calcula o tamanho da string - `strlen()`

A função `strlen()` retorna o número de caracteres em uma string **(sem contar o `\0` final)**.
```c
char nome[] = "Ubuntu"; 

int tamanho = strlen(nome); // 7
```
### 5.5.2 Copia uma string para outra - `strcpy()`

A função `strcpy()` copia o conteúdo de uma string para outra.
```c
char origem[] = "C é incrível!"; 
char destino[20]; 

strcpy(destino, origem); // Copia "C é incrível!" para destino
```
**Cuidado!** Se `destino` não for grande o suficiente, ocorrerá um **estouro de buffer**.

### 5.5.3 Concatena duas strings - `strncat()`

A função `strcat()` adiciona uma string ao final de outra.

```c
char saudacao[30] = "Olá, "; 
char nome[] = "Mariana!"; 

strcat(saudacao, nome); // Adiciona "Mariana!" ao final de "Olá, "
```
**Evite estouros!** O tamanho da string de destino deve ser grande o suficiente.

### 5.5.4 Compara duas strings - `strcmp()`

A função `strcmp` compara duas strings **caractere por caractere**:

- Retorna `0`: Se as strings forem **iguais**
- Retorna um valor **negativo**: Se a primeira string for **menor** que a segunda
- Retorna  um valor **positivo**: Se a primeira string for **maior** que a segunda

```c
char str1[] = "Linux"; 
char str2[] = "Windows";

int resposta = strcmp(str1, str2);
```
