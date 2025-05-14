#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Produto{
    char nome[50];
    int codigo;
    int quantidade;
    float preco;
};

typedef struct Produto Produto;

int main(){
    setlocale(LC_ALL, "Portuguese");

    int limiteProdutos = 100;
    Produto produtos[100];
    int total = 0;
    int opcao;

    do{ //menu com as opcoes para cadastrar, buscar e listar os dados
        printf("\n===== Menu Estoque =====\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Buscar Produto por Código\n");
        printf("3 - Listar Produtos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%i", &opcao);
        getchar();

        if(opcao == 1){
            if(total >= limiteProdutos) { //cadastro dos produtos
                printf("Limite de produtos atingido!\n");
                continue;
            }

            printf("\nCadastro do Produto %i\n", total + 1);
            printf("Nome: ");
            fgets(produtos[total].nome, sizeof(produtos[total].nome), stdin);
            produtos[total].nome[strcspn(produtos[total].nome, "\n")] = '\0';

            printf("Código: ");
            scanf("%i", &produtos[total].codigo);

            printf("Quantidade: ");
            scanf("%i", &produtos[total].quantidade);

            printf("Preço: ");
            scanf("%f", &produtos[total].preco);
            getchar();

            total++;
            printf("Produto cadastrado com sucesso!\n");

        }else if (opcao == 2) { //busca dos produtos
            int codigo;
            int encontrado = 0;
            printf("Digite o código do produto: ");
            scanf("%i", &codigo);

            for (int i = 0; i < total; i++) {
                if (produtos[i].codigo == codigo) {
                    printf("\nProduto encontrado:\n");
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Código: %i\n", produtos[i].codigo);
                    printf("Quantidade: %i\n", produtos[i].quantidade);
                    printf("Preço: R$ %.2f\n", produtos[i].preco);
                    encontrado = 1;
                    break;
                }
            }

            if(!encontrado) {
                printf("Produto com código %i não encontrado.\n", codigo);
            }

        }else if(opcao == 3){ //lista os produtos
            if(total == 0) {
                printf("Nenhum produto cadastrado.\n");
            }else {
                printf("\n=== Lista de Produtos ===\n");
                for (int i = 0; i < total; i++) {
                    printf("\nProduto %i:\n", i + 1);
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Código: %i\n", produtos[i].codigo);
                    printf("Quantidade: %i\n", produtos[i].quantidade);
                    printf("Preço: R$ %.2f\n", produtos[i].preco);
                }
            }
        }else if(opcao != 0) {
            printf("Opção inválida. Tente novamente.\n");
        }

    }while(opcao != 0);

    printf("Programa encerrado.\n");
    return 0;
}