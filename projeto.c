#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h> 

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
