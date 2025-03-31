#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h> 
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    int periodoAtual;
    printf("Digite o período atual (1 a 7): ");
    scanf("%d", &periodoAtual);

    if (periodoAtual < 1 || periodoAtual > 7) {
        printf("Período inválido. Por favor, insira um valor entre 1 e 7.\n");
        return 1;
    }

    verificarMaterias(periodoAtual);

    return 0;
}

typedef struct {
    char codigo[10];
    char nome[100];
    int periodo;
    char prerequisitos[100];
} Disciplina;

void verificarMaterias(int periodoAtual) {
    Disciplina disciplinas[] = {
        {"COMP359", "Programação 1", 1, "Nenhum"},
        {"COMP360", "Lógica para Computação", 1, "Nenhum"},
        {"COMP361", "Computação, Sociedade e Ética", 1, "Nenhum"},
        {"COMP362", "Matemática Discreta", 1, "Nenhum"},
        {"COMP363", "Cálculo Diferencial e Integral", 1, "Nenhum"},
        {"COMP364", "Estrutura de Dados", 2, "COMP359"},
        {"COMP365", "Banco de Dados", 2, "Nenhum"},
        {"COMP366", "Organização e Arquitetura de Computadores", 2, "Nenhum"},
        {"COMP367", "Geometria Analítica", 2, "Nenhum"},
        {"COMP368", "Redes de Computadores", 3, "COMP359"},
        {"COMP369", "Teoria dos Grafos", 3, "COMP364 e COMP362"},
        {"COMP370", "Probabilidade e Estatística", 3, "COMP363"},
        {"COMP371", "Álgebra Linear", 3, "COMP367"},
        {"COMP372", "Programação 2", 4, "COMP364, COMP365 e COMP368"},
        {"COMP373", "Programação 3", 4, "COMP364, COMP365 e COMP368"},
        {"COMP374", "Projeto e Análise de Algoritmos", 4, "COMP364 e COMP369"},
        {"COMP376", "Teoria da Computação", 4, "Nenhum"},
        {"COMP378", "Sistemas Operacionais", 5, "COMP366"},
        {"COMP379", "Compiladores", 5, "COMP364 e COMP376"},
        {"COMP380", "Inteligência Artificial", 5, "COMP360 e COMP364"},
        {"COMP381", "Computação Gráfica", 5, "Nenhum"},
        {"COMP382", "Projeto e Desenvolvimento de Sistemas", 6, "Todas as disciplinas do 1º ao 5º período"},
        {"COMP386", "Metodologia de Pesquisa e Trabalho Individual", 7, "Nenhum"},
        {"COMP387", "Noções de Direito", 7, "Nenhum"}
    };

    int totalDisciplinas = sizeof(disciplinas) / sizeof(disciplinas[0]);

    printf("Disciplinas recomendadas para o %dº período:\n", periodoAtual);
    for (int i = 0; i < totalDisciplinas; i++) {
        if (disciplinas[i].periodo == periodoAtual) {
            printf("Código: %s | Nome: %s | Pré-requisitos: %s\n",
                   disciplinas[i].codigo, disciplinas[i].nome, disciplinas[i].prerequisitos);
        }
    }
}

/*

Limite máximo de disciplinas por semestre.      ---> 8 materias

Tempo para concluir o curso.                    ---> tempo médio 

Escolha da ênfase.                              ---> nenhuma ênfase

Critério de seleção das disciplinas.            ---> ate  3 disciplinas por dia, mais deve ir todos os dias a ufal



        Fluxo de materias do curso de Ciência da Computação da UFAL

Código da Disciplina | Nome da Disciplina                     | Período | Pré-requisito
---------------------|--------------------------------------|---------|---------------------------------
COMP359              | Programação 1                                | 1º      | Nenhum
COMP360              | Lógica para Computação                       | 1º      | Nenhum
COMP361              | Computação, Sociedade e Ética                | 1º      | Nenhum
COMP362              | Matemática Discreta                          | 1º      | Nenhum
COMP363              | Cálculo Diferencial e Integral               | 1º      | Nenhum
-----------------------------------------------------------------------------------------------------------      
COMP364              | Estrutura de Dados                     | 2º      | COMP359 (Programação 1)
COMP365              | Banco de Dados                         | 2º      | Nenhum
COMP366              | Organização e Arquitetura de Computadores| 2º      | Nenhum
COMP367              | Geometria Analítica                    | 2º      | Nenhum
-----------------------------------------------------------------------------------------------------------
COMP368              | Redes de Computadores                  | 3º      | COMP359 (Programação 1)
COMP369              | Teoria dos Grafos                      | 3º      | COMP364 e COMP362
COMP370              | Probabilidade e Estatística            | 3º      | COMP363
COMP371              | Álgebra Linear                         | 3º      | COMP367
-----------------------------------------------------------------------------------------------------------
COMP372              | Programação 2                          | 4º      | COMP364, COMP365 e COMP368
COMP373              | Programação 3                          | 4º      | COMP364, COMP365 e COMP368
COMP374              | Projeto e Análise de Algoritmos        | 4º      | COMP364 e COMP369
COMP376              | Teoria da Computação                   | 4º      | Nenhum
-----------------------------------------------------------------------------------------------------------
COMP378              | Sistemas Operacionais                  | 5º      | COMP366
COMP379              | Compiladores                           | 5º      | COMP364 e COMP376
COMP380              | Inteligência Artificial                | 5º      | COMP360 e COMP364
COMP381              | Computação Gráfica                     | 5º      | Nenhum
-----------------------------------------------------------------------------------------------------------
COMP382              | Projeto e Desenvolvimento de Sistemas  | 6º      | Todas as disciplinas do 1º ao 5º período
-----------------------------------------------------------------------------------------------------------
COMP386              | Metodologia de Pesquisa e Trabalho Individual| 7º      | Nenhum
COMP387              | Noções de Direito                      | 7º      | Nenhum

*/