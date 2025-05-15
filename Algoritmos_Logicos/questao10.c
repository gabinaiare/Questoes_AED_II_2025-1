#include<stdio.h>
#include<locale.h>

// Função recursiva
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int n;

    printf("Digite um número (n >= 0): ");
    scanf("%d", &n);

    if(n < 0){
        printf("Valor inválido.\n");
        return 1;
    }

    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));

    return 0;
}