
![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/capa%20gif.gif?raw=true) 

>Por Élcio Amorim.


# TRABALHO 0 AEDS (Jogo da Vida)

## Introdução 
Este é um trabalho da disciplina de Algoritmos e Estrutura de Dados (AEDS), **[orientado pelo professor Michel](https://github.com/mpiress)**. Será implementado o Jogo da Vida em C++, seguindo as diretrizes fornecidas. O objetivo é revisar conceitos importantes e aplicar conhecimentos adquiridos ao longo do curso.

O Jogo da Vida é um autômato celular desenvolvido pelo matemático britânico John Horton Conway em 1970. É um exemplo bem conhecido de autômato celular e tem aplicações em diversas áreas da ciência. As regras do jogo são simples e são aplicadas a cada nova "geração". A partir de uma imagem em um tabuleiro bi-dimensional definida pelo jogador.

## Regras 
Podemos dizer que foram criadas representações visuais claras e didáticas para ilustrar o funcionamento e as mudanças ocorridas a cada geração do Jogo da Vida. Essas imagens ajudam a visualizar de forma intuitiva as alterações no tabuleiro bi-dimensional conforme as regras são aplicadas.

>![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/solidao.png?raw=true)

![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/superpopulacao.png?raw=true)

>![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/sobrevivencia.png?raw=true)

![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/solidao.png?raw=true)

## Decisões de Implementação/Principais Problemas
![]()
Foram exploradas diversas ideias para tornar a implementação ainda mais interessante e robusta. Embora tenha optado por não incluir algumas ideas, como o cercamento da matriz original (será falado ), a ideia de implementar essas decisões foi considerada para melhorar a eficiência e a precisão do programa. E também será abordado o principal problema do código, que diz respeito à detecção de posições fora da matriz.

### O "GRANDE" problema
Ao declararmos uma matriz em C++, não podemos acessar posições que não existem em uma matriz porque isso causaria um erro de acesso inválido à memória. Quando tentamos acessar uma posição fora dos limites de uma matriz, estamos acessando uma área de memória que não foi alocada para essa matriz. Como representado abaixo:

![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/matriz%20inexistente.png?raw=true) 

#### Uma solução não tão boa...
Rodear a matriz de elementos para facilitar a verificação de vizinhos parece ser uma boa ideia à primeira vista, pois simplifica o tratamento de células nas bordas, evitando condições especiais de verificação. No entanto, essa abordagem pode aumentar significativamente o custo computacional.

Ao rodear a matriz, você está adicionando células extras em todas as bordas, o que aumenta a quantidade de elementos a serem processados. Além disso, ao realizar as verificações de vizinhança, você precisa considerar essas células extras, o que aumenta a complexidade do código e o tempo de execução.

![](https://github.com/elcioam/trab0_aeds/blob/main/git%20design/cercar%20matriz.png?raw=true)

#### A solução usada
Apesar de quase ser implementada a ideia acima, blá blá bla (colocar minha ideia e a imagem).

## Lógica utilizada
* contar os vizinhos bla bla bla
* bla bla


## Comandos do código
**fazer tabelinha**
make clean
make 
make run












