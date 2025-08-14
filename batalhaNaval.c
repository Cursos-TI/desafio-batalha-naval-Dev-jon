#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10

// Função para inicializar 

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
    
    // Posiciona o navio (valor 3 para posições ocupadas)

    for (int j = coluna; j < coluna + tamanho; j++) {
        tabuleiro[linha][j] = 3;
    }
    
    return true;
}

// Posicionar navio vertical

bool posicionarVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho) {
    
    if (linha + tamanho > TAMANHO) {
        printf("Erro: Navio vertical não cabe nesta posição!\n");
        return false;
    }
    
    
    for (int i = linha; i < linha + tamanho; i++) {
        if (tabuleiro[i][coluna] != 0) {
            printf("Erro: Posição (%d,%d) já ocupada!\n", i, coluna);
            return false;
        }
    }
    
    
    for (int i = linha; i < linha + tamanho; i++) {
        tabuleiro[i][coluna] = 3;
    }
    
    return true;
}



// Posicionar navio diagonal (direita para baixo)
bool posicionarDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho) {
    // Verifica se o navio cabe na posição
    if (linha + tamanho > TAMANHO || coluna + tamanho > TAMANHO) {
        printf("Erro: Navio diagonal não cabe nesta posição!\n");
        return false;
    }
    
    // Verifica se as posições estão livres
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) {
            printf("Erro: Posição (%d,%d) já ocupada!\n", linha + i, coluna + i);
            return false;
        }
    }
    
    // Posiciona o navio
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
    
    return true;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);
    
    printf("=== BATALHA NAVAL - TABULEIRO 10x10 ===\n");
    printf("=== 0: Água | 3: Navio ===\n");

    
