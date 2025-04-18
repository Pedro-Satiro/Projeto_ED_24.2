#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aluno : Pedro Henrique Satiro Correia

#define MAX_PACIENTES 100

typedef struct {
    char nome[50];
    int idade;
    char cor[10];
    int horaChegada;
} Paciente;

typedef struct {
    Paciente pacientes[MAX_PACIENTES];
    int tamanho;
} FilaPrioridade;

void inicializarFila(FilaPrioridade *fila) {
    fila->tamanho = 0;
}

int estaCheia(FilaPrioridade *fila) {
    return fila->tamanho == MAX_PACIENTES;
}

int estaVazia(FilaPrioridade *fila) {
    return fila->tamanho == 0;
}

void classificarPaciente(Paciente *paciente) {
    int riscoIminente, riscoSignificativo, estavel, riscoImediato;

    printf("Classificacao de triagem para %s:\n", paciente->nome);
    printf("1. Possui risco de morte iminente? (1-Sim, 0-Nao): ");
    scanf("%d", &riscoIminente);

    if (riscoIminente) {
        strcpy(paciente->cor, "VERMELHO");
        return;
    }

    printf("2. Possui risco significativo de agravamento? (1-Sim, 0-Nao): ");
    scanf("%d", &riscoSignificativo);

    if (riscoSignificativo) {
        strcpy(paciente->cor, "LARANJA");
        return;
    }

    printf("3. Situacao esta estavel? (1-Sim, 0-Nao): ");
    scanf("%d", &estavel);

    if (!estavel) {
        strcpy(paciente->cor, "AMARELO");
        return;
    }

    printf("4. Possui risco imediato? (1-Sim, 0-Nao): ");
    scanf("%d", &riscoImediato);

    if (riscoImediato) {
        strcpy(paciente->cor, "AMARELO");
    } else {
        strcpy(paciente->cor, "VERDE");
    }
}
int compararCores(const char *cor1, const char *cor2) {
    const char *ordemCores[] = {"VERMELHO", "LARANJA", "AMARELO", "VERDE"};
    int prioridade1 = 0, prioridade2 = 0;

    for (int i = 0; i < 4; i++) {
        if (strcmp(cor1, ordemCores[i]) == 0) {
            prioridade1 = i;
        }
        if (strcmp(cor2, ordemCores[i]) == 0) {
            prioridade2 = i;
        }
    }

    return prioridade1 - prioridade2;
}
void inserirPaciente(FilaPrioridade *fila) {
    if (estaCheia(fila)) {
        printf("A fila esta cheia!\n");
        return;
    }

    Paciente novoPaciente;
    printf("Nome do paciente: ");
    scanf(" %[^\n]", novoPaciente.nome);
    printf("Idade do paciente: ");
    scanf("%d", &novoPaciente.idade);
    printf("Hora de chegada (em minutos): ");
    scanf("%d", &novoPaciente.horaChegada);

    classificarPaciente(&novoPaciente);

    int i = fila->tamanho - 1;
    while (i >= 0 && strcmp(fila->pacientes[i].cor, novoPaciente.cor) > 0) {
        fila->pacientes[i + 1] = fila->pacientes[i];
        i--;
    }

    fila->pacientes[i + 1] = novoPaciente;
    fila->tamanho++;

    printf("Paciente %s classificado como %s inserido na fila.\n", novoPaciente.nome, novoPaciente.cor);
}

void removerPaciente(FilaPrioridade *fila) {
    if (estaVazia(fila)) {
        printf("A fila esta vazia!\n");
        return;
    }

    printf("Paciente %s atendido e removido da fila.\n", fila->pacientes[0].nome);
    for (int i = 1; i < fila->tamanho; i++) {
        fila->pacientes[i - 1] = fila->pacientes[i];
    }
    fila->tamanho--;
}

void exibirFila(FilaPrioridade *fila) {
    if (estaVazia(fila)) {
        printf("A fila esta vazia!\n");
        return;
    }

    printf("Fila de prioridade:\n");
    for (int i = 0; i < fila->tamanho; i++) {
        printf("%d. Nome: %s, Idade: %d, Cor: %s, Hora de Chegada: %d\n",
               i + 1, fila->pacientes[i].nome, fila->pacientes[i].idade,
               fila->pacientes[i].cor, fila->pacientes[i].horaChegada);
    }
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Inserir paciente\n");
    printf("2. Remover paciente\n");
    printf("3. Exibir fila\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}
int compararPacientes(Paciente *a, Paciente *b) {
    // Prioridade 1: Menores de 15 anos
    if (a->idade < 15 && b->idade >= 15) {
        return -1;
    }
    if (b->idade < 15 && a->idade >= 15) {
        return 1;
    }

    // Prioridade 2: Mais velho
    if (a->idade != b->idade) {
        return b->idade - a->idade;
    }

    // Prioridade 3: Maior tempo de espera (menor hora de chegada)
    return a->horaChegada - b->horaChegada;
}

void ordenarFila(FilaPrioridade *fila) {
    for (int i = 0; i < fila->tamanho - 1; i++) {
        for (int j = 0; j < fila->tamanho - i - 1; j++) {
            if (compararPacientes(&fila->pacientes[j], &fila->pacientes[j + 1]) > 0) {
                Paciente temp = fila->pacientes[j];
                fila->pacientes[j] = fila->pacientes[j + 1];
                fila->pacientes[j + 1] = temp;
            }
        }
    }
}
int main() {
    FilaPrioridade fila;
    inicializarFila(&fila);

    int opcao;
    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirPaciente(&fila);
                break;
            case 2:
                removerPaciente(&fila);
                break;
            case 3:
                exibirFila(&fila);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
