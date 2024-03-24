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

int verificar_matriz(const vector<vector<int>>& matriz1, const vector<vector<int>>& matriz2){
    if (matriz1 == matriz2){
        return 1;
    }
    else 
    return 0;
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
    int tamanho=0;
    arq_input >> tamanho;
     if (tamanho<5){
        cout << "A matriz não é maior ou igual a 5x5.\n";
        exit(1);
    }

    vector<vector<int>> matriz_inicial(tamanho, vector<int>(tamanho));
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            arq_input >> matriz_inicial[i][j];
        }
    }
    return matriz_inicial;
}

void imprimir_matriz(const vector<vector<int>>& matriz, ofstream& arquivo_saida) {
    for (const auto& linha : matriz) {
        for (int elemento : linha) {
            arquivo_saida << elemento << " ";
        }
        arquivo_saida << endl;
    }
}

void menu(){
    int geracoes=100;
    ifstream arquivo_entrada = abrir_arquivo();

    ofstream arquivo_saida;
    arquivo_saida.open("geracoes.mps");
    if (!arquivo_saida.is_open()) {
        cout << "Ocorreu um erro ao abrir o arquivo.\n";
        exit(1);
    }
    
    vector<vector<int>> matriz = ler_arquivo(arquivo_entrada);
    int i=0;

    do
    {
        arquivo_saida << "---------------------------\n";
        arquivo_saida << "Geração " << i << "\n\n";
        imprimir_matriz(matriz, arquivo_saida);
        matriz = proxima_geracao(matriz);
        if (verificar_matriz(matriz, proxima_geracao(matriz)) == 1){
            arquivo_saida << "---------------------------\n";
            arquivo_saida << "Geração " << i +1 << "\n\n";
            imprimir_matriz(matriz, arquivo_saida);
            i = geracoes;
            arquivo_saida << "\n**A matriz não evolui mais.**";
            i--; //Pra compensar o ++ que tem abaixo.
        }
        i++;
        
    } while (i != geracoes);
    arquivo_saida.close();
    cout << "Arquivo \"gerações.mps\" escrito com sucesso!\n";
}

int main() {
    menu();

    return 0;
}