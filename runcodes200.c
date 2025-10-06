#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 41
#define MAX_ALUNOS 50
#define NUM_NOTAS 3

typedef struct {
    char nome[TAM_NOME];
    float notas[NUM_NOTAS];
    float media;
} Aluno_t;

void limparBuffer() {
    char ch;
    while (((ch = getchar()) != '\n') && ch != EOF);
}

void adicionarAluno(Aluno_t alunos[], int *num_alunos) {
    if (*num_alunos == MAX_ALUNOS) {
        printf("Número máximo já foi atingido!\n");
        return;
    }

    Aluno_t novo;
    printf("Digite o nome: ");
    fgets(novo.nome, TAM_NOME, stdin);

    for (int i = 0; i < NUM_NOTAS; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &novo.notas[i]);
        limparBuffer();
    }

    float media = 0;
    for (int i = 0; i < NUM_NOTAS; i++) {
        media += novo.notas[i];
    }
    media /= NUM_NOTAS;
    novo.media = media;

    alunos[*num_alunos] = novo;
    *num_alunos += 1;
}

void listarAlunos(const Aluno_t alunos[], int num_alunos) {
    if (num_alunos == 0) {
        printf("Não há alunos para exibir\n");
        return;
    }
    for (int i = 0; i < num_alunos; i++) {
        printf("Nome do aluno: %s\n", alunos[i].nome);
        printf("Média = %.2f\n", alunos[i].media);
    }
}

void alunoMaiorMedia(const Aluno_t alunos[], int num_alunos) {
    if (num_alunos == 0) {
        printf("Não há alunos para exibir\n");
        return;
    }
    int indice_maior = 0;
    for (int i = 0; i < num_alunos; i++) {
        if (alunos[indice_maior].media < alunos[i].media) {
            indice_maior = i;
        }
    }

    printf("Aluno com maior média:\n");
    printf("Nome: %s\n", alunos[indice_maior].nome);
    printf("Maior média: %.2f\n", alunos[indice_maior].media);
}

int main() {
    Aluno_t alunos[MAX_ALUNOS];
    int num_alunos = 0;

    int opcao;
    do {
        printf("---- MENU ----\n");
        printf("1. Adicionar aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Mostrar aluno com a maior média\n");
        printf("0. Sair\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);
        limparBuffer();
        switch (opcao) {
        case 1:
            adicionarAluno(alunos, &num_alunos);
            break;
        case 2:
            listarAlunos(alunos, num_alunos);
            break;
        case 3:
            alunoMaiorMedia(alunos, num_alunos);
            break;
        case 0:
            printf("Terminando execução.\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }


    } while (opcao != 0);

    return 0;
}