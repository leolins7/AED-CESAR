#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
} Node;

// Função para criar um novo nó
Node* criarNode(int valor) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    novoNode->valor = valor;
    novoNode->esquerda = NULL;
    novoNode->direita = NULL;
    return novoNode;
}

// Função para inserir um valor na ABB
Node* inserir(Node* raiz, int valor) {
    if (raiz == NULL) {
        return criarNode(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

// Função para encontrar o nó com o menor valor na subárvore direita
Node* encontrarMin(Node* node) {
    Node* atual = node;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

// Função para remover um nó da ABB
Node* remover(Node* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        // Caso 1: Nó com 0 ou 1 filho
        if (raiz->esquerda == NULL) {
            Node* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            Node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Caso 2: Nó com 2 filhos
        Node* temp = encontrarMin(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

// Função para percorrer a árvore em ordem (in-order)
void percorrerEmOrdem(Node* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        percorrerEmOrdem(raiz->direita);
    }
}

// Função principal
int main() {
    Node* raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int i;
    int num_valores = sizeof(valores) / sizeof(valores[0]);

    // 1) Inserção dos valores
    printf("1) Inserindo os valores: ");
    for (i = 0; i < num_valores; i++) {
        raiz = inserir(raiz, valores[i]);
        printf("%d ", valores[i]);
    }
    printf("\n");

    // 1c) Mostrando a árvore em ordem crescente
    printf("   c) Arvore em ordem crescente: ");
    percorrerEmOrdem(raiz);
    printf("\n\n");

    // 2) Remocao de nos
    // a) Removendo o no 20 (sem filhos)
    printf("2a) Removendo o no 20...\n");
    raiz = remover(raiz, 20);
    printf("    Arvore apos remocao de 20: ");
    percorrerEmOrdem(raiz);
    printf("\n\n");

    // b) Removendo o no 30 (com um filho)
    printf("2b) Removendo o no 30...\n");
    raiz = remover(raiz, 30);
    printf("    Arvore apos remocao de 30: ");
    percorrerEmOrdem(raiz);
    printf("\n\n");

    // c) Removendo o no 50 (com dois filhos)
    printf("2c) Removendo o no 50...\n");
    raiz = remover(raiz, 50);
    printf("    Arvore apos remocao de 50: ");
    percorrerEmOrdem(raiz);
    printf("\n\n");

    // e) Mostrando a arvore em ordem após todas as remoções
    printf("2e) Arvore final em ordem: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    return 0;
}