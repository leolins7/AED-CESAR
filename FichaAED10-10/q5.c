#include <stdio.h>
#include <stdlib.h>

typedef struct Funcionarios {
    char nome[50];
    char cargo[30];
    float salario;
}Funcionarios;

int main (){
    int N;
    Funcionarios *funcionarios;
    printf ("Informe quantos funcionarios voce deseja cadastrar: \n");
    scanf ("%d", &N);
    funcionarios = (Funcionarios *)malloc(sizeof(Funcionarios) * N);
    for (int i = 0; i < N; i++){
    printf ("Informe agora nome, cargo e salario do funcionario: \n ");
    scanf ("%s %s %f", funcionarios[i].nome, funcionarios[i].cargo, &funcionarios[i].salario);
    }

    for (int i = 0; i < N; i++){
    printf("%s %s %2.f", funcionarios[i].nome, funcionarios[i].cargo, funcionarios[i].salario);
    }

    free (funcionarios);

    return 0;


}