#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int dia;
    int mes;
    int ano;
};

int comparaData(struct Pessoa p1, struct Pessoa p2) {
    if (p1.ano < p2.ano) return -1;
    if (p1.ano > p2.ano) return 1;
    if (p1.mes < p2.mes) return -1;
    if (p1.mes > p2.mes) return 1;
    if (p1.dia < p2.dia) return -1;
    if (p1.dia > p2.dia) return 1;
    return 0;
}

int main() {
    struct Pessoa pessoas[6];
    struct Pessoa mais_nova, mais_velha;
    
    for (int i = 0; i < 6; i++) {
        printf("\nDigite os dados da pessoa %d:\n", i + 1);

        printf("Nome: ");
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = 0;

        printf("Data de Nascimento: ");
        scanf("%d %d %d", &pessoas[i].dia, &pessoas[i].mes, &pessoas[i].ano);
        getchar();  
    }

    mais_nova = mais_velha = pessoas[0];

    for (int i = 1; i < 6; i++) {
        if (comparaData(pessoas[i], mais_velha) < 0) {
            mais_velha = pessoas[i];
        }
        if (comparaData(pessoas[i], mais_nova) > 0) {
            mais_nova = pessoas[i];
        }
    }

    printf("\nPessoa mais velha: %s\n", mais_velha.nome);
    printf("Data de Nascimento: %02d/%02d/%04d\n", mais_velha.dia, mais_velha.mes, mais_velha.ano);

    printf("\nPessoa mais nova: %s\n", mais_nova.nome);
    printf("Data de Nascimento: %02d/%02d/%04d\n", mais_nova.dia, mais_nova.mes, mais_nova.ano);

    return 0;
}
