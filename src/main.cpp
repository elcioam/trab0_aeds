#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> 

using namespace std;

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
    return 0;
}
