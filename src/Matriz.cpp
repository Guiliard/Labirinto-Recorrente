#include "Matriz.hpp"

Matriz ::Matriz()
{
    this->contaPassos=0;
    this->Itensconsumidos=0;
    this->Perigosenfrentados=0;
    this->casasexploradas=0;
    this->tudozero=true;
    this->teleporte=false;
}

short int Matriz ::getTamanho()
{
    return tamanho;
}

short int Matriz ::getNum_matrizes()
{
    return num_matrizes;
}

short int Matriz :: getContapassos()
{
    return contaPassos;
}

short int Matriz :: getItensconsumidos()
{
    return Itensconsumidos;
}

short int Matriz :: getPerigosenfrentados()
{
    return Perigosenfrentados;
}

short int Matriz :: getCasasexploradas()
{
    return casasexploradas;
}

void Matriz ::setTamanho(short int tamanho)
{
    this->tamanho = tamanho;
}

void Matriz ::setNum_matrizes(short int num_matrizes)
{
    this->num_matrizes = num_matrizes;
}

void Matriz :: setContapassos(short int contaPassos)
{
    this->contaPassos = contaPassos;
}

void Matriz :: setItensconsumidos(short int Itensconsumidos)
{
    this->Itensconsumidos = Itensconsumidos;
}

void Matriz :: setPerigosenfrentados(short int Perigosenfrentados)
{
    this->Perigosenfrentados = Perigosenfrentados;
}

void Matriz :: setCasasexploradas(short int casasexploradas)
{
    this->casasexploradas = casasexploradas;
}

void Matriz :: Contaespinhos(short int *linha, short int *coluna, short int *mundo)
{
    bool confere = true;
    if(vectorespinhos.size()==0)
    {
        vectorespinhos.push_back(*linha);
        vectorespinhos.push_back(*coluna);
        vectorespinhos.push_back(*mundo);
        setCasasexploradas(getCasasexploradas()+1);
    }
    else
    {
        for(long unsigned int i=0; i<vectorespinhos.size(); i=i+3)
        {
            if(vectorespinhos[i]==*linha && vectorespinhos[i+1]==*coluna && vectorespinhos[i+2]==*mundo)
                confere = false;
        }
        if(confere==true)
        {
            vectorespinhos.push_back(*linha);
            vectorespinhos.push_back(*coluna);
            vectorespinhos.push_back(*mundo);
            setCasasexploradas(getCasasexploradas()+1);   
        }
    }
}

void Matriz ::Leitura(fstream &arq, string **mat, string nomearq) // carrega matrizes
{
    short int k = 0;
    while (!arq.eof())
    {
        string linha;
        vector<string> vectorfrase;
        if (k == 0 && nomearq == "dataset/input.data")
            getline(arq, linha);
        getline(arq, linha);
        if (linha.empty() == true)
            return;
        char *caracter, vector[linha.length() - 1];
        strcpy(vector, linha.c_str());
        for (short int i = 0; i < getTamanho(); i++)
        {
            caracter = strtok(vector, " ");
            while (caracter)
            {
                vectorfrase.push_back(caracter);
                caracter = strtok(NULL, " "); // até o caracter ser nulo
            }
            if (i != getTamanho())
            {
                getline(arq, linha);
                strcpy(vector, linha.c_str());
            }
        }
        short int progresso = 0;
        for (short int i = 0; i < getTamanho(); i++)
        {
            for (short int j = 0; j < getTamanho(); j++)
            {
                mat[i][j] = vectorfrase[progresso];
                progresso++;
            }
        }
        if(nomearq=="dataset/input.data")
        {   
            CriaMundo(mat, k);
            k++;
        }
    }
}

