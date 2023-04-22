#include "Matriz.hpp"
int main()
{
    Matriz *jogo = new Matriz();
    short int tamanho, num_matrizes;
    string linha, nomearq="dataset/input.data";
    fstream arq;

    arq.open(nomearq);
    if (arq.is_open())
    {
        arq >> tamanho;
        arq >> tamanho;
        arq >> num_matrizes;
        string **mat = new string *[tamanho];
        for (short int i = 0; i < tamanho; i++)
            mat[i] = new string[tamanho];
        jogo->setTamanho(tamanho);
        jogo->setNum_matrizes(num_matrizes);
        jogo->Leitura(arq, mat, nomearq);
        jogo->VerMundo();
        jogo->Movimento(mat);
        jogo->VerMundo();
        jogo->VerTrajetoria();
    }

    arq.close();
}
