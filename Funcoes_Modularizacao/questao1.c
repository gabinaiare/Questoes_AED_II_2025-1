#include<stdio.h>
#include <stdbool.h>
#include<locale.h>

/*Prototipo da Função*/
bool ehPrimo (int n);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int x, y;

    do
    {
        printf("Digite o começo do intervalo: ");
        scanf("%i", &x);
        printf("Digite o fim do intervalo: ");
        scanf("%i", &y);
    } while (x >= y); //para garantir que o primeiro número será menor ou igual ao último

    /*Este for irá percorrer todos os números do intervalo
    chamando a função ehPrimo para fazer a verificação dos números primos
    de cada um*/
    printf("Números primos entre %i e %i:\n", x, y);
    for (int i = x; i <= y; i++){
        if (ehPrimo(i))
        {
            printf("%i ", i);
        }   
    } 

return 0;
}

bool ehPrimo (int n){
    if (n < 2){
        return false; //número menor que dois não é primo
    }
    /*divide n por todos os números i entre dois e raiz quadrada de n*/
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0)
        {
            return false;
        }
    }
    return true; //quando não entra em nenhum dos dois if, então é primo
}