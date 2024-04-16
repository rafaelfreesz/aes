## Exercício

1) Para cada estrutura abaixo, implemente os métodos contido(K,L), inserir(K,L) e remover(K,L) e
   verifique as complexidades de cada método. No caso de filas e pilhas, o remover(K,L) não terá o
   argumento K, visto que filas e pilhas removem sempre quem está na extremidade.

   **c)** Pilha com lista simplesmente encadeada.

**Solução:** 

- Estrutura:

![Logo do R](./docs/uml_pilha.jpg)

- Método _inserir(K,L)_: Como não há demanda do do médodo _contido(K,L)_, _inserir(K,L)_ se torna **O(1)**.

```
void Pilha::inserir(int k, Pilha *l) {
    No *novoNo = new No();
    novoNo->valor = k;

    if (isVazia(l)) {
        l->ultimo = novoNo;
    } else {
        novoNo->proximo = l->primeiro;
    }

    l->primeiro = novoNo;
}
```

- Método _remover(K,L)_: Como não há demanda do do médodo _contido(K,L)_, _remover(K,L)_ se torna **O(1)**.

```
No *Pilha::remover(Pilha *l) {
    if (!isVazia(l)) {
        No *no = l->primeiro;

        if (l->primeiro == l->ultimo) {
            l->primeiro = l->ultimo = nullptr;
        } else {
            l->primeiro = l->primeiro->proximo;
        }

        return no;
    } else {
        cout << "A pilha está vazia" << endl;
        return nullptr;
    }
}
``` 