void Matriz ::CriaMundo(string **mat, short int k)
{
    string nome, nome2;
    string numero, numero2;
    fstream file, file2;
    nome = "dataset/Mundo";
    nome2 = "dataset/MundoAntigo";
    numero = to_string(k + 1);
    numero2 = to_string(k + 1);
    nome = nome + numero + ".gm";
    nome2 = nome2 + numero2 + ".gm";
    file.open(nome, std::fstream::out);
    file2.open(nome2, std::fstream::out);
    for (short int i = 0; i < getTamanho(); i++)
    {
        for (short int j = 0; j < getTamanho(); j++)
        {
            file << mat[i][j] << " ";
            file2 << mat[i][j] << " ";
        }
        file << "\n";
        file2 << "\n";
    }
    file.close();
    file2.close();
}
void Matriz :: CriaTrajetoria(string **mat)
{
    short int k=0;
    vector<short int> aux;
    string nome;
    fstream file;
    nome = "dataset/Trajetória.gm";
    file.open(nome, std::fstream::out);
    while(k<getNum_matrizes())
    {
        for(short int i=0; i<getTamanho(); i++)
        {
            for(short int j=0; j<getTamanho(); j++)
                mat[i][j]=to_string(0);
        }
        for(long unsigned int i=0; i<vectorespinhos.size(); i=i+3)
        {
            if(vectorespinhos[i+2]==k)
                mat[vectorespinhos[i]][vectorespinhos[i+1]]="x";
        }
        for(long unsigned int i=0; i<vectornumeros.size(); i=i+3)
        {
            if(vectornumeros[i+2]==k)
                mat[vectornumeros[i]][vectornumeros[i+1]]="x";
        }
        for(short int i=0; i<getTamanho(); i++)
        {
            for(short int j=0; j<getTamanho(); j++)
                file << mat[i][j] << " ";
            file << endl;
        }
        file << endl;
        k++;
    }
    file.close();
}

void Matriz ::VerMundo()
{
    short int mundo = 0;
    string numero, nome, linha;
    for (short int i = 0; i < getNum_matrizes(); i++)
    {
        cout << "\n[MUNDO " << mundo + 1 << "]\n\n";
        nome = "dataset/Mundo";
        numero = to_string(mundo + 1);
        nome = nome + numero + ".gm";
        fstream arq(nome);
        for (short int j = 0; j < getTamanho(); j++)
        {
            getline(arq, linha);
            linha = linha + "\n";
            cout << linha;
        }
        nome = "\0";
        linha = "\0";
        arq.close();
        mundo++;
    }
}

void Matriz :: VerTrajetoria()
{
    string nome, linha;
    cout << "\n[TRAJETÓRIA]\n\n";
    nome = "dataset/Trajetória.gm";
    fstream arq(nome);
    for (short int i = 0; i < getNum_matrizes(); i++)
    {
        for (short int j = 0; j < getTamanho(); j++)
        {
            getline(arq, linha);
            linha = linha + "\n";
            cout << linha;
        }
        getline(arq,linha);
        cout << endl;
    }
    arq.close();
}
void Matriz :: CheckPoint(Player *hunter)
{
    cout << "\nJOGO ENCERRADO!\n";
    cout << "Total de vida do jogador: " << hunter->getVida() << "\n";
    cout << "Total de casas percorridas pelo jogador: " << getContapassos() << "\n";
    cout << "Total de itens consumidos pelo jogador: " << getItensconsumidos() << "\n";
    cout << "Total de perigosos enfrentados pelo jogador: " << getPerigosenfrentados() << "\n";
    cout << "Total de casas inexploradas pelo jogador: " << getTamanho()*getTamanho()*getNum_matrizes() - getCasasexploradas() << "\n";
    cout << "Obrigado por Jogar!\n";
}

