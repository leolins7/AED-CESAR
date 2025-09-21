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

// Função para buscar um valor na ABB
Node* buscar(Node* raiz, int valor) {
    // Se a raiz for nula ou o valor for encontrado na raiz, retorna a raiz
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    // Se o valor for maior que a raiz, busca na subárvore direita
    if (valor > raiz->valor) {
        return buscar(raiz->direita, valor);
    }

    // Se o valor for menor que a raiz, busca na subárvore esquerda
    return buscar(raiz->esquerda, valor);
}

// Função principal
int main() {
    Node* raiz = NULL;
    int valores_arvore[] = {50, 30, 70, 20, 40, 60, 80};
    int i;
    int num_valores_arvore = sizeof(valores_arvore) / sizeof(valores_arvore[0]);

    // Construção da árvore
    for (i = 0; i < num_valores_arvore; i++) {
        raiz = inserir(raiz, valores_arvore[i]);
    }

    // Valores a serem buscados
    int valores_busca[] = {60, 25, 40};
    int num_valores_busca = sizeof(valores_busca) / sizeof(valores_busca[0]);

    printf("Iniciando a busca na arvore...\n\n");

    // Realizando a busca e imprimindo o resultado
    for (i = 0; i < num_valores_busca; i++) {
        int valor_atual = valores_busca[i];
        Node* resultado_busca = buscar(raiz, valor_atual);

        if (resultado_busca != NULL) {
            printf("O valor %d foi encontrado na arvore.\n", valor_atual);
        } else {
            printf("O valor %d nao foi encontrado na arvore.\n", valor_atual);
        }
    }

    

    return 0;
}