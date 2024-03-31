![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/capa%20gif.gif?raw=true) 

![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/capa.png?raw=true)

>Por Élcio Amorim.

# **TRABALHO 0 AEDS (Jogo da Vida)**

## *Introdução* 
Este é um trabalho da disciplina de Algoritmos e Estrutura de Dados (AEDS), **[orientado pelo professor Michel](https://github.com/mpiress)**. Será implementado o Jogo da Vida em C++, seguindo as diretrizes fornecidas. O objetivo é revisar conceitos importantes e aplicar conhecimentos adquiridos ao longo do curso.

O Jogo da Vida é um autômato celular desenvolvido pelo matemático britânico John Horton Conway em 1970. É um exemplo bem conhecido de autômato celular e tem aplicações em diversas áreas da ciência. As regras do jogo são simples e são aplicadas a cada nova "geração". A partir de uma imagem em um tabuleiro bi-dimensional definida pelo jogador.

## *Regras*
Foram criadas representações visuais claras e didáticas para ilustrar o funcionamento e as mudanças ocorridas a cada geração do Jogo da Vida. Essas imagens ajudam a visualizar de forma intuitiva as alterações no tabuleiro bi-dimensional conforme as regras são aplicadas.

>![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/solidao.png?raw=true)

![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/superpopulacao.png?raw=true)

>![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/sobrevivencia.png?raw=true)

![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/solidao.png?raw=true)

## Orientações do Projeto

Logo abaixo está orientações importantes que deverão ser seguidas no código:

1. Criar uma matriz N x N para representar o tabuleiro do Jogo da Vida.
2. Ler a matriz de entrada de um arquivo, considerando um tamanho mínimo de 5x5.
3. Pedir ao usuário apenas o número de gerações a ser avaliado como entrada.
4. Apresentar mensagens de algoritmo em execução e processo de gerações finalizado na tela.
5. Armazenar a matriz de entrada em um arquivo chamado ```input.mps``` dentro da pasta ```datasets``` do projeto, fora da pasta ```src```.
6. Salvar a matriz avaliada em um arquivo chamado ```geracoes.mps```, mostrando todas as evoluções, inclusive a matriz de origem.
7. Utilizar uma fração de 2 para 1 para compor os valores 0s e 1s, com menos 1s para um melhor espalhamento.

## *Decisões de Implementação/Principais Problemas*
![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/problemas.png?raw=true)
Foram exploradas diversas ideias para tornar a implementação ainda mais interessante e robusta. Embora tenha optado por não incluir algumas ideas, como o cercamento da matriz original (será falado), a ideia de implementar essas decisões foi considerada para melhorar a eficiência e a precisão do programa. E também será abordado o principal problema do código, que diz respeito à detecção de posições fora da matriz.

### *O "GRANDE" problema*
Ao declararmos uma matriz em C++, não podemos acessar posições que não existem em uma matriz porque isso causaria um erro de acesso inválido à memória. Quando tentamos acessar uma posição fora dos limites de uma matriz, estamos acessando uma área de memória que não foi alocada para essa matriz. Como representado abaixo:

![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/matriz%20inexistente.png?raw=true) 

#### *Uma solução não tão boa...*
Rodear a matriz de elementos para facilitar a verificação de vizinhos parece ser uma boa ideia à primeira vista, pois simplifica o tratamento de células nas bordas, evitando condições especiais de verificação. No entanto, essa abordagem pode aumentar significativamente o custo computacional.

Ao rodear a matriz, você está adicionando células extras em todas as bordas, o que aumenta a quantidade de elementos a serem processados. Além disso, ao realizar as verificações de vizinhança, você precisa considerar essas células extras, o que aumenta a complexidade do código e o tempo de execução.

![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/cercar%20matriz.png?raw=true)

#### *A solução usada*
Apesar de quase ser implementada a ideia acima, uma decisão melhor foi implementada. Foi criada uma função booleana chamada *posicao_valida* que é responsável por verificar se a posição que acessada está dentro dos limites da matriz, ela combinada com a função *contar_vizinhos_iguais_a_1* (será mostrada) fez com que tudo funcionasse de acordo com a proposta do trabalho. Ela recebe como entrada as coordenadas *(i, j)* de uma posição na matriz e os limites da matriz, ou seja, o número de linhas e colunas (que é o mesmo). Em seguida, verifica se i está dentro do intervalo *[0, linhas]* e se j está dentro do intervalo *[0, colunas]*. Se ambos forem verdadeiros, isso significa que a posição *(i, j)* está dentro dos limites válidos da matriz e retorna **true**. Caso contrário, retorna **false**, indicando que a posição está fora dos limites.

A representação para ajudar no entendimento:
![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/posicao%20valida.png?raw=true)

## *Funções do programa*

**Função posicao_valida:**<br>
Parâmetros: i, j são as coordenadas da posição a ser verificada; linhas, colunas são o número total de linhas e colunas da matriz.<br>
Funcionalidade: Verifica se a posição (i, j) está dentro dos limites válidos da matriz.<br>
Retorno: Retorna true se a posição é válida e false caso contrário.<br>

**Função contar_vizinhos_iguais_a_1:**<br>
Parâmetros: matriz é a matriz de entrada; linha, coluna são as coordenadas da célula atual.<br>
Funcionalidade: Conta o número de vizinhos da célula (linha, coluna) que têm o valor 1 na matriz. Os vizinhos são as células acima, abaixo, à esquerda, à direita e nas diagonais.<br>
Retorno: Retorna o número de vizinhos iguais a 1.<br>

**Função proxima_geracao:**<br>
Parâmetros: matriz é a matriz atual do Jogo da Vida.<br>
Funcionalidade: Calcula a próxima geração do Jogo da Vida para a matriz dada, aplicando as regras do jogo.<br>
Retorno: Retorna a matriz que representa a próxima geração.<br>

**Função verificar_matriz:**<br>
Parâmetros: matriz1, matriz2 são duas matrizes a serem comparadas.<br>
Funcionalidade: Verifica se as duas matrizes são iguais, ou seja, se possuem os mesmos elementos nas mesmas posições.<br>
Retorno: Retorna 1 se as matrizes são iguais e 0 caso contrário.<br>

**Função abrir_arquivo:**<br>
Funcionalidade: Abre o arquivo de entrada "input.mps".<br>
Retorno: Retorna um objeto ifstream que permite a leitura do arquivo.<br>

**Função ler_arquivo:**<br>
Parâmetros: arq_input é o objeto ifstream que representa o arquivo aberto.<br>
Funcionalidade: Lê uma matriz do arquivo de entrada, verificando se o tamanho da matriz é maior ou igual a 5x5.<br>
Retorno: Retorna a matriz lida do arquivo.<br>

**Função imprimir_matriz:**<br>
Parâmetros: matriz é a matriz a ser impressa; arquivo_saida é o objeto ofstream que representa o arquivo de saída.<br>
Funcionalidade: Imprime a matriz no arquivo de saída, separando os elementos por espaço e as linhas por quebra de linha.<br>

**Função menu:**<br>
Parâmetros: geracoes é o número de gerações que serão geradas.<br>
Funcionalidade: Função principal que controla o fluxo do programa. Abre o arquivo de entrada, o arquivo de saída, lê a matriz do arquivo de entrada, calcula as próximas gerações do Jogo da Vida e imprime no arquivo de saída até que o número de gerações seja atingido ou a matriz não evolua mais.<br>

## *Comandos do código* (Makefile)

Comando   | Utilidade
--------- | ------
```make clean``` | Remove os arquivos objetos e o executável gerados.
```make``` | Compila o código fonte e gera o executável.
```make run``` | Executa o programa compilado.

## *Conclusão*
Durante a realização deste trabalho, pude revisitar e aplicar conceitos importantes de IPC (Introdução à Programação de Computadores), como a passagem de parâmetros por referência em funções e os conceitos de matrizes. A implementação do Jogo da Vida em C++ foi uma oportunidade para colocar em prática esses conceitos, além de aprimorar minhas habilidades de programação.

Destaco também o tempo dedicado à criação de **imagens didáticas**, essenciais para o melhor entendimento do código e das regras do Jogo da Vida. Essas imagens não apenas facilitaram a compreensão do algoritmo, mas também contribuíram para uma apresentação mais visual e atrativa do trabalho.

No geral, estou satisfeito com o resultado final e com o aprendizado obtido ao longo do desenvolvimento deste projeto. Acredito que essa experiência tenha ajudado significativamente para o meu desenvolvimento como programador.

## *Contato*

Contato   | Plataforma
--------- | ------
```@argondsgn / @elcioamorim_``` | [![Instagram](https://skillicons.dev/icons?i=instagram)](https://www.instagram.com/argondsgn)
```elcio@aluno.cefetmg.br``` | [![Gmail](https://skillicons.dev/icons?i=gmail)](elcio@aluno.cefetmg.br)














