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

vector<vector<int>> proxima_geracao(const vector<vector<int>>& matriz){
    int linhas = matriz.size();
    int colunas = matriz[0].size();
    //Iniciei as matriz com o número 0, por que como não havia nenhum elemento preenchido, ele dava segmentation fault.
    vector<vector<int>> proxima_matriz(linhas, vector<int>(colunas, 0));
    for (int linha = 0; linha < matriz.size(); linha++) {
        for (int coluna = 0; coluna < matriz.size(); coluna++) {
            //Uma célula viva com menos de dois vizinhos vivos morre (solidão)
            if (contar_vizinhos_iguais_a_1(matriz, linha, coluna) < 2 && matriz[linha][coluna] == 1) {
                proxima_matriz[linha][coluna] = 0;
            }
            // Uma célula viva com mais de três vizinhos vivos morre (superpopulação).
            else if (contar_vizinhos_iguais_a_1(matriz, linha, coluna) > 3 && matriz[linha][coluna] == 1) {
                proxima_matriz[linha][coluna] = 0;
            }
            // Uma célula viva com dois ou três vizinhos vivos sobrevive.
            else if ((contar_vizinhos_iguais_a_1(matriz, linha, coluna) == 2 || contar_vizinhos_iguais_a_1(matriz, linha, coluna) == 3) && matriz[linha][coluna] == 1) {
                proxima_matriz[linha][coluna] = 1;
            }
            // Uma célula morta com exatamente três vizinhos vivos se torna viva (reprodução)
            else if (contar_vizinhos_iguais_a_1(matriz, linha, coluna) == 3 && matriz[linha][coluna] == 0) {
                proxima_matriz[linha][coluna] = 1;
            }
        }
    }
    return proxima_matriz;
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

void menu(){
    int geracoes=5;
    ifstream arquivo = abrir_arquivo();
    vector<vector<int>> matriz = ler_arquivo(arquivo);
    int i=0;
    do
    {
        cout << "---------------------------\n";
        cout << "Geração " << i ;
        cout << endl;
        imprimir_matriz(matriz);
        matriz = proxima_geracao(matriz);
        i++;
    } while (i != geracoes);
}

int main() {
    menu();
    // ifstream arquivo = abrir_arquivo();
    // vector<vector<int>> matriz = ler_arquivo(arquivo);

    // imprimir_matriz(matriz);
    // cout << endl;
    // imprimir_matriz(proxima_geracao(matriz));
    // cout << endl;
    // imprimir_matriz(proxima_geracao(proxima_geracao(matriz)));
    
    // arquivo.close();

    



    return 0;
}