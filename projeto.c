#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int codigo;
    char nome[100];
    int periodo;
    int prerequisitos[20];
    int totalPrerequisitos;
} Disciplina;

void listarTodasMaterias(Disciplina disciplinas[], int totalDisciplinas) {
    printf("Lista de todas as materias:\n");
    for (int i = 0; i < totalDisciplinas; i++) {
        printf("Codigo: %d | Nome: %s | Periodo: %d\n", disciplinas[i].codigo, disciplinas[i].nome, disciplinas[i].periodo);
    }
}

void selecionarMaterias(Disciplina disciplinas[], int totalDisciplinas, int periodoAtual, int materiasCursadas[], int totalCursadas) {
    printf("Disciplinas recomendadas para o %d periodo:\n", periodoAtual);
    int materiasSelecionadas[100];
    int totalSelecionadas = 0;

    for (int i = 0; i < totalDisciplinas; i++) {
        if (disciplinas[i].periodo == periodoAtual) {
            int podeCursar = 1;
            for (int j = 0; j < disciplinas[i].totalPrerequisitos; j++) {
                int prerequisitoAtendido = 0;
                for (int k = 0; k < totalCursadas; k++) {
                    if (disciplinas[i].prerequisitos[j] == materiasCursadas[k]) {
                        prerequisitoAtendido = 1;
                        break;
                    }
                }
                if (!prerequisitoAtendido) {
                    podeCursar = 0;
                    break;
                }
            }
            if (podeCursar) {
                printf("Codigo: %d | Nome: %s\n", disciplinas[i].codigo, disciplinas[i].nome);
            }
        }
    }

    printf("Digite os codigos das materias que deseja cursar (-1 para finalizar):\n");
    while (1) {
        if (totalSelecionadas >= 8) {
            printf("Voce atingiu o limite maximo de 8 materias por periodo.\n"); // 1 Regra 
            break;
        }

        int codigo;
        scanf("%d", &codigo);
        if (codigo == -1) {
            break;
        }
        int encontrado = 0;
        for (int i = 0; i < totalDisciplinas; i++) {
            if (disciplinas[i].codigo == codigo && disciplinas[i].periodo == periodoAtual) {
                encontrado = 1;
                materiasSelecionadas[totalSelecionadas++] = codigo;
                break;
            }
        }
        if (!encontrado) {
            printf("Codigo invalido ou nao recomendado para este periodo. Tente novamente.\n");
        }
    }

    printf("Materias selecionadas:\n");
    for (int i = 0; i < totalSelecionadas; i++) {
        for (int j = 0; j < totalDisciplinas; j++) {
            if (disciplinas[j].codigo == materiasSelecionadas[i]) {
                printf("Codigo: %d | Nome: %s\n", disciplinas[j].codigo, disciplinas[j].nome);
                break;
            }
        }
    }
}

void obterMateriasCursadas(int materiasCursadas[], int *totalCursadas) {
    printf("Digite os codigos das materias ja cursadas (digite -1 para finalizar):\n");
    while (1) {
        int codigo;
        scanf("%d", &codigo);
        if (codigo == -1) {
            break;
        }
        if (codigo < 359 || codigo > 390) {
            printf("Codigo invalido. Insira o Codigo correto da diciplina.\n");
            continue;
        }
        materiasCursadas[(*totalCursadas)++] = codigo;
    }
}

int obterPeriodoAtual() {
    int periodoAtual;
    printf("Digite o periodo atual (1 a 7): ");
    scanf("%d", &periodoAtual);

    if (periodoAtual < 1 || periodoAtual > 7) {
        printf("Periodo invalido. Por favor, insira um valor entre 1 e 7.\n");
        exit(1);
    }
    return periodoAtual;
}

int main() {
    setlocale(LC_ALL, "");

    Disciplina disciplinas[] = {
        {359, "Programacao 1", 1, {}, 0},
        {360, "Logica para Computacao", 1, {}, 0},
        {361, "Computacao, Sociedade e Etica", 1, {}, 0},
        {362, "Matematica Discreta", 1, {}, 0},
        {363, "Calculo Diferencial e Integral", 1, {}, 0},
        {364, "Estrutura de Dados", 2, {359}, 1},
        {365, "Banco de Dados", 2, {}, 0},
        {366, "Organizacao e Arquitetura de Computadores", 2, {}, 0},
        {367, "Geometria Analitica", 2, {}, 0},
        {368, "Redes de Computadores", 3, {359}, 1},
        {369, "Teoria dos Grafos", 3, {364, 362}, 2},
        {370, "Probabilidade e Estatistica", 3, {363}, 1},
        {371, "Algebra Linear", 3, {367}, 1},
        {372, "Programacao 2", 4, {364, 365, 368}, 3},
        {373, "Programacao 3", 4, {364, 365, 368}, 3},
        {376, "Teoria da Computacao", 4, {}, 0},
        {378, "Sistemas Operacionais", 5, {366}, 1},
        {379, "Compiladores", 5, {364, 376}, 2},
        {380, "Inteligencia Artificial", 5, {360, 364}, 2},
        {381, "Computacao Grafica", 5, {}, 0},
        {382, "Projeto e Desenvolvimento de Sistemas", 6, {359,360,361,362,364,365,366,367,368,369,370,371,372,373,376,378,379,380,381}, 19},
        {386, "Metodologia de Pesquisa e Trabalho Individual", 7, {}, 0},
        {387, "Nocoes de Direito", 7, {}, 0}
    };

    int totalDisciplinas = sizeof(disciplinas) / sizeof(disciplinas[0]);

    listarTodasMaterias(disciplinas, totalDisciplinas);

    int materiasCursadas[100];
    int totalCursadas = 0;

    obterMateriasCursadas(materiasCursadas, &totalCursadas);

    int periodoAtual = obterPeriodoAtual();

    selecionarMaterias(disciplinas, totalDisciplinas, periodoAtual, materiasCursadas, totalCursadas);

    return 0;
}



/*
        programação 1 terça e quinta
        Logica para Computacao
        Computacao, Sociedade e Etica
        Matematica Discreta
        Calculo Diferencial e Integral terça e quinta
        Estrutura de Dados
        Banco de Dados terça e quinta
        Organizacao e Arquitetura de Computadores terça e quinta
        Geometria Analitica
        Redes de Computadores
        Teoria dos Grafos
        Probabilidade e Estatistica
        Algebra Linear
        Programacao 2 terça e quinta
        Programacao 3
        Teoria da Computacao,
        Sistemas Operacionais
        Compiladores
        Inteligencia Artificial
        Computacao Grafica
        Projeto e Desenvolvimento de Sistemas
        Metodologia de Pesquisa e Trabalho Individual
        Nocoes de Direito

*/