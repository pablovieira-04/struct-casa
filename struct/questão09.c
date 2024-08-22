#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char esporte[30];
    int idade;
    float altura;
} Atleta;

int main() {
    Atleta atletas[5];
    Atleta mais_velho, mais_alto;

    for (int i = 0; i < 5; i++) {
        printf("\nDigite os dados do atleta %d:\n", i + 1);

        printf("Nome: ");
        fgets(atletas[i].nome, sizeof(atletas[i].nome), stdin);
        atletas[i].nome[strcspn(atletas[i].nome, "\n")] = 0; 

        printf("Esporte: ");
        fgets(atletas[i].esporte, sizeof(atletas[i].esporte), stdin);
        atletas[i].esporte[strcspn(atletas[i].esporte, "\n")] = 0; 

        printf("Idade: ");
        scanf("%d", &atletas[i].idade);

        printf("Altura (em metros): ");
        scanf("%f", &atletas[i].altura);
        getchar(); 
    }

    mais_velho = mais_alto = atletas[0];


    for (int i = 1; i < 5; i++) {
        if (atletas[i].idade > mais_velho.idade) {
            mais_velho = atletas[i];
        }
        if (atletas[i].altura > mais_alto.altura) {
            mais_alto = atletas[i];
        }
    }

    printf("\nAtleta mais velho:\n");
    printf("Nome: %s\n", mais_velho.nome);
    printf("Esporte: %s\n", mais_velho.esporte);
    printf("Idade: %d anos\n", mais_velho.idade);
    printf("Altura: %.2f metros\n", mais_velho.altura);

    printf("\nAtleta mais alto:\n");
    printf("Nome: %s\n", mais_alto.nome);
    printf("Esporte: %s\n", mais_alto.esporte);
    printf("Idade: %d anos\n", mais_alto.idade);
    printf("Altura: %.2f metros\n", mais_alto.altura);

    return 0;
}
