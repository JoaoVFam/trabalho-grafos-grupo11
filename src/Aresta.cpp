#include "Aresta.h"
#include <iostream>

using namespace std;

Aresta::Aresta()
{

    //construtor sem nenhum par�metro
}

Aresta::Aresta(int id_vertice_adjacente)
{
    this->id_vertice = id_vertice_adjacente;

}

Aresta::Aresta(int id_vertice_adjacente, int peso_aresta)
{
    this->id_vertice = id_vertice_adjacente;
    this->peso = peso_aresta;

}

Aresta::Aresta(int idprim, int idsec, int peso) {

    this->id_vertice = idprim;
    this->id_sec = idsec;
    this->peso = peso;



}



Aresta::~Aresta()
{

}

void Aresta::setIdVertice(int id)
{
    this->id_vertice = id;
}

int Aresta::getIdVertice()
{
    return this->id_vertice;
}


int Aresta::getPeso()
{
    return peso;
}

void Aresta::setPeso(int peso)
{
    this->peso = peso;
}
void Aresta::getIdSec(int id)
{

     this->id_sec=id;
}
