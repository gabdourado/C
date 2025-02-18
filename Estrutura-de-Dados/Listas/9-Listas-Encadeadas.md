## 9.0 Definição de Listas Encadeadas

Uma **Lista Simplesmente Encadeada** é uma Estrutura de Dados **Dinâmica** composta por nós, onde cada nó contém dois elementos principais:

1. **Dado**: Informação armazenada.
2. **Ponteiro**: Referência para o próximo nó da lista.

A principal característica dessa estrutura é que os nós **não** precisam estar **armazenados em posições consecutivas na memória**. Em vez disso, cada nó aponta explicitamente para o próximo, formando uma cadeia de elementos.

O primeiro nó da lista é chamado de **Cabeça (Head)** e o último nó aponta para `NULL`, indicando o fim da lista.
## 9.1 Tamanho Dinâmico

As **Estruturas de Dados** estudadas até agora, como **Arrays** e **Matrizes** armazenam elementos de forma **contígua** na memória, o que pode limitar a escalabilidade devido à necessidade de realocação para expansão, impactando o desempenho.

Observe abaixo um **exemplo visual** de um Array de `5` números inteiros:

| **Endereço** | **Valor** |
| ------------ | --------- |
| `0x001`      | 10        |
| `0x002`      | 20        |
| `0x003`      | 30        |
| `0x004`      | 40        |

Em contraste, as **Listas Encadeadas não exigem armazenamento Contíguo**. Isso significa que elas podem crescer e diminuir dinamicamente conforme a necessidade, o que torna o uso da memória mais eficiente e facilita operações como inserções e remoções.

Observe abaixo um **exemplo visual** de uma Lista Encadeada de `5` números inteiros:

| **Endereço** | **Valor** | **Próximo** |
| :----------: | :-------: | :---------: |
|   `0x001`    |    10     |   `0x006`   |
|   `0x002`    |           |             |
|   `0x003`    |           |             |
|   `0x004`    |    40     |    `NULL`   |
|   `0x005`    |           |             |
|   `0x006`    |    20     |   `0x007`   |
|   `0x007`    |    30     |   `0x004`   |

Como podemos ver, a lista não precisa de espaços contíguos. Assim, é fácil aumentar ou diminuir seu tamanho conforme a necessidade, tornando a **Lista Encadeada** muito mais flexível em comparação ao **Array**.
## 9.2 Inserção de um Nó

A **Inserção** de um nó em uma Lista Encadeada pode ser feita de diferentes formas, dependendo de onde o novo nó será colocado. Vamos analisar três casos distintos:
### 9.2.1 Inserção no Início da Lista 

Inserir um nó no início da lista é uma operação simples e eficiente. O novo nó se torna o primeiro nó da lista, e o ponteiro da lista é atualizado para apontar para ele.

1. O novo nó é criado com o valor que queremos inserir.
2. O ponteiro do novo nó é ajustado para apontar para o antigo nó cabeça.
3. O ponteiro da lista é atualizado para apontar para o novo nó, fazendo dele o nó cabeça.

### 9.2.2 Inserção no Meio da Lista

O novo nó precisa ser ajustado para apontar para o nó seguinte ao nó inserido, e o ponteiro do nó anterior ao novo nó deve ser atualizado para apontar para o novo nó.

1. O novo nó é criado com o valor que queremos inserir.
2. Percorra a lista até encontrar o nó após o qual o novo nó será inserido.
3. O ponteiro do novo nó é atualizado para apontar para o nó seguinte ao nó anterior.
4. O ponteiro do nó anterior é atualizado para apontar para o novo nó.

### 9.2.3 Inserção no Final da Lista

Inserir um nó no final da lista exige um pouco mais de trabalho, pois é necessário localizar o último nó (o nó que aponta para `NULL`) e ajustar seu ponteiro para apontar para o novo nó.

1. O novo nó é criado com o valor que queremos inserir.
2. Percorra a lista até encontrar o nó que aponta para `NULL`.
3. O ponteiro do último nó é atualizado para apontar para o novo nó.
4. O ponteiro do novo nó é ajustado para `NULL`, já que ele será o último nó.

