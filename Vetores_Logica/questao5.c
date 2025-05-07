#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int V1[10], V2[10];

    for (int i = 0; i < 10; i++){ //Pega todos os números do primeiro vetor
        printf("Digite o %iº número: ", i + 1);
        scanf("%i", &V1[i]);
    }

    printf("\nPróximo Vetor:\n");

    for (int i = 0; i < 10; i++){ //Pega todos os números do segundo vetor
        printf("Digite o %iº número: ", i + 1);
        scanf("%i", &V2[i]);
    }

    
    printf("\nElementos comuns:\n");
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++) {
            if (V1[i] == V2[j]){
                int impresso = 0; // Verifica se já foi impresso antes
                for (int k = 0; k < i; k++){
                    if (V1[k] == V1[i]){
                        impresso = 1;
                        break;
                    }
                }
                if (!impresso){
                    printf("%d\n", V1[i]);
                }
                break; //não precisa continuar verificando B
            }
        }
    }
return 0;  
}