/* 
Nome : Pedro Henrique Sátiro Correia

Regras:::

limite máximo de disciplinas por semestre é 8.
O aluno deve concluir o curso em tempo médio possível.
nenhuma ênfase
o aluno não deve extrapola o limite de 3 disciplinas no máximo por dia, mais deve ir todos os dias a ufal

*/ 




/*
        Fluxo de materias do curso de Ciência da Computação da UFAL

 1 Periodo: 
 Programação 1                  359
Lógica para Computação          360
Computação, Sociedade e Ética   361
Matemática Discreta             362
Cálculo Diferencial e Integral  363


2 Periodo:
Estrutura de Dados 1            364
Banco de Dados 1                365
OAC                             366
Geometria Analítica             367

3 Periodo:
Redes de Computadores           368
Teoria dos Grafos               369
Probabilidade e Estatística     370
Álgebra Linear                  371 

4 Periodo:
Programação 2                   372
Programação 3                   373
Projeto e Análise de Algoritmos 374
Teoria da Computação            375

5 Periodo:
Sistemas Operacionais           378
Compiladores                    379
Inteligência Artificial         380
Computação Gráfica              381

6 Periodo:
Projeto e Desenvolvimento de Sistemas 382

7 Periodo:
Metodologia de Pesquisa e Trabalho Individual 386
Noções de Direito               387


*/



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
    int dias[4]; // 0: segunda, 1: terca, 2: quarta, 3: quinta
} Disciplina;

void listarTodasMaterias(Disciplina disciplinas[], int totalDisciplinas) {
    printf("Lista de todas as materias:\n");
    for (int i = 0; i < totalDisciplinas; i++) {
        printf("Codigo: %d | Nome: %s | Periodo: %d\n", disciplinas[i].codigo, disciplinas[i].nome, disciplinas[i].periodo);
    }
}

