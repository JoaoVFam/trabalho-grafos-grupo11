#ifndef ARESTA_H
#define ARESTA_H

/*
*
*@Author Joao Victor Lopes Fam
*
*
*/

using namespace std;


class Aresta
{
private:
    int id_vertice; // armazena o valor do id em que o grafo que cont�m essa aresta esta ligado
    int peso; // peso da aresta
    Aresta* prox;

public:
    Aresta(); //contrutor
    Aresta(int id_vertice_adjacente); // contrutor com parametros
    Aresta(int id_vertice_adjacente, int peso_aresta);
    ~Aresta(); // destrutor

    int getIdVertice(); // retorna o id do vertice

    void setIdVertice(int id); // define o id do vertice

    Aresta* getProx();
    void setProx(Aresta* prox);

    int getPeso();
    void setPeso(int peso);
};

#endif // ARESTA_H
