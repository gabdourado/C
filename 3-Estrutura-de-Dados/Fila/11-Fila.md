## 11.0 Fila com Lista Encadeada

O conceito fundamental das Filas está nas operações de **inserção** e **remoção**. Em uma fila convencional - sem prioridade -, toda inserção é feita no final e toda remoção no início.

Uma forma simples de visualizar uma Fila é compará-la a uma fila de clientes em um supermercado:

- Quando um novo cliente chega, ele se posiciona **no final da fila**.
- O atendimento sempre ocorre **do início da fila**, ou seja, o primeiro cliente a chegar será o primeiro a ser atendido e sair.

Esse comportamento segue o princípio **FIFO** (_First In, First Out_), ou seja, o primeiro elemento inserido será o primeiro a ser removido.

Na implementação com **Listas Encadeadas**, a Fila é representada por uma estrutura que mantém dois ponteiros: **Início** e **Fim**. O ponteiro **Início** aponta para o primeiro elemento da fila, enquanto o ponteiro **Fim** aponta para o último elemento.

## 11.1 Inserção e Remoção na Fila

Como dito anteriormente, as operações de Inserção/Enfileirar (*Enqueue*) e Remoção/Desenfileirar (*Dequeue*), seguem o princípio **FIFO** (_First In, First Out_), vejamos como isso ocorre na prática.

### 10.1.1 Enqueue (Enfileirar)

Adiciona um novo elemento no **final** da fila.

1. Criamos um novo nó.
2. O ponteiro do nó que está atualmente no **Fim** da fila passa a apontar para o novo nó.
3. Atualizamos o ponteiro **Fim** para esse novo nó.
4. Se a fila estiver vazia, o ponteiro **Início** também será atualizado para apontar para o novo nó.

Se inserirmos os valores `10`, `20` e `30` usando `enqueue()`, a estrutura da fila será:

| Endereço | Valor | Próximo |
| :------: | :---: | :-----: |
| `0x001`  | `10`  | `0x002` |
| `0x002`  | `20`  | `0x003` |
| `0x003`  | `30`  | `NULL`  |

O ponteiro **Início** aponta para o nó com valor `10`, e o ponteiro **Fim** aponta para o nó com valor `30`.
### 10.1.2 Dequeue (Desenfileirar)

Remove o elemento do **início** da fila.

1. O nó apontado pelo ponteiro **Início** é removido.
2. O ponteiro **Início** passa a apontar para o próximo nó da fila.
3. Se a fila ficar vazia após a remoção, o ponteiro **Fim** também é atualizado para `NULL`.

Agora, se chamarmos `dequeue()`, o `10` será removido, e a fila ficará assim:

| Endereço | Valor | Próximo |
| :------: | :---: | :-----: |
| `0x002`  | `20`  | `0x003` |
| `0x003`  | `30`  | `NULL`  |

O ponteiro **Início** agora aponta para o nó com valor `20`, e o **Fim** continua apontando para `30`.

## 11.2 Vantagem das Pilhas: Eficiência nas Operações `Enqueue()` e `Dequeue()`

Assim como as **Pilhas** - estudadas anteriormente -, uma das principais vantagens das **Filas** é a **eficiência nas operações de inserção e remoção**. Graças ao princípio **FIFO** (_First In, First Out_), as operações `enqueue()` e `dequeue()` são executadas em **tempo constante**, ou seja, $O(1)$.

Isso significa que, independentemente do número de elementos na fila, o tempo necessário para adicionar ou remover um item **permanece o mesmo**. Essa eficiência ocorre porque as operações envolvem apenas a **atualização de ponteiros**, sem necessidade de deslocar os outros elementos da estrutura.


## 10.3 Desvantagem das Filas: Acesso Restrito

As **Filas** possuem **acesso restrito aos elementos**. Seu funcionamento permite acessar diretamente apenas o **primeiro** e o **último** elementos, por meio dos ponteiros **Início** e **Fim**.

Isso significa que **não é possível acessar ou modificar um elemento no meio da fila diretamente**. Para alcançar um item específico, é necessário remover, um a um, todos os elementos que estão antes dele utilizando `dequeue()`, o que pode ser visto como um problema dependendo da aplicação.
