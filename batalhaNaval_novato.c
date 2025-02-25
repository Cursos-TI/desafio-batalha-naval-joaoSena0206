#include <stdio.h>

const int LINHAS_TABULEIRO = 10;
const int COLUNAS_TABULEIRO = 10;

void checaCoordenada(int coord[], char navioTipo[])
{
    if ((coord[0] < 0 || coord[0] > 9))
    {
        printf("Linha inválida do navio da %s!\n", navioTipo);
    }

    if ((coord[1] < 0 || coord[1] > 9))
    {
        printf("Coluna inválida do navio da %s!", navioTipo);
    }
}

void mostraTabuleiro(int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO])
{
    for (int i = 0; i < LINHAS_TABULEIRO; i++)
    {
        for (int j = 0; j < COLUNAS_TABULEIRO; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO];
    int navioHorizontal[3];
    int navioVertical[3];
    int coord_navioHorizontal[2] = {5, 1};
    int coord_navioVertical[2] = {5, 2};

    // Inicializa o tabuleiro com 0s
    for (int i = 0; i < LINHAS_TABULEIRO; i++)
    {
        for (int j = 0; j < COLUNAS_TABULEIRO; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Checa se as coordenadas são válidas
    checaCoordenada(coord_navioHorizontal, "horizontal");
    checaCoordenada(coord_navioVertical, "vertical");

    // Checa se as coordenadas são iguais
    if ((coord_navioHorizontal[0] == coord_navioVertical[0]) && (coord_navioHorizontal[1] == coord_navioVertical[1]))
    {
        printf("As coordenadas dos navios não podem ser iguais!");

        return -1;
    }

    // Checa se as coordenadas dos navios excedem o limite do tabuleiro
    int diferencaExcedidaHorizontal = coord_navioHorizontal[1] + 2 - 9;
    int diferencaExcedidaVertical = coord_navioVertical[0] + 2 - 9;

    if (coord_navioHorizontal[1] + 2 > 9)
    {
        coord_navioHorizontal[1] -= diferencaExcedidaHorizontal;
    }

    if (coord_navioVertical[0] + 2 > 9)
    {
        coord_navioVertical[0] -= diferencaExcedidaVertical;
    }

    // Coloca os navios no tabuleiro
    for (int i = 0; i < 3; i++)
    {
        // Checa se os navios se sobrepõem
        if (tabuleiro[coord_navioHorizontal[0]][coord_navioHorizontal[1] + i] == 3 || tabuleiro[coord_navioVertical[0] + i][coord_navioVertical[1]] == 3)
        {
            printf("Os navios se sobrepõem! Escolha outra coordenada!");

            return -1;
        }

        tabuleiro[coord_navioHorizontal[0]][coord_navioHorizontal[1] + i] = 3;
        tabuleiro[coord_navioVertical[0] + i][coord_navioVertical[1]] = 3;
    }

    // Mostra o tabuleiro na tela
    mostraTabuleiro(tabuleiro);

    return 0;
}
