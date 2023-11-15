#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[50];
    float nota1;
    float nota2;
    float media;
};


float calcularMedia(float nota1, float nota2) {
    return (nota1 + nota2) / 2.0;
}

void preencherAluno(struct Aluno *aluno) {
    printf("Digite o nome do aluno: ");
    scanf("%s", aluno->nome);

    printf("Digite a nota 1 do aluno %s: ", aluno->nome);
    scanf("%f", &aluno->nota1);

    printf("Digite a nota 2 do aluno %s: ", aluno->nome);
    scanf("%f", &aluno->nota2);

    // Calcular a média e armazenar na struct
    aluno->media = calcularMedia(aluno->nota1, aluno->nota2);
}

void escreverArquivo(struct Aluno *aluno, FILE *arquivo) {
    fprintf(arquivo, " Nome do aluno:  %s = Nota 1 = %.2f, Nota 2 = %.2f; Media do aluno = %.2f\n", aluno->nome, aluno->nota1, aluno->nota2, aluno->media);
}

int main() {
    
    FILE *arquivo = fopen("Media_Alunos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    struct Aluno alunos[10];

    for (int i = 0; i < 10; i++) {
        preencherAluno(&alunos[i]);
    }

    for (int i = 0; i < 10; i++) {
        escreverArquivo(&alunos[i], arquivo);
    }

    fclose(arquivo);

    printf("Os dados foram salvos no arquivo 'Media_Alunos.txt'\n");

    return 0;
}
