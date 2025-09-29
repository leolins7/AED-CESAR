#include <stdio.h>
#include <stdlib.h>


typedef struct Product {
    char nome[50];
    int codigo;
    float preco;
}Product;

void exibirProduto (Product p){

    printf ("%s\n", p.nome);
    printf ("%d\n", p.codigo);
    printf ("R$%2.f\n", p.preco);

}

int main (){

    Product produto;
    printf ("Informe o nome, codigo e preco do produto \n");
    scanf ("%s %d %f", produto.nome, &produto.codigo, &produto.preco);
    exibirProduto (produto);

    return 0;
}