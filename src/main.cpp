#include <iostream>
#include <fstream>

using namespace std;

ifstream abrir_arquivo(){ 
        ifstream arq_input;

        arq_input.open("input.mps");
        if (!arq_input.is_open()) {
            cout << "Ocorreu um erro ao abrir o arquivo.\n";
        }
       int linhas_colunas = 0;

        arq_input >> linhas_colunas;

        if (linhas_colunas < 5 ) {
            cout << "A matriz não é maior ou igual ou 5x5";
            arq_input.close();
        }

    return arq_input;
}

int main() {
    cout << ("OI\n");
    return 0;
}