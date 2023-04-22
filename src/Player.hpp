#ifndef __PLAYER_HPP
#define __PLAYER_HPP

using namespace std;

class Player
{
    private:
    short int vida;
    short int mochila;

    public:
    Player();
    void setVida(short int vida);
        short int getVida();
    void setMochila(short int mochila);
        short int getMochila();
};
#endif

