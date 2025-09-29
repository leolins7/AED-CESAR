#include <stdio.h>
#include <stdlib.h>

typedef struct Carro{
    char modelo[30];
    int ano;
    float preco;
}Carro;

int main (){
    Carro *ptr_carro;

    ptr_carro = (Carro *)malloc (sizeof(Carro));
    if (ptr_carro == NULL){
        printf ("Erro ao alocar memoria. \n");
        return 1;
    }
    printf ("Informe o modelo, ano e preco do carro: ");

    scanf ("%s %d %f", ptr_carro->modelo, &ptr_carro->ano, &ptr_carro->preco);

    printf ("Modelo: %s \n Ano: %d \n Preco: %2.f\n ", ptr_carro->modelo, ptr_carro->ano, ptr_carro->preco);
    
    free (ptr_carro);
    return 0;
    
}