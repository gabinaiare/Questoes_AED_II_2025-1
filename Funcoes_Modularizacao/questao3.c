#include<stdio.h>
#include<locale.h>

int inverte(int numero);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int n;

    printf("Digite um número: ");
    scanf("%i", &n);

    printf("Sua inversão: %i", inverte(n));
}

int inverte(int numero){
    int invertido = 0; //a variavel pegará digito por digito durante a inversão

    while (numero != 0)
    {
        int digito = numero % 10; //Aqui é pego o último digito do número
        invertido = invertido * 10 + digito; //A formula para inverter
        numero /= 10; //Reduz o número
    }
    
    return invertido;
}