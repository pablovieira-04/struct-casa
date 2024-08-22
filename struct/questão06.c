#include <stdio.h>
#include <string.h>


struct Aluno {
    int matricula;
    char nome[50];
    float notas[3];
};

int main() {
   
    struct Aluno alunos[5];
    float maior_media = 0;
    int indice_maior_media = 0;

    
    for (int i = 0; i < 5; i++) {
        printf("\nDigite os dados do aluno %d:\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        getchar();
        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0; 

        for (int j = 0; j < 3; j++) {
            printf("Nota da prova %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
    }

    
    for (int i = 0; i < 5; i++) {
        float media = 0;
        for (int j = 0; j < 3; j++) {
            media += alunos[i].notas[j];
        }
        media /= 3; 

        if (media > maior_media) {
            maior_media = media;
            indice_maior_media = i;
        }
    }

   
    printf("\nAluno com a maior media geral:\n");
    printf("Nome: %s\n", alunos[indice_maior_media].nome);
    printf("Matricula: %d\n", alunos[indice_maior_media].matricula);
    printf("Notas: %.2f, %.2f, %.2f\n", alunos[indice_maior_media].notas[0],
           alunos[indice_maior_media].notas[1], alunos[indice_maior_media].notas[2]);
    printf("Media Geral: %.2f\n", maior_media);

    return 0;
}
