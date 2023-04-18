<h1 align="center"> Labirinto-Recorrente </h1>
<div style="display: inline-block;">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg"/> 
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<a href="https://github.com/Guiliard/midpy/issues">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"/>
<img align="center" height="20px" width="80px" src="https://badgen.net/badge/license/MIT/green"/>
</a>
</div>
<br><div align=center>
<img src="https://user-images.githubusercontent.com/127882640/232782489-b924b25c-6224-463b-b180-1c43ec4591dd.png" width="850px">
</div>

# Introdução
<p>Foi proposto um problema de caminhamento de matrizes quadradas (NxN) de forma recorrente, ou seja, aquele que opta por um caminho alatório com possibilidade de retorno. No exercício, a movimentação se dá nas oito direções cardeais (Oeste, Sudoeste, Sul, Sudeste, Leste, Nordeste, Norte, Noroeste), e, também, em todas as matrizes existentes de forma conectada.</p> 

# Descrição do Problema
<p>Em um arquivo do tipo ".data", localiza-se um determinado número de matrizes quadradas, as quais possuem, em suas posições, três tipos de elementos: inteiros positivos (0 a 9), paredes (#) e perigos (*). Os inteiros positivos significam itens que podem ser consumidos, as paredes significam as posições que não podem ser acessadas, e o asterisco, os perigos a serem enfrentados.<br>
Na matriz, localiza-se, também, um jogador (hunter), sendo esse o personagem que percorrerá a matriz de forma aleatória. Caso o jogador encontre um inteiro positivo diferente de zero (1 a 9), ele pegará um item para si, e o valor daquela posição será diminuida em uma unidade. Caso 4 itens seja acumulados pelo "hunter", e ele possuir a vida inferior à original (10 pontos de vida), ele trá trocar seus itens por 1 unidade de vida. Se o jogador possuir a vida completa e, mesmo assim, possuir 4 itens, eles serão jogados fora. Caso ele encontre um perigo (*), o "hunter" perderá 1 unidade de vida. E caso ele encontre uma parede (#), o jogador não poderá ir para aquela posição.<br>
Todos os elementos da matriz devem ser escaneadas e transferidas para o código de programação, que tem como objetivo realizar o caminhamento, operar o jogador (hunter), e salvar todos os dados obtidos. É importante salientar que as matrizes devem estar interconectadas, como se fossem um "único" caminho. O código deve se encerrar caso o "hunter" chega à vida zero ou caso ele não pegue mais itens durante o caminho (se o valor das posições percorridadas for igual à 0). No final do programa, é preciso apresentar como resultado: 
  
- Quantas casas foram percorridas ao todo.
- Qual a soma de itens consumidos pelo caminho.
- Quantas casas da matriz ficaram sem serem exploradas.
- Quantos perigos foram enfrentados ao decorrer do percurso. <br>

# Solução Proposta

# Casos Especiais

# Implementação

# Conclusão 

# Compilação e Execução
