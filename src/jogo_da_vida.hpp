#ifndef JOGO_DA_VIDA_HPP
#define JOGO_DA_VIDA_HPP

#include <vector>
#include <fstream>

bool posicao_valida(int i, int j, int linhas, int colunas);
int contar_vizinhos_iguais_a_1(const std::vector<std::vector<int>>& matriz, int linha, int coluna);
std::vector<std::vector<int>> proxima_geracao(const std::vector<std::vector<int>>& matriz);
int verificar_matriz(const std::vector<std::vector<int>>& matriz1, const std::vector<std::vector<int>>& matriz2);
std::ifstream abrir_arquivo();
std::vector<std::vector<int>> ler_arquivo(std::ifstream& arq_input);
void imprimir_matriz(const std::vector<std::vector<int>>& matriz, std::ofstream& arquivo_saida);
void menu(int geracoes);

#endif // JOGO_DA_VIDA_HPP
