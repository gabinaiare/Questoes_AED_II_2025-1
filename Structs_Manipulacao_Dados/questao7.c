#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct Alunos
{
    char nome[10];
    int matricula;
    float media;
};

typedef struct Alunos alunos;
int main(){
    setlocale(LC_ALL, "Portuguese");
    int n;

    printf("Quantos alunos deseja cadastrar? "); //Pegando a quantidade de alunos para cadastro
    scanf("%i", &n);

    alunos aluno[n];

    for (int i = 0; i < n; i++){ //Coletando suas informações
        getchar();

        printf("Informe o nome: ");
        scanf("%[^\n]", aluno[i].nome);

        printf("Informe a matrícula: ");
        scanf("%i", &aluno[i].matricula);

        printf("Informe a média: ");
        scanf("%f", &aluno[i].media);

        printf("\n");
    }

    printf("\n===== Alunos Cadastrados =====\n"); //Exibindo os dados, junto com as informações de aprovação
    for (int i = 0; i < n; i++){
        printf("Nome: %s\n", aluno[i].nome);
        printf("Matrícula: %i\n", aluno[i].matricula);
        printf("Média: %.2f\n", aluno[i].media);

        if (aluno[i].media >= 7){
            printf("Aluno aprovado!\n\n");
        }
        else{
            printf("Aluno reprovado!\n\n");
        }      
    } 
return 0;
}