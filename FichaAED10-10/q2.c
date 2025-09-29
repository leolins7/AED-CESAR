#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;

}Aluno;

int main (){

    Aluno alunos [5];
    float media;
    for (int i = 0; i < 5; i++){
        printf ("Informe o nome, matricula e nota do aluno");
        scanf ("%s %d %f", alunos->nome, &alunos->matricula, &alunos->nota);
        media += alunos->nota;
    }

    printf ("A media das notas eh: %2.f", media);



    return 0;
}