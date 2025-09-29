#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa
{
    char nome[50];
    int idade;
    float altura;

}Pessoa;

int main (){

    Pessoa Usuario;

    printf ("Informe o nome, idade e altura do usuario: \n");

    scanf ("%s %d %f", Usuario.nome, &Usuario.idade, &Usuario.altura);

    printf ("Nome %s\n", Usuario.nome);

    printf ("Idade %d\n", Usuario.idade);

    printf ("Altura - %2.f", Usuario.altura);
        
    
    
    return 0;
}