void Matriz ::Movimento(string **mat)
{
    Player *hunter = new Player();
    unsigned seed = time(0);
    short int lugar;
    short int linha = 0, coluna = 0, mundo = 0;
    short int maislinha = 0, maiscoluna = 0;
    bool valido = true;
    string nome = "dataset/Mundo";
    string numero = to_string(mundo + 1);
    nome = nome + numero + ".gm";
    fstream arq(nome);
    Leitura(arq, mat, nome);
    cout << "\nAtenção! O jogador começará na posição indicada!";
    cout << "\nDigite as coordenadas da Mundo 1 (linha - de 0 a " << getTamanho() - 1 << " - coluna - de 0 a " << getTamanho() - 1 << ") para o início do jogo:\n";
    while (valido == true)
    {
        cout << "Linha:";
        cin >> linha;
        cout << "Coluna:";
        cin >> coluna;
        if (mat[linha][coluna] == "#")
        {
            valido = true;
            cout << "\nO jogador não poder começar em uma parede. Favor digitar novamente:\n";
        }
        else
            valido = false;
    }
    AndarMundo(hunter, mat, &linha, &coluna, &mundo, maislinha, maiscoluna);
    srand(seed);
    while (hunter->getVida() > 0)
    {
        lugar = rand() % 8;
        if (lugar == 0)
        {
            if (coluna != getTamanho() - 1)
            {
                maislinha = 0;
                maiscoluna = 1;
                AndarMundo(hunter, mat, &linha, &coluna, &mundo, maislinha, maiscoluna);
            }
        }
        else if (lugar == 1)
        {
            if (linha != getTamanho() - 1 && coluna != getTamanho() - 1)
            {
                maislinha = 1;
                maiscoluna = 1;
                AndarMundo(hunter, mat, &linha, &coluna, &mundo, maislinha, maiscoluna);
            }
        }
        else if (lugar == 2)
        {
            if (linha != getTamanho() - 1)
            {
                maislinha = 1;
                maiscoluna = 0;
                AndarMundo(hunter, mat, &linha, &coluna, &mundo, maislinha, maiscoluna);
            }
        }
        else if (lugar == 3)
        {
            if (linha != getTamanho() - 1 && coluna != 0)
            {
                maislinha = 1;
                maiscoluna = -1;
                AndarMundo(hunter, mat, &linha, &coluna, &mundo, maislinha, maiscoluna);
            }
        }
        else if (lugar == 4)
        {
            if (coluna != 0)
            {
                maislinha = 0;
                maiscoluna = -1;
                AndarMundo(hunter, mat, &linha, &coluna, &mundo, maislinha, maiscoluna);
            }
        }
        else if (lugar == 5)
        {
            if (linha != 0 && coluna != 0)
            {
                maislinha = -1;
                maiscoluna = -1;
                AndarMundo(hunter, mat, &linha, &coluna, &mundo, maislinha, maiscoluna);
            }
        }
        else if (lugar == 6)
        {
            if (linha != 0)
            {
                maislinha = -1;
                maiscoluna = 0;
                AndarMundo(hunter, mat, &linha, &coluna, &mundo, maislinha, maiscoluna);
            }
        }
        else if (lugar == 7)
        {
            if (linha != 0 && coluna != getTamanho() - 1)
            {
                maislinha = -1;
                maiscoluna = +1;
                AndarMundo(hunter, mat, &linha, &coluna, &mundo, maislinha, maiscoluna);
            }
        }
        if(linha==0 && coluna==0 && mundo==0 && teleporte==true)
        {
            if(tudozero==true)
                break;
            else
            {
                tudozero=true;
                teleporte=false;  
            } 
        } 
    }
    ComparaMundo(mat);
    CheckPoint(hunter);
    CriaTrajetoria(mat);
}

void Matriz :: ComparaMundo(string **mat)
{
    short int k=0;
    string nome, nome2;
    string numero, numero2;
    string **mataux = new string *[getTamanho()];
        for (short int i = 0; i < getTamanho(); i++)
            mataux[i] = new string[getTamanho()];
    while(k<getNum_matrizes())
    {
        nome = "dataset/Mundo";
        nome2 = "dataset/MundoAntigo";
        numero = to_string(k + 1);
        numero2 = to_string(k + 1);
        nome = nome + numero + ".gm";
        nome2 = nome2 + numero2 + ".gm";
        fstream file(nome), file2(nome2);
        Leitura(file, mat, nome);
        Leitura(file2, mataux, nome2);
        for(short int i = 0; i < getTamanho(); i++)
        {
            for(short int j = 0; j < getTamanho(); j++)
                if(mat[i][j] != mataux[i][j])
                {
                    setCasasexploradas(getCasasexploradas()+1);
                    vectornumeros.push_back(i);
                    vectornumeros.push_back(j);
                    vectornumeros.push_back(k);
                }
        }
        k++;
    }
}

void Matriz :: AtualizarMundo(string **mat, short int *mundo)
{
    string nome;
    string numero;
    ofstream file;
    nome = "dataset/Mundo";
    numero = to_string(*mundo + 1);
    nome = nome + numero + ".gm";
    file.open(nome);
    for (short int i = 0; i < getTamanho(); i++)
    {
        for (short int j = 0; j < getTamanho(); j++)
            file << mat[i][j] << " ";
        file << endl;
    }
    file.close();
}

