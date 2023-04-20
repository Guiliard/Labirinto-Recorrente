<h1 align="center"> Labirinto-Recorrente </h1>
<div style="display: inline-block;">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg"/> 
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Contributions-welcome-brightgreen.svg?style=flat"/>
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Compilation-Make-orange.svg"/>
</div>
<br><div align=center>
<img src="https://user-images.githubusercontent.com/127882640/232782489-b924b25c-6224-463b-b180-1c43ec4591dd.png" width="850px">
</div>

# Introdução
<p>Foi proposto um problema de caminhamento de matrizes quadradas (NxN) de forma recorrente, ou seja, aquele que opta por um caminho alatório com possibilidade de retorno. No exercício, a movimentação se dá nas oito direções cardeais (Oeste, Sudoeste, Sul, Sudeste, Leste, Nordeste, Norte, Noroeste), e, também, em todas as matrizes existentes de forma conectada.</p> 

# Descrição do Problema
<p>Em um arquivo do tipo ".data", localiza-se um determinado número de matrizes quadradas, as quais possuem, em suas posições, três tipos de elementos: inteiros positivos (0 a 9), paredes (#) e perigos (*). Os inteiros positivos maiores que zero significam itens que podem ser consumidos, as paredes significam as posições que não podem ser acessadas, e o asterisco, os perigos a serem enfrentados.<br>
Na matriz, localiza-se, também, um jogador (hunter), sendo esse o personagem que a percorrerá de forma aleatória seguindo as seguintes regras:

- Caso o jogador encontre um inteiro positivo diferente de zero (1 a 9), ele pegará um item para si, e o valor daquela posição será diminuida em uma unidade. 
- Caso 4 itens seja acumulados pelo "hunter", e ele possuir a vida inferior à original (10 pontos de vida), ele irá trocar seus itens por 1 unidade de vida. 
- Se o jogador possuir a vida completa e, mesmo assim, tiver 4 itens, eles serão jogados fora. 
- Caso ele encontre um perigo (*), o "hunter" perderá 1 unidade de vida. 
- Caso ele encontre uma parede (#), o jogador não poderá ir para aquela posição.<br>

Todos os elementos da matriz devem ser escaneados e transferidos para o código de programação, que tem como objetivo realizar o caminhamento, operar o jogador (hunter), e salvar todos os dados obtidos. É importante salientar que as matrizes devem estar interconectadas, como se fossem um "único" caminho. O código deve se encerrar caso o "hunter" chegue à zero de vida ou caso ele não pegue mais itens durante o caminho (se o valor das posições percorridadas for igual à 0). No final do programa, é preciso apresentar como resultado: 
  
- Quantas casas foram percorridas ao todo.
- Qual a soma de itens consumidos pelo caminho.
- Quantas casas da matriz ficaram sem serem exploradas.
- Quantos perigos foram enfrentados ao decorrer do percurso. <br>

# Solução Proposta
<p>Para esse tipo de problema, foi proposto um código que contém 5 arquivos: Player.hpp, Player.cpp, Matriz.hpp, Matriz.cpp e Main.cpp.<br>

- ```Player.hpp``` : Classe que possui a declaração dos atributos (características) e métodos (funções) do jogador. <br>
- ```Player.cpp``` : Arquivo que retém a estruturação das funções envolvidas. <br>
- ```Matriz.hpp``` : Classe que possui a declaração de variáveis e funções envolvidas no processo de caminhamento. <br>
- ```Matriz.cpp``` : Arquivo que retém a estruturação das funções envolvidas. <br>
- ```Main.cpp``` : Arquivo mais importante, responsável por chamar as funções contidas nas classes e realizar o processo de caminhamento.<br>

Em primeiro lugar, destaca-se a lógica utilizada para "unificar" todas as matrizes como apenas um caminho. Imaginou-se que, em 3 posições pré-determinadas de qualquer matriz (linha 0 - coluna N , linha N - coluna 0 , linha N - coluna N), haveria-se um portal, o qual levaria o jogador para a posição inicial (linha 0 - coluna 0) da próxima matriz, sendo que os portais da última matriz dariam acesso à posição inicial da primeira. Com isso, tem-se a unificação do caminho. <br>
Outro ponto importante é a forma que o carregamento das matrizes foi realizado. Tendo em vista que o número de matrizes não é determinado, carregar todas elas em memória seria uma alternativa de demandaria um enorme custo, ou seja, negativo para o processamento. Para contornar essa situação, carregamentos de matrizes em arquivos do tipo ".gm" foram utilizados, sendo que cada arquivo ".gm" armazenaria uma matriz. Com isso, obtém-se um baixo custo de memória e uma otimização do programa.    
Dito esses assuntos, vale ressaltar as onze funções declaradas no arquivo Matriz.cpp, as quais tornam todo o processo possível:

- ```AndarMundo``` : Função responsável por movimentar o "hunter", a qual analisa se a posição da matriz é acessável ou não. Caso seja acessável, ela fará o jogador se deslocar e, também, fará todos os procedimentos necessários após esse caminhamento, como pegar item, armazenar esse item na mochila do jogador, diminuir o total de itens que aquela posição possui, ganhar vida, perder vida, zerar a mochila, se teletransportar ou não fazer nada.  
- ```AtualizarMundo``` : Função que possui como objetivo atualizar o arquivo que contém a matriz caminhada pelo jogador, deixado em evidência as casas percorridas por ele.
- ```CheckPoint``` : Função responsável por registrar as informações finais sobre caminhamento realizado pelo "hunter", tais como:
  * Total de vida
  * Total de casas percorridas
  * Total de itens consumidos
  * Total de perigos enfrentados
  * Total de casas inexploradas  
- ```ComparaMundo``` : Função que possui como objetivo comparar a matriz original (antes do caminhamento) com a matriz alterada (depois do caminhamento), para que, assim, saiba-se com exatidão por onde o "hunter" passou.
- ```ContaEspinhos``` : Função responsável por contar por quantos perigos (espinhos - *) diferentes o jogador acessou.
- ```CriaMundo``` : Função que cria os arquivos do tipo ".gm", os quais serão operados ao longo do programa.
- ```CriaTrajetoria``` : Função que cria um arquivo específico do tipo ".gm" que mostra, através de um marcador (x), todas as posições de todas as matrizes que "hunter" passou.
- ```Leitura``` : Função responsável por ler um arquivo, seja ele do tipo ".data" ou ".gm" e carregá-lio em uma matriz.
- ```Movimento``` : Função que tem como objetivo movimentar o jogador de forma randômica, ou seja, aleatória, sorteando umas das 8 possíveis direções cardeais, obedecendo a seguinte relação:
  * 0 - Leste
  * 1 - Sudeste
  * 2 - Sul
  * 3 - Sudoeste
  * 4 - Oeste
  * 5 - Noroeste
  * 6 - Norte 
  * 7 - Nordeste
- ```VerMundo``` : Função responsável por mostrar todos os arquivos ".gm" que contém todas as matrizes alteradas (após o caminhamento).
- ```VerTrajetoria``` : Função que mostra o arquivo ".gm" que possui todas as posições de todas as matrizes nas quais o "hunter" passou.

Com a interconexão de todas essas funções, o caminhamento do jogador por todas as matrizes se torna possível e real.

# Casos Especiais

# Implementação

# Conclusão 

# Compilação e Execução
