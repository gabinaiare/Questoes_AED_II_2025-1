#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int V[10];

    for (int i = 0; i < 10; i++){ //Pega todos os números do vetor
        printf("Digite o %iº número: ", i + 1);
        scanf("%i", &V[i]);
    }

    for (int i = 0; i < 10; i++){
        int contado = 0;

        for (int j = 0; j < i; j++){ //compara o número atual com os números anteriores
            if (V[i] == V[j])
            {
                contado += 1;
                break;
            }
        }
        if (!contado){ //contagem de quantas vezes aparece
            int contagem = 1;
            for (int j = i + 1; j < 10; j++) {
                if (V[i] == V[j]) {
                    contagem++;
                }
            }
            printf("O número: %d aparece %d vez(es)\n", V[i], contagem);
        }   
    }    
}