void Matriz ::AndarMundo(Player *hunter, string **mat, short int *linha, short int *coluna, short int *mundo, short int maislinha, short int maiscoluna)
{
    short int converter = 0;
    if (mat[*linha + maislinha][*coluna + maiscoluna] == "#")
        cout << "";
    else if (mat[*linha + maislinha][*coluna + maiscoluna] == "*")
    {
        hunter->setVida(hunter->getVida() - 1);
        setPerigosenfrentados(getPerigosenfrentados()+1);
        *linha = *linha + maislinha;
        *coluna = *coluna + maiscoluna;
        Contaespinhos(linha, coluna, mundo);
        setContapassos(getContapassos()+1);
        if (hunter->getVida() == 0)
            AtualizarMundo(mat, mundo);
    }
    else
    {
        *linha = *linha + maislinha;
        *coluna = *coluna + maiscoluna;
        setContapassos(getContapassos()+1);
        converter = stoi(mat[*linha][*coluna]);
        if (converter != 0)
        {
            tudozero=false;
            hunter->setMochila(hunter->getMochila() + 1);
            setItensconsumidos(getItensconsumidos()+1);
            converter = converter - 1;
            mat[*linha][*coluna] = to_string(converter);
            if (hunter->getMochila() == 4 && hunter->getVida() < 10)
            {
                hunter->setVida(hunter->getVida() + 1);
                hunter->setMochila(0);
            }
            else if (hunter->getMochila() == 4 && hunter->getVida() == 10)
                hunter->setMochila(0);
        }
        else
            setContapassos(getContapassos()+1);
    }
    if ((*linha == getTamanho() - 1 && *coluna == 0) || (*linha == getTamanho() - 1 && *coluna == getTamanho() - 1) || (*linha == 0 && *coluna == getTamanho() - 1)) // portal
    {
        *linha = 0;
        *coluna = 0;
        setContapassos(getContapassos()+1);
        if (*mundo == getNum_matrizes() - 1)
        {
            AtualizarMundo(mat, mundo);
            *mundo = 0;
            string nome = "dataset/Mundo";
            string numero = to_string(*mundo + 1);
            nome = nome + numero + ".gm";
            fstream arq(nome);
            Leitura(arq, mat, nome);
            teleporte=true;
        }
        else
        {
            AtualizarMundo(mat, mundo);
            *mundo = *mundo + 1;
            string nome = "dataset/Mundo";
            string numero = to_string(*mundo + 1);
            nome = nome + numero + ".gm";
            fstream arq(nome);
            Leitura(arq, mat, nome);
        }
        if (mat[*linha][*coluna] == "#")
        {
            mat[*linha][*coluna] = "4";
            hunter->setMochila(hunter->getMochila() + 1);
            setItensconsumidos(getItensconsumidos()+1);
            cout << "O jogador ganhou 1 item!\n";
            converter = stoi(mat[*linha][*coluna]);
            converter = converter - 1;
            mat[*linha][*coluna] = to_string(converter);
            if (hunter->getMochila() == 4 && hunter->getVida() < 10)
            {
                hunter->setVida(hunter->getVida() + 1);
                hunter->setMochila(0);
            }
            else if (hunter->getMochila() == 4 && hunter->getVida() == 10)
                hunter->setMochila(0);
        }
        else if (mat[*linha][*coluna] == "*")
        {
            hunter->setVida(hunter->getVida() - 1);
            setPerigosenfrentados(getPerigosenfrentados()+1);
            Contaespinhos(linha, coluna, mundo);
            if (hunter->getVida() == 0)
                AtualizarMundo(mat, mundo);
        }
        else
        {
            converter = stoi(mat[*linha][*coluna]);
            if (converter != 0)
            {
                tudozero=false;
                hunter->setMochila(hunter->getMochila() + 1);
                setItensconsumidos(getItensconsumidos()+1);
                converter = converter - 1;
                mat[*linha][*coluna] = to_string(converter);
                if (hunter->getMochila() == 4 && hunter->getVida() < 10)
                {
                    hunter->setVida(hunter->getVida() + 1);
                    hunter->setMochila(0);
                }
                else if (hunter->getMochila() == 4 && hunter->getVida() == 10)
                    hunter->setMochila(0);
            }
        }
    }
}
