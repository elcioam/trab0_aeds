#include "jogo_da_vida.hpp"
#include "iostream"

using namespace std; 

int main() {
    int geracoes;
    cout << ("Digite quantas gerações:\n");
    cin >> geracoes;
    menu(geracoes);

    return 0;
}