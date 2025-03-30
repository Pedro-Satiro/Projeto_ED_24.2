/* 







// funcao para converter as letras em números
int valor_letra(wchar_t letra) {
    switch (letra) {
        case L'q': return 1; case L'w': return 6; case L'e': return 7;
        case L'r': return 6; case L't': return 5; case L'y': return 2;
        case L'u': return 3; case L'i': return 8; case L'o': return 9;
        case L'p': return 4; case L'a': return 2; case L's': return 5;
        case L'd': return 8; case L'f': return 7; case L'g': return 4;
        case L'h': return 1; case L'j': return 4; case L'k': return 7;
        case L'l': return 8; case L'ç': return 5; case L'é': return 2;
        case L'z': return 3; case L'x': return 4; case L'c': return 9;
        case L'v': return 8; case L'b': return 3; case L'n': return 2;
        case L'm': return 5; case L'ó': return 6; case L'õ': return 7;
        case L'ô': return 6; case L'â': return 1; case L'ê': return 2;
        case L'í': return 3; case L' ': return 0; 
        default: return 0;
    }
}

// funcao que realiza a operação com os números e retorna 0, 1 ou 2
int operacao(int numeros[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += numeros[i];
    }
    printf("Soma %d\n", soma);
    return soma % 3;
}

// separar o nome e calcular soma por parte
void separarNome(wchar_t nome[], int numeros[], int tamanho) {
    printf("\nPartes do nome separadas com suas somas:\n");
    
    int inicio = 0;
    int encontrouPalavra = 0;
    int somaParcial = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (numeros[i] == 0) { // ee encontrou um espaço (0)
            if (encontrouPalavra) {
                wprintf(L"%.*ls (Soma: %d)\n", i - inicio, &nome[inicio], somaParcial);
            }
            encontrouPalavra = 0;
            inicio = i + 1; // atualiza para a proxima palavra
            somaParcial = 0; 
        } else {
            encontrouPalavra = 1;
            somaParcial += numeros[i];
        }
    }
    
    // caso sobre um nome sobrando
    if (encontrouPalavra) {
        wprintf(L"%ls (Soma: %d)\n", &nome[inicio], somaParcial);
    }
}

int main() {
    int numeros[50];
    wchar_t nome[50]; 

    printf("Digite seu nome: ");
    fgetws(nome, sizeof(nome) / sizeof(wchar_t), stdin);
    nome[wcslen(nome) - 1] = L'\0'; 

    int tamanho = wcslen(nome);

    printf("Letras do nome:\n");
    for (int i = 0; i < tamanho; i++) {
        wprintf(L"Letras[%d] = %lc\n", i, nome[i]);
        numeros[i] = valor_letra(towlower(nome[i]));
    }

    printf("Numeros convertidos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Numeros[%d] = %d\n", i, numeros[i]);
    }

    int resultado = operacao(numeros, tamanho); 

    separarNome(nome, numeros, tamanho);

    printf("Resto da divisao da soma por 3: %d\n", resultado);
    return 0;
}



1 etapa :  aluno deve ter um limite máximo de disciplina por semestre planejado, igual a:

some todos os números do seu primeiro nome e divida o resultado por 3, se o valor do resto for :

0 = máximo 10
1= máximo 8
2= máximo 6

R: 34 ÷ 3 = 11 com resto 1


2 Etapa: Considerando que o aluno deseja concluir o curso: :

some todos os números do seu próximo nome e divida o resultado por 3, se o valor do resto for :

0= no menor tempo possível
1= no maior tempo possível
2= tempo médio possível

R: Resto da divisão por 3:
35 ÷ 3 = 11 com resto 2
Portanto:

O aluno deve concluir o curso em tempo médio possível.

A ênfase deve ser nenhuma.

A escolha das disciplinas deve seguir a regra: o aluno não deve extrapolar o limite de 3 disciplinas no máximo por dia, mas deve ir todos os dias à UFAL.

3 etapa : escolha da ênfase deve seguir a seguinte orientação:

some todos os números do seu próximo nome e divida o resultado por 3, se o valor do resto for :

0= ênfase desejada pelo aluno
1= ênfase que diminui o tempo de conclusão do curso pelo aluno
2= nenhuma ênfase

R:Resto da divisão por 3:
35 ÷ 3 = 11 com resto 2
Portanto:


A ênfase deve ser nenhuma.

A escolha das disciplinas deve seguir a regra: o aluno não deve extrapolar o limite de 3 disciplinas no máximo por dia, mas deve ir todos os dias à UFAL.

4 etapa: A escolha da das disciplina deve seguir a seguinte orientação:

some todos os números do seu próximo nome e divida o resultado por 3, se o valor do resto for :

0= as disciplinas deve ocupar o menos números de dias possíveis
1= as disciplinas devem pertencer a um mesmo turno
2= o aluno não deve extrapola o limite de 3 disciplinas no máximo por dia, mais deve ir todos os dias a ufal

Resto da divisão por 3:
47 ÷ 3 = 15 com resto 2
Portanto:

O aluno deve concluir o curso em tempo médio possível.

A ênfase deve ser nenhuma.

A escolha das disciplinas deve seguir a regra: o aluno não deve extrapolar o limite de 3 disciplinas no máximo por dia, mas deve ir todos os dias à UFAL.


Escopo do projeto :


Faça um programa que gerar um aconselhamento pedagógico aos alunos do Curso de Ciência da Computação do Instituto de Computação da UFAL, considerando o último plano pedagógico PPC2019. Não é permitido que o aluno esteja matriculado em uma disciplina sem ter seu pré-requisito, nem em duas disciplinas com choque de horário. É obrigatório que o aluno esteja matriculado em pelo menos 1 disciplina.

O aluno deve ter um limite máximo de disciplina por semestre planejado, igual a:



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