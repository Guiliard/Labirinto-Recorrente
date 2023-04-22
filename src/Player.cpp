#include "Player.hpp"

Player :: Player()
{
    this->vida=10;
    this->mochila=0;
}

short int Player :: getVida()
{
    return vida;
}

short int Player :: getMochila()
{
    return mochila;
}

void Player :: setVida(short int vida)
{
    this->vida=vida;
}

void Player :: setMochila(short int mochila)
{
    this->mochila=mochila;
}