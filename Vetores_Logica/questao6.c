#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int A[3][3], B[3][3], C[3][3];
    int i, j;

    printf("Digite os valores da matriz A:\n"); // Leitura da matriz A
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nDigite os valores da matriz B:\n"); // Leitura da matriz B
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < 3; i++){ //Soma das matrizes, utilizando a matriz C para armazenar o resultado
        for (j = 0; j < 3; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nMatriz soma (C = A + B):\n"); //Resultado da soma
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
