#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <list>
#include "Aresta.h"

/*
*
*@Author grupo11
*
*
*/

using namespace std;


class Vertice
{
private:
    int ID; // id do vertice
    int grau; // grau do vertice
    int contAresta;


    int cor; //Cor do vertice
    list <int> idAdjascentes;
    bool multiAresta;

public:
    list<Aresta>ListaAresta;
    Vertice(); //contrutor sem parametros
    Vertice(int id); // contrutor passando o id do vertice
    ~Vertice(); // destrutor
    int getID(); // retorna o id do vertice
    int getGrau(); // retorna o grau do vertice

    void adicionaAresta(int id_vertice_adjacente); // adiciona uma aresta na lista de aresta
    void removeAresta(int id_vertice_adjacente); // remove uma aresta da lista de aresta

    void imprimirArestas(); // imprime todas as arestas


    bool temMultiAresta();
    void mostrarVizinhanca();
};

#endif // VERTICE_H
