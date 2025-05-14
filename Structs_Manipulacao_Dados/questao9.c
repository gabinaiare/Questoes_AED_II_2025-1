#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct{
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

void adicionarContato(Contato contatos[], int *total){
    printf("\n--- Adicionar Contato ---\n");

    printf("Nome: ");
    getchar(); // limpar buffer
    fgets(contatos[*total].nome, sizeof(contatos[*total].nome), stdin);
    contatos[*total].nome[strcspn(contatos[*total].nome, "\n")] = 0;

    printf("Telefone: ");
    fgets(contatos[*total].telefone, sizeof(contatos[*total].telefone), stdin);
    contatos[*total].telefone[strcspn(contatos[*total].telefone, "\n")] = 0;

    printf("Email: ");
    fgets(contatos[*total].email, sizeof(contatos[*total].email), stdin);
    contatos[*total].email[strcspn(contatos[*total].email, "\n")] = 0;

    (*total)++;

    printf("Contato adicionado com sucesso!\n");
}

void buscarContato(Contato contatos[], int total){
    char busca[50];
    int encontrado = 0;

    printf("\nDigite o nome para buscar: ");
    getchar(); // limpar buffer
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = 0;

    for(int i = 0; i < total; i++){
        if (strcmp(contatos[i].nome, busca) == 0) {
            printf("\n--- Contato encontrado ---\n");
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Email: %s\n", contatos[i].email);
            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("Contato não encontrado.\n");
    }
}

void exibirContatos(Contato contatos[], int total){
    if(total == 0){
        printf("\nNenhum contato na agenda.\n");
        return;
    }

    printf("\n--- Lista de Contatos ---\n");

    for (int i = 0; i < total; i++) {
        printf("Nome: %s\n", contatos[i].nome);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("Email: %s\n", contatos[i].email);
        printf("--------------------------\n");
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    Contato contatos[100];
    int totalContatos = 0;
    int opcao;

    do{
        printf("\n=== MENU AGENDA ===\n");
        printf("1. Adicionar contato\n");
        printf("2. Buscar contato\n");
        printf("3. Exibir todos os contatos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                adicionarContato(contatos, &totalContatos);
                break;
            case 2:
                buscarContato(contatos, totalContatos);
                break;
            case 3:
                exibirContatos(contatos, totalContatos);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    }while(opcao != 0);

    return 0;
}