void selecionarMaterias(Disciplina disciplinas[], int totalDisciplinas, int periodoAtual, int materiasCursadas[], int totalCursadas, Disciplina disciplinasSelecionadas[]) {
    printf("Disciplinas recomendadas para o %d periodo:\n", periodoAtual);
    int materiasSelecionadas[100];
    int totalSelecionadas = 0;

    for (int i = 0; i < totalDisciplinas; i++) {
        if (disciplinas[i].periodo <= periodoAtual) {
            int podeCursar = 1;
            for (int k = 0; k < totalCursadas; k++) {
                if (disciplinas[i].codigo == materiasCursadas[k]) {
                    podeCursar = 0;
                    break;
                }
            }
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

    printf("Digite os codigos das materias que deseja cursar (-1 para finalizar) (use 1 materia por linha):\n");
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
            if (disciplinas[i].codigo == codigo && disciplinas[i].periodo <= periodoAtual) {
                encontrado = 1;
                materiasSelecionadas[totalSelecionadas++] = codigo;
                break;
            }
        }
        if (!encontrado) {
            printf("Codigo invalido ou nao recomendado para este periodo. Tente novamente.\n");
        }
    }

    if (totalSelecionadas == 0) {
        printf("Voce deve selecionar pelo menos uma materia.\n");
        exit(1);
    }

    printf("Materias selecionadas:\n");
    for (int i = 0; i < totalSelecionadas; i++) {
        for (int j = 0; j < totalDisciplinas; j++) {
            if (disciplinas[j].codigo == materiasSelecionadas[i]) {
                printf("Codigo: %d | Nome: %s\n", disciplinas[j].codigo, disciplinas[j].nome);
                disciplinasSelecionadas[i] = disciplinas[j];
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

int verificaDiasMatricula(Disciplina disciplinas[]) {
    int dias[4] = {0, 0, 0, 0};

    for (int i = 0; i < 100; i++) {
        if (disciplinas[i].codigo == 0) {
            break;
        }
        for (int j = 0; j < 4; j++) {
            if (disciplinas[i].dias[j]) {
                dias[j]++;
                if (dias[j] > 3) {
                    printf("Erro: Mais de 3 materias alocadas no mesmo dia.\n");
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (dias[i] == 0) {
            printf("Erro: Nenhuma materia alocada no dia %d.\n", i + 1);
            return 0;
        }
    }
    
    return 1; // Retorne o valor apropriado
}

int verificarFormaturaEm8Periodos(Disciplina disciplinas[], int totalDisciplinas, int materiasCursadas[], int totalCursadas, int periodoAtual) {
    int totalRestantes = 0;
    int materiasRestantes[50];

    for (int i = 0; i < totalDisciplinas; i++) {
        int jaCursada = 0;
        for (int j = 0; j < totalCursadas; j++) {
            if (disciplinas[i].codigo == materiasCursadas[j]) {
                jaCursada = 1;
                break;
            }
        }
        if (!jaCursada) {
            materiasRestantes[totalRestantes++] = disciplinas[i].codigo;
        }
    }

    int periodosRestantes = 8 - periodoAtual;
    if (periodosRestantes <= 0) {
        printf("Erro: Já está no último período ou além do limite de 8 períodos.\n");
        return 0;
    }

    int maxMateriasPorPeriodo = 8;
    int materiasPorPeriodo = (totalRestantes + periodosRestantes - 1) / periodosRestantes; // Arredondar para cima

    if (materiasPorPeriodo > maxMateriasPorPeriodo) {
        printf("Nao e possivel se formar em 8 periodos. Voce precisara cursar mais de %d materias por periodo.\n", maxMateriasPorPeriodo);
        return 0;
    } else {
        printf("E possivel se formar em 8 periodos.\n");
        printf("Voce precisara cursar aproximadamente %d materias por periodo nos proximos %d periodos.\n", materiasPorPeriodo, periodosRestantes);
        return 1;
    }
}

int main() {
    setlocale(LC_ALL, "");

    Disciplina disciplinas[] = {
        {359, "Programacao 1", 1, {}, 0, {1, 3}},
        {360, "Logica para Computacao", 1, {}, 0, {0, 2}},
        {361, "Computacao, Sociedade e Etica", 1, {}, 0, {0, 2}},
        {362, "Matematica Discreta", 1, {}, 0, {0, 2}},
        {363, "Calculo Diferencial e Integral", 1, {}, 0, {1, 3}},
        {364, "Estrutura de Dados", 2, {359}, 1, {0, 2}},
        {365, "Banco de Dados", 2, {}, 0, {1, 3}},
        {366, "Organizacao e Arquitetura de Computadores", 2, {}, 0, {1, 3}},
        {367, "Geometria Analitica", 2, {}, 0, {0, 2}},
        {368, "Redes de Computadores", 3, {359}, 1, {0, 2}},
        {369, "Teoria dos Grafos", 3, {364, 362}, 2, {0, 3}},
        {370, "Probabilidade e Estatistica", 3, {363}, 1, {0, 2}},
        {371, "Algebra Linear", 3, {367}, 1, {0, 2}},
        {372, "Programacao 2", 4, {364, 365, 368}, 3, {1, 3}},
        {373, "Programacao 3", 4, {364, 365, 368}, 3, {1, 2}},
        {376, "Teoria da Computacao", 4, {}, 0, {0, 2}},
        {378, "Sistemas Operacionais", 5, {366}, 1, {0, 2}},
        {379, "Compiladores", 5, {364, 376}, 2, {0, 2}},
        {380, "Inteligencia Artificial", 5, {360, 364}, 2, {1, 3}},
        {381, "Computacao Grafica", 5, {}, 0, {1, 3}},
        {382, "Projeto e Desenvolvimento de Sistemas", 6, {359,360,361,362,364,365,366,367,368,369,370,371,372,373,376,378,379,380,381}, 19, {0, 1, 2, 3}},
        {386, "Metodologia de Pesquisa e Trabalho Individual", 7, {}, 0, {1, 3}},
        {387, "Nocoes de Direito", 7, {}, 0, {1, 3}}
    };

    int totalDisciplinas = sizeof(disciplinas) / sizeof(disciplinas[0]);

    listarTodasMaterias(disciplinas, totalDisciplinas);

    int materiasCursadas[100];
    int totalCursadas = 0;

    obterMateriasCursadas(materiasCursadas, &totalCursadas);

    int periodoAtual = obterPeriodoAtual();

    if (!verificarFormaturaEm8Periodos(disciplinas, totalDisciplinas, materiasCursadas, totalCursadas, periodoAtual)) {
        printf("Voce nao podera se formar em 8 periodos. Entre em contato com a sua coordenacao \n");
        return 0;
    }

    Disciplina disciplinasSelecionadas[100];

    selecionarMaterias(disciplinas, totalDisciplinas, periodoAtual, materiasCursadas, totalCursadas, disciplinasSelecionadas);

    printf("Verificando se as materias selecionadas atendem as regras de alocacao...\n");
    if (verificaDiasMatricula(disciplinasSelecionadas)) {
        printf("Materias selecionadas atendem as regras de alocacao.\n");
    } else {
        printf("Materias selecionadas nao atendem as regras de alocacao.\n");
    }

    return 0;
}

/*
        programação 1 - [1, 3]
        Logica para Computacao - [0, 2]
        Computacao, Sociedade e Etica - [0, 2]
        Matematica Discreta - [0, 2]
        Calculo Diferencial e Integral - [1, 3]
        Estrutura de Dados - [0, 2]
        Banco de Dados - [1, 3]
        Organizacao e Arquitetura de Computadores -  [1, 3]
        Geometria Analitica - [0, 2]
        Redes de Computadores - [0, 2]
        Teoria dos Grafos - [0, 3]
        Probabilidade e Estatistica - [0, 2]
        Algebra Linear - [0, 2]
        Programacao 2-  [1, 3]
        Programacao 3 - [1, 2]
        Teoria da Computacao - [0, 2]
        Sistemas Operacionais - [0, 2]
        Compiladores - [0, 2]
        Inteligencia Artificial - [1, 3]
        Computacao Grafica  - [1, 3]
        Projeto e Desenvolvimento de Sistemas [0, 1, 2, 3]
        Metodologia de Pesquisa e Trabalho Individual -  [1, 3]
        Nocoes de Direito - [1, 3]

*/