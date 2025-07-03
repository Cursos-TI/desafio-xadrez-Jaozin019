#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Níveis: Novato, Aventureiro e Mestre

#define BISPO_STEPS   5
#define TORRE_STEPS   5
#define RAINHA_STEPS  8

// Funções recursivas para o nível Mestre
void moveBishopRec(int currentStep, int maxSteps);
void moveRookRec(int currentStep, int maxSteps);
void moveQueenRec(int currentStep, int maxSteps);

int main() {
    
    // Nível Novato - Movimentações com estruturas de repetição
    
    printf("=== Nivel Novato ===\n\n");

    // Movimento do Bispo: 5 casas na diagonal superior direita
    printf("Movimentacao do Bispo (diagonal superior direita):\n");
    for (int passo = 1; passo <= BISPO_STEPS; passo++) {
        printf("[%d] Cima-Direita\n", passo);
    }
    printf("\n");

    // Movimento da Torre: 5 casas para a direita
    printf("Movimentacao da Torre (direita):\n");
    for (int passo = 1; passo <= TORRE_STEPS; passo++) {
        printf("[%d] Direita\n", passo);
    }
    printf("\n");

    // Movimento da Rainha: 8 casas para a esquerda
    printf("Movimentacao da Rainha (esquerda):\n");
    for (int passo = 1; passo <= RAINHA_STEPS; passo++) {
        printf("[%d] Esquerda\n", passo);
    }
    printf("\n\n");


    // Nível Aventureiro - Cavalo em L (para baixo e para a esquerda)
    
    printf("=== Nivel Aventureiro ===\n\n");
    printf("Movimentacao do Cavalo (L: 2x Baixo, 1x Esquerda):\n");

    // Loop for aninhado com do-while
    for (int rep = 0; rep < 1; rep++) {
        // passo vertical: 2 vezes para baixo
        for (int v = 0; v < 2; v++) {
            printf("Baixo\n");
        }
        // passo horizontal: 1 vez para a esquerda
        int h = 0;
        do {
            printf("Esquerda\n");
            h++;
        } while (h < 1);
    }
    printf("\n\n");

    // Nível Mestre - Funções recursivas e loops avançados

    printf("=== Nivel Mestre ===\n\n");

    // Bispo: recursão + loops aninhados

    printf("Movimentacao do Bispo (recursivo, diagonal superior direita):\n");
    moveBishopRec(1, BISPO_STEPS);
    printf("\n");

    // Torre: recursão simples

    printf("Movimentacao da Torre (recursivo, direita):\n");
    moveRookRec(1, TORRE_STEPS);
    printf("\n");

    // Rainha: recursão simples

    printf("Movimentacao da Rainha (recursivo, esquerda):\n");
    moveQueenRec(1, RAINHA_STEPS);
    printf("\n");

    // Cavalo: L para cima e direita com múltiplas condições, continue e break

    printf("Movimentacao do Cavalo (L: 2x Cima, 1x Direita, loops com continue e break):\n");
    int upCount = 0, rightCount = 0;
    while (1) {
        if (upCount < 2) {
            upCount++;
            printf("Cima\n");
            continue;  // Volta ao início para subir novamente
        }
        if (rightCount < 1) {
            rightCount++;
            printf("Direita\n");
        }
        // Assim que completar 2 "Cima" e 1 "Direita", sai do laço
        if (upCount >= 2 && rightCount >= 1) {
            break;
        }
    }

    return 0;
}

// Movimentar o Bispo em diagonal (superior direita)

void moveBishopRec(int currentStep, int maxSteps) {
    if (currentStep > maxSteps) {
        return;  
    }
   
    for (int i = 0; i < 1; i++) {
        printf("Cima\n");
        for (int j = 0; j < 1; j++) {
            printf("Direita\n");
        }
    }
    moveBishopRec(currentStep + 1, maxSteps);
}

// Movimentar a Torre para a direita
void moveRookRec(int currentStep, int maxSteps) {
    if (currentStep > maxSteps) {
        return;
    }
    printf("Direita\n");
    moveRookRec(currentStep + 1, maxSteps);
}

// Movimentar a Rainha para a esquerda
void moveQueenRec(int currentStep, int maxSteps) {
    if (currentStep > maxSteps) {
        return;
    }
    printf("Esquerda\n");
    moveQueenRec(currentStep + 1, maxSteps);
}

