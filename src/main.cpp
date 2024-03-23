#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> 

using namespace std;

bool posicao_valida(int i, int j, int linhas, int colunas) {
    return i >= 0 && i < linhas && j >= 0 && j < colunas;
}

int contar_vizinhos_iguais_a_1(const vector<vector<int>>& matriz, int linha, int coluna) {
    int linhas = matriz.size();
    int colunas = matriz[0].size();

    int contagem = 0;
    // Verificar vizinho acima
    if (posicao_valida(linha - 1, coluna, linhas, colunas) && matriz[linha - 1][coluna] == 1) {
        contagem++;
    }
    // Verificar vizinho abaixo
    if (posicao_valida(linha + 1, coluna, linhas, colunas) && matriz[linha + 1][coluna] == 1) {
        contagem++;
    }
    // Verificar vizinho à esquerda
    if (posicao_valida(linha, coluna - 1, linhas, colunas) && matriz[linha][coluna - 1] == 1) {
        contagem++;
    }
    // Verificar vizinho à direita
    if (posicao_valida(linha, coluna + 1, linhas, colunas) && matriz[linha][coluna + 1] == 1) {
        contagem++;
    }
    // Verificar vizinho superior esquerdo
    if (posicao_valida(linha - 1, coluna - 1, linhas, colunas) && matriz[linha - 1][coluna - 1] == 1) {
        contagem++;
    }
    // Verificar vizinho superior direito
    if (posicao_valida(linha - 1, coluna + 1, linhas, colunas) && matriz[linha - 1][coluna + 1] == 1) {
        contagem++;
    }
    // Verificar vizinho inferior esquerdo
    if (posicao_valida(linha + 1, coluna - 1, linhas, colunas) && matriz[linha + 1][coluna - 1] == 1) {
        contagem++;
    }
    // Verificar vizinho inferior direito
    if (posicao_valida(linha + 1, coluna + 1, linhas, colunas) && matriz[linha + 1][coluna + 1] == 1) {
        contagem++;
    }

    return contagem;
}


ifstream abrir_arquivo() {
    ifstream arq_input;
    arq_input.open("input.mps");
    if (!arq_input.is_open()) {
        cout << "Ocorreu um erro ao abrir o arquivo.\n";
        exit(1);
    }
    return arq_input;
}


vector<vector<int>> ler_arquivo(ifstream& arq_input) {
    int tamanho;
    arq_input >> tamanho;

    vector<vector<int>> matriz_inicial(tamanho, vector<int>(tamanho));
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            arq_input >> matriz_inicial[i][j];
        }
    }
    return matriz_inicial;
}

void imprimir_matriz(const vector<vector<int>>& matriz) {
    for (const auto& linha : matriz) {
        for (int elemento : linha) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}


int main() {
ifstream arquivo = abrir_arquivo();
    vector<vector<int>> matriz = ler_arquivo(arquivo);

    imprimir_matriz(matriz);
    arquivo.close();

    

    cout << endl;


    return 0;
}