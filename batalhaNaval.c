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
