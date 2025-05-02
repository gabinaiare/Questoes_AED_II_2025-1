#include<stdio.h>
#include<locale.h>

int potencia(int base, int expoente); //Protótipo da Função

int main(){
    setlocale(LC_ALL, "Portuguese");
    int b, e;

    printf("Digite a base da potência: ");
    scanf("%i", &b);
    printf("Digite o expoente: ");
    scanf("%i", &e);

    printf("O resultado da potênciação é: %i", potencia(b, e)); 

return 0;
}

int potencia(int base, int expoente){
    int resultado = 1;

    if (expoente == 0){ //Resultado igual a 1 caso o expoente seja 0
        return 1;
    }

    for (int i = 1; i <= expoente; i++){ //Faz a multiplicação da base no total de vezes do expoente
        resultado *= base;
    }

return resultado;
}