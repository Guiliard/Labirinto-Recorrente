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
- ```Movimento``` : Função que tem como objetivo pedir para o usuário escolher a posição de início do jogador na primeira matriz, movimentá-lo de forma randômica, ou seja, aleatória, sorteando umas das 8 possíveis direções cardeais e, além disso, verificar se o código pode ser encerrado (caso o "hunter" perca todos os seus pontos de vida ou se todo o caminho que ele percorra não seja diferente de zero). Por fim, vale exibir a relação entre o sorteio randômico e as 8 direções cardeias:
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
<div align=center>
<img src="https://user-images.githubusercontent.com/127882640/233478607-25dfe6bc-de75-4af7-85ce-29de3e1c73c1.png" width="850px">
</div>
<p  align="center">
Exemplo de caminhamento envolvendo duas matrizes quadradas (3x3). As setas verdes indicam as posições possíveis de serem acessadas, as vermelhas indicam as não possíveis, os círculos amarelos "P" indicam a localização dos portais. Junto a eles, existem as setas amarelas, as quais indicam para onde os portais levam o "hunter". Vale ressaltar que toda seta verde é dupla, ou seja, possível de ida e volta. Além disso, o caracter "P" dos portais pode assumir a identidade que qualquer caracter comum da matriz, seja um número natural de 0 a 9 (itens), seja uma parade (#), seja um perigo (*). Caso seja uma parede, aquele portal se torna inacessável.
</p>
 
# Casos Especiais
Tendo em vista que o "hunter" não pode caminhar onde existem paredes, é impossível de, na função ```Movimento``` , o usuário digitar uma posição que seja parede (#). Caso isso ocorra, o programa informará ao usuário sobre o ocorrido e pedirá para que ele digite uma nova posição diferente de parede.
<div align=center>
<img src="https://user-images.githubusercontent.com/127882640/233627558-c73038a8-bd8a-4a6b-98af-51eff20b4c34.png" hspace="50px" width="420px"/>
<img src="https://user-images.githubusercontent.com/127882640/233627635-b242f2b8-83e5-44d3-b6dd-0e6fc0ea32df.png" width="420px"/>
</div>
<p  align="center">
Exemplo da primeira posição ser parede.
</p>
<br>
Ademais, existe a possibilidade de, se o jogador entrar em um portal, a posição de chegada (linha 0 - coluna - 0) da próxima matriz seja uma parede (#). Caso isso ocorra, o portal transformará aquela parede em um baú de 4 itens (número natural 4), sendo que esse novo caracter será operado normalmente pelo "hunter" obedecendo as regras do programa.
<div align=center>
<img src="https://user-images.githubusercontent.com/127882640/233629917-836b54f9-566f-4e9e-9d18-747839a4564e.png" hspace="50px" width="420px"/>
<img src="https://user-images.githubusercontent.com/127882640/233629985-4aa8d018-3e9f-420f-a57c-4aadf71d894a.png" width="420px"/>
</div>
<p  align="center">
Exemplo da transformação da parede em um baú.
</p>

# Casos Sem Tratamento

Existem dois casos no programa que, se acontecerem, o código entra em loop infinito e não se encerra. O primeiro deles é se todas as posições de uma matriz for parede (#). Nesse caso, nenhuma posição da matriz é acessível pelo jogador, logo, o caminhamento se torna impossível.
O segundo caso é denominado "quarto fechado", que ocorre quando, na função ```Movimento``` , o usuário digita uma posição possível, mas, ao redor dela, só existem paredes, deixando o jogador preso em uma espécie de "quarto", o que também torna o caminhamento impossível.
<div align=center>
<img src="https://user-images.githubusercontent.com/127882640/233633727-3d084f38-1aa7-48cf-83a9-e18761b9dc70.png" hspace="50px" width="420px"/>
<img src="https://user-images.githubusercontent.com/127882640/233633747-c6fcec12-468d-4f47-afa5-e30ec9d3ba86.png" width="420px"/>
</div>
<p  align="center">
Exemplo de caminhamentos impossíveis. Em ambos os casos, o caracter "P" de portal assumi a identidade de uma parede (#).
</p>

# Implementação

Considere duas matrizes (6x6) como teste do problema proposto:
<div align=center>
<img src="https://user-images.githubusercontent.com/127882640/233639465-12d78a9f-a5c7-4eeb-afc2-b7ce053c5302.png" width="200px">
</div>
O resultado esperado é:<br>
<br><div align=center>
<img src="https://user-images.githubusercontent.com/127882640/233639840-78887137-d6c1-4b5f-8203-7bb1931cb1e5.png" width="850px">
<p  align="center">
Leitura das matrizes e fornecimento da posição de início pelo usuário. <br> <br>
</p>
<img src="https://user-images.githubusercontent.com/127882640/233640429-6177638c-3593-442b-b4b4-be7d9138bb70.png" width="750px">
<p  align="center">
Função CheckPoint. <br> <br>
</p>
<img src="https://user-images.githubusercontent.com/127882640/233640087-165f4535-2a62-4454-8d73-8c59d30e5312.png" hspace="50px" width="177px">
<img src="https://user-images.githubusercontent.com/127882640/233640196-1e2bb20e-66b3-43c9-9c43-0996e0b0393e.png" width="220px"> <br>
<p  align="center">
Primeiro output (matrizes alteradas) e segundo output (trajetória do "hunter"). <br> <br>
</p>
</div>

# Conclusão 

De forma geral, o programa, orientado à objeto, se mostra eficiente para resolver o caminhamento de matrizes de forma randômica. Seu custo computacional é diretamente proporcional ao tamanho da entrada, visto que um grande número de matrizes maiores demandará mais iterações e operações do que um pequeno número de matrizes menores. Por fim, afirma-se que o objetivo do trabalho foi cumprido com exelência, porém, o código é passivo de melhorias e otimizações, tais como aquelas discutidas na seção "Casos Sem Tratamento". 

# Compilação e Execução

Um arquivo Makefile que realiza todo o procedimento de compilação e execução está disponível no código. Para utilizá-lo, siga as diretrizes de execução no terminal:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build e todos os arquivos ".gm" gerados na pasta dataset |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
