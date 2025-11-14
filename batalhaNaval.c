#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main()
{
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiroNovato[5][5];
    int tabuleiroNovatoNavios[4][2] = {
        // Horizontal
        {1, 2},
        {1, 3},
        // Vertical
        {3, 1},
        {4, 1}};

    printf("tabuleiroNovato: \n");
    for (int linha = 0; linha < 5; linha++)
    {
        for (int coluna = 0; coluna < 5; coluna++)
        {
            tabuleiroNovato[linha][coluna] = 0;

            for (int navio = 0; navio < 4; navio++)
            {
                if (linha == tabuleiroNovatoNavios[navio][0] && coluna == tabuleiroNovatoNavios[navio][1])
                {
                    tabuleiroNovato[linha][coluna] = 1;
                }
            }

            printf("%d ", tabuleiroNovato[linha][coluna]);
        }

        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    int tabuleiroAventureiro[10][10] = {0};
    int validoAventureiro = 1;

    // Lista de coordenadas (linha, colunauna) - 1-based
    int naviosAventureiro[12][2] = {
        // Horizontal
        {1, 2},
        {1, 3},
        {1, 4},
        // Vertical
        {3, 2},
        {4, 2},
        {5, 2},
        // Diagonal 1
        {10, 9},
        {9, 8},
        {8, 7},
        // Diagonal 2
        {7, 9},
        {6, 8},
        {5, 7}};

    // Validação de limites
    for (int i = 0; i < 12 && validoAventureiro; i++)
    {
        if (naviosAventureiro[i][0] < 1 || naviosAventureiro[i][0] > 10 ||
            naviosAventureiro[i][1] < 1 || naviosAventureiro[i][1] > 10)
        {
            printf("Erro: coordenada fora do tabuleiro (%d,%d)\n",
                   naviosAventureiro[i][0], naviosAventureiro[i][1]);
            validoAventureiro = 0;
        }
    }

    // Validação de sobreposição O(N²)
    for (int i = 0; i < 12 && validoAventureiro; i++)
    {
        for (int j = i + 1; j < 12; j++)
        {
            if (naviosAventureiro[i][0] == naviosAventureiro[j][0] &&
                naviosAventureiro[i][1] == naviosAventureiro[j][1])
            {
                printf("Erro: sobreposição detectada na posição (%d,%d)\n",
                       naviosAventureiro[i][0], naviosAventureiro[i][1]);
                validoAventureiro = 0;
                break;
            }
        }
    }

    // Posicionar navios se válido
    if (validoAventureiro)
    {
        for (int i = 0; i < 12; i++)
            tabuleiroAventureiro[naviosAventureiro[i][0] - 1][naviosAventureiro[i][1] - 1] = 3;

        printf("tabuleiroAventureiro:\n");
        for (int l = 0; l < 10; l++)
        {
            for (int c = 0; c < 10; c++)
                printf("%d ", tabuleiroAventureiro[l][c]);
            printf("\n");
        }
    }
    else
    {
        printf("Navios não foram posicionados devido a erros.\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    int cone[5][5] = {0};
    printf("cone:\n");
    for (int linha = 0; linha < 3; linha++)
    {
        int inicio = 2 - linha;
        int fim = 2 + linha;
        for (int coluna = inicio; coluna <= fim; coluna++)
        {
            cone[linha][coluna] = 1;
        }
    }
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 5; coluna++)
        {
            printf("%d ", cone[linha][coluna]);
        }
        printf("\n");
    }

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    int octa[5][5] = {0};
    printf("octaedro:\n");
    for (int linha = 0; linha < 3; linha++)
    {
        if (linha == 1)
        {
            octa[linha][1] = 1;
            octa[linha][2] = 1;
            octa[linha][3] = 1;
        }
        else
        {
            octa[linha][2] = 1;
        }
    }
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 5; coluna++)
        {
            printf("%d ", octa[linha][coluna]);
        }
        printf("\n");
    }

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    int cruz[5][5] = {0};
    printf("cruz:\n");
    for (int linha = 0; linha < 3; linha++)
    {
        if (linha == 1)
        {
            for (int coluna = 0; coluna < 5; coluna++)
            {
                cruz[linha][coluna] = 1;
            }
        }
        else
        {
            cruz[linha][2] = 1;
        }
    }
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 5; coluna++)
        {
            printf("%d ", cruz[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
