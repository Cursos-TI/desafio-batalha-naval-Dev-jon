#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10

// Função para inicializar o tabuleiro com 0s (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir 

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%2d ", j); // Cabeçalho das colunas (0-9)
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i); // Número da linha (0-9)
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Posicionar navio horizontal

bool posicionarHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho) {
    // Verifica se o navio cabe na posição
    if (coluna + tamanho > TAMANHO) {
        printf("Erro: Navio horizontal não cabe nesta posição!\n");
        return false;
    }
// Verifica se as posições estão livres


    for (int j = coluna; j < coluna + tamanho; j++) {
        if (tabuleiro[linha][j] != 0) {
            printf("Erro: Posição (%d,%d) já ocupada!\n", linha, j);
            return false;
        }
    }
    
    // Posiciona o navio 

    
    for (int j = coluna; j < coluna + tamanho; j++) {
        tabuleiro[linha][j] = 3;
    }
    
    return true;
}    