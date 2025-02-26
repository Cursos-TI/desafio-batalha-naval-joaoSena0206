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

void aplicarHabilidades(int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO], int habilidade[5][5], int coordLinha, int coordColuna)
{
    int pontoOrigem = 2;
    int tamanhoHabilidade = 5;

    coordLinha--;
    coordColuna--;

    for (int i = 0; i < tamanhoHabilidade; i++)
    {
        for (int j = 0; j < tamanhoHabilidade; j++)
        {
            int linha = coordLinha + i - tamanhoHabilidade / 2;
            int coluna = coordColuna + j - tamanhoHabilidade / 2;
            int eLinhaValida = linha >= 0 && linha < LINHAS_TABULEIRO;
            int eColunaValida = coluna >= 0 && coluna < COLUNAS_TABULEIRO;
            int ePosicaoValida = eLinhaValida && eColunaValida && habilidade[i][j] == 1 && tabuleiro[linha][coluna] != 3;

            if (ePosicaoValida)
            {
                tabuleiro[linha][coluna] = 5;
            }
        }
    }
}

int main()
{
    int tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO];
    int navioHorizontal[3];
    int navioVertical[3];
    int navioDiagonal1[3];
    int navioDiagonal2[3];
    int coord_navioHorizontal[2] = {5 - 1, 1 - 1}; // Diminui as coordenadas em 1 para que o usuário entenda como 10x10 e não como 9x9 (array começa no índice 0)
    int coord_navioVertical[2] = {7 - 1, 1 - 1};
    int coord_navioDiagonal1[2] = {3 - 1, 3 - 1};
    int coord_navioDiagonal2[2] = {8 - 1, 2 - 1};

    int cone[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}};

    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}};

    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}};

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
    checaCoordenada(coord_navioDiagonal1, "diagonal");
    checaCoordenada(coord_navioDiagonal2, "diagonal");

    // Checa se as coordenadas dos navios excedem o limite do tabuleiro
    int diferencaExcedidaHorizontal = coord_navioHorizontal[1] + 2 - 9;
    int diferencaExcedidaVertical = coord_navioVertical[0] + 2 - 9;

    int diferencaExcedidaLinhaDiagonal1 = coord_navioDiagonal1[0] + 2 - 9;
    int diferencaExcedidaColunaDiagonal1 = coord_navioDiagonal1[1] + 2 - 9;

    int diferencaExcedidaLinhaDiagonal2 = coord_navioDiagonal2[0] + 2 - 9;
    int diferencaExcedidaColunaDiagonal2 = coord_navioDiagonal2[1] + 2 - 9;

    if (coord_navioHorizontal[1] + 2 > 9)
    {
        coord_navioHorizontal[1] -= diferencaExcedidaHorizontal;
    }

    if (coord_navioVertical[0] + 2 > 9)
    {
        coord_navioVertical[0] -= diferencaExcedidaVertical;
    }

    if (coord_navioDiagonal1[0] + 2 > 9)
    {
        coord_navioDiagonal1[0] -= diferencaExcedidaLinhaDiagonal1;
    }

    if (coord_navioDiagonal1[1] + 2 > 9)
    {
        coord_navioDiagonal1[1] -= diferencaExcedidaColunaDiagonal1;
    }

    if (coord_navioDiagonal2[0] + 2 > 9)
    {
        coord_navioDiagonal2[0] -= diferencaExcedidaLinhaDiagonal2;
    }

    if (coord_navioDiagonal2[1] + 2 > 9)
    {
        coord_navioDiagonal2[1] -= diferencaExcedidaColunaDiagonal2;
    }

    // Coloca os navios no tabuleiro
    for (int i = 0; i < 3; i++)
    {
        // Checa se os navios se sobrepõem
        int localNavioHorizontal = tabuleiro[coord_navioHorizontal[0]][coord_navioHorizontal[1] + i];
        int localNavioVertical = tabuleiro[coord_navioVertical[0] + i][coord_navioVertical[1]];
        int localNavioDiagonal1 = tabuleiro[coord_navioDiagonal1[0] + i][coord_navioDiagonal1[1] + i];
        int localNavioDiagonal2 = tabuleiro[coord_navioDiagonal2[0] + i][coord_navioDiagonal2[1] + i];

        int estaoNaviosSobrepostos = localNavioHorizontal == 3 || localNavioVertical == 3 || localNavioDiagonal1 == 3 || localNavioDiagonal2 == 3;

        if (estaoNaviosSobrepostos)
        {
            printf("Os navios se sobrepõem! Escolha outra coordenada!");

            return -1;
        }

        tabuleiro[coord_navioHorizontal[0]][coord_navioHorizontal[1] + i] = 3;
        tabuleiro[coord_navioVertical[0] + i][coord_navioVertical[1]] = 3;

        tabuleiro[coord_navioDiagonal1[0] + i][coord_navioDiagonal1[1] + i] = 3;
        tabuleiro[coord_navioDiagonal2[0] + i][coord_navioDiagonal2[1] + i] = 3;
    }

    // Coloca as habilidades no tabuleiro
    aplicarHabilidades(tabuleiro, cone, 5, 8);
    aplicarHabilidades(tabuleiro, cruz, 3, 5);
    aplicarHabilidades(tabuleiro, octaedro, 2, 3);

    // Mostra o tabuleiro na tela
    mostraTabuleiro(tabuleiro);

    return 0;
}