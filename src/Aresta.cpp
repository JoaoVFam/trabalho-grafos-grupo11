#include "Aresta.h"
#include <iostream>

using namespace std;

Aresta::Aresta()
{
    this->prox = NULL;
    //construtor sem nenhum parâmetro
}

Aresta::Aresta(int id_vertice_adjacente)
{
    this->id_vertice = id_vertice_adjacente;
    this->prox = NULL;
}

Aresta::Aresta(int id_vertice_adjacente, int peso_aresta)
{
    this->id_vertice = id_vertice_adjacente;
    this->peso = peso_aresta;
    this->prox = NULL;
}

Aresta::~Aresta()
{
    delete prox;
}

void Aresta::setIdVertice(int id)
{
    this->id_vertice = id;
}

int Aresta::getIdVertice()
{
    return this->id_vertice;
}

Aresta* Aresta::getProx()
{
    return prox;
}

void Aresta::setProx(Aresta* prox)
{
    this->prox = prox;
}

int Aresta::getPeso()
{
    return peso;
}

void Aresta::setPeso(int peso)
{
    this->peso = peso;
}