Observe o exemplo anterior e  como seria a **inserção** do elemento `50` no final da lista:

* **Lista antes da Inserção**

| **Endereço** | **Valor** | **Próximo** |
| :----------: | :-------: | :---------: |
|   `0x001`    |    10     |   `0x006`   |
|   `0x002`    |           |             |
|   `0x003`    |           |             |
|   `0x004`    |    40     |    `NULL`   |
|   `0x005`    |           |             |
|   `0x006`    |    20     |   `0x007`   |
|   `0x007`    |    30     |   `0x004`   |

* **Lista após a Inserção**

| **Endereço** | **Valor** | **Próximo** |
| :----------: | :-------: | :---------: |
|   `0x001`    |    10     |   `0x006`   |
|   `0x002`    |    50     |   `NULL`    |
|   `0x003`    |           |             |
|   `0x004`    |    40     |   `0x002`   |
|   `0x005`    |           |             |
|   `0x006`    |    20     |   `0x007`   |
|   `0x007`    |    30     |   `0x004`   |

Neste caso, o último nó da lista, com valor `40`, tem seu ponteiro alterado para apontar para o novo nó `50`. O novo nó `50`, por sua vez, aponta para `NULL`, indicando que ele agora é o último nó da lista.

## 9.3 Remoção de um Nó

Na **Remoção** de um nó em uma lista encadeada, devemos considerar os três casos distintos vistos na inserção:

### 9.3.1 Remoção do Nó Cabeça da Lista

A remoção do **nó cabeça** é um caso especial. Quando removemos o nó cabeça, o ponteiro da lista deve ser atualizado para apontar para o próximo nó da lista.

1. O ponteiro da lista é atualizado para apontar para o segundo nó, que agora se torna o novo nó cabeça.
2. O nó removido é desconectado da lista e se torna inacessível.

### 9.3.2 Remoção de um Nó no Meio da Lista

Quando removemos um nó que está **no meio** da lista, precisamos garantir que o nó anterior ao nó removido ainda aponte para o próximo nó do nó removido.

1. Localize o nó a ser removido e o nó anterior a ele.
2. O ponteiro do nó anterior deve ser atualizado para apontar para o nó seguinte ao que será removido.
3. O nó removido é desconectado da lista e se torna inacessível.

### 9.3.3 Remoção do Último Nó da Lista

Quando removemos o **último nó** da lista, devemos realizar os seguintes passos:

1. O nó anterior ao último nó deve ter seu ponteiro ajustado para `NULL`, indicando que ele agora é o último nó da lista.
2. O nó removido, que estava apontando para `NULL`, é desconectado da lista.

Observe como seria a **remoção** do elemento `20` da lista, que está no **meio** da lista:

* **Antes da Remoção**

| **Endereço** | **Valor** | **Próximo** |
| :----------: | :-------: | :---------: |
|   `0x001`    |    10     |   `0x006`   |
|   `0x002`    |    50     |   `NULL`    |
|   `0x003`    |           |             |
|   `0x004`    |    40     |   `0x002`   |
|   `0x005`    |           |             |
|   `0x006`    |    20     |   `0x007`   |
|   `0x007`    |    30     |   `0x004`   |

* **Após a Remoção**

| **Endereço** | **Valor** | **Próximo** |
| :----------: | :-------: | :---------: |
|   `0x001`    |    10     |   `0x007`   |
|   `0x002`    |    50     |   `NULL`    |
|   `0x003`    |           |             |
|   `0x004`    |    40     |   `0x002`   |
|   `0x005`    |           |             |
|   `0x006`    |           |             |
|   `0x007`    |    30     |   `0x004`   |

Para remover o nó com o valor `20`, o ponteiro do nó anterior (que contém o valor `10` e aponta para `0x006`) deve ser alterado para apontar para o nó seguinte a `20`, ou seja, o nó com o valor `30` (endereço `0x007`). Após esse ajuste, o nó com o valor `20` é desconectado e removido da lista, sem a necessidade de mover os outros nós.
