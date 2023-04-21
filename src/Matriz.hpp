#ifndef __MATRIZ_HPP
#define __MATRIZ_HPP
#include "Player.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matriz
{
    private: 
        short int tamanho;
        short int num_matrizes;
        short int contaPassos;
        short int Itensconsumidos;
        short int Perigosenfrentados;
        short int casasexploradas;
        bool tudozero;
        bool teleporte;
        vector <short int> vectorespinhos;
        vector <short int> vectornumeros;

    public:
    Matriz();
    void setTamanho(short int tamanho);
        short int getTamanho();
    void setNum_matrizes(short int num_matrizes);
        short int getNum_matrizes();
    void setContapassos(short int contaPassos);
        short int getContapassos();
    void setItensconsumidos(short int Itensconsumidos);
        short int getItensconsumidos();
    void setPerigosenfrentados(short int Perigosenfrentados);
        short int getPerigosenfrentados();
    void setCasasexploradas(short int casasexploradas);
        short int getCasasexploradas();
    void Contaespinhos(short int *linha, short int *coluna, short int *mundo);
    void Leitura(fstream& arq, string **mat, string nomearq);
    void CriaMundo(string **mat, short int k);
    void CriaTrajetoria(string **mat);
    void VerMundo();
    void VerTrajetoria();
    void CheckPoint(Player *hunter);
    void Movimento(string **mat);
    void ComparaMundo(string **mat);
    void AndarMundo(Player *hunter, string **mat, short int *linha, short int *coluna, short int *mundo, short int maislinha, short int maiscoluna);
    void AtualizarMundo(string **mat, short int *mundo);
};
#endif
