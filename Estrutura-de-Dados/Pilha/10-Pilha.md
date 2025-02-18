## 10.0 Pilha com Lista Encadeada

Uma das **Estruturas de Dados** mais simples e intuitivas é a **Pilha**. O conceito principal dessa estrutura é que **todas as operações de inserção e remoção acontecem no topo**.

Uma boa analogia é uma **pilha de pratos**:

- Quando colocamos um novo prato, ele fica no topo da pilha.
- Para pegar um prato, sempre retiramos o que está no topo primeiro.

Esse comportamento segue o princípio **LIFO** (*Last In, First Out*), que significa que **o último elemento inserido é o primeiro a ser removido**.

Na implementação com **Lista Encadeada**, a pilha é representada por um ponteiro chamado **Topo**, que aponta para o elemento mais recentemente inserido.

## 10.1 Inserção e Remoção na Pilha

Como dito anteriormente, as operações de Inserção/Empilhar (*Push*) e Remoção/Desempilhar (*Pop*), seguem o princípio FIFO (L*ast In, First Out*), vejamos como isso ocorre na prática.
### 10.1.1 Push (Empilhar)

Adiciona um novo elemento no topo da pilha.

1. Criamos um novo nó.
2. O ponteiro do novo nó aponta para o nó que era o topo anterior.
3. Atualizamos o **Topo** para esse novo nó.

Se inserirmos os valores `10`, `20` e `30` usando `push()`, a estrutura da pilha será:

| **Endereço** | **Valor** | **Próximo** |
| ------------ | --------- | ----------- |
| `0x001`      | `30`      | `0x002`     |
| `0x002`      | `20`      | `0x003`     |
| `0x003`      | `10`      | `NULL`      |

### 10.1.2 Pop (Desempilhar)

Remove o elemento do topo da pilha.

1. O nó do topo é removido.
2. O ponteiro **Topo** passa a apontar para o próximo nó.

Agora, se chamarmos `pop()`, o `30` será removido, e a pilha ficará assim:

|**Endereço**|**Valor**|**Próximo**|
|---|---|---|
|`0x002`|`20`|`0x003`|
|`0x003`|`10`|`NULL`|

## 10.2 Vantagem das Pilhas: Eficiência nas Operações `Push()` e `Pop()`

Uma das grandes vantagens das pilhas é a **eficiência nas operações de inserção** e **remoção** de elementos. Devido ao seu seu funcionamento baseado no princípio LIFO (_Last In, First Out_), , as operações `push()` e `pop()` são executadas em **tempo constante**, ou seja, $O(1)$.

Isso significa que, independentemente do número de elementos na pilha, o tempo necessário para adicionar ou remover um item é **sempre o mesmo**. Esse desempenho é possível porque as operações envolvem apenas a **manipulação de ponteiros** ou **índices**, sem a necessidade de reorganizar os outros elementos da estrutura.

## 10.3 Desvantagem das Pilhas: Acesso Restrito

Uma das limitações das pilhas, em comparação com outras estruturas de dados, é o **acesso restrito aos seus elementos**. Devido ao seu funcionamento, a pilha só permite que o **último elemento inserido** seja acessado diretamente.

Isso significa que **não é possível acessar ou modificar um elemento no meio da pilha** sem antes remover os elementos que estão acima dele. Ou seja, para acessar um item específico, é necessário realizar a operação de `pop()` nos elementos que estão acima dele, um a um, até que o elemento desejado seja alcançado.
