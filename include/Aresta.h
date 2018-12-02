#ifndef ARESTA_H
#define ARESTA_H

/*
*
*@Author grupo11
*
*
*/

using namespace std;


class Aresta
{
private:
    int id_vertice; // armazena o valor do id em que o grafo que cont�m essa aresta esta ligado
    int id_sec;     // id somente pra estrutura que armazena todas as arestas na estrutura grafo
    int peso; // peso da aresta


public:
    Aresta(); //contrutor
    Aresta(int id_vertice_adjacente); // contrutor com parametros
    Aresta(int id_vertice_adjacente, int peso_aresta);
    Aresta(int idprim , int idsec,int peso);
    ~Aresta(); // destrutor

    int getIdVertice(); // retorna o id do vertice
    int getIdSec(); //   retorna o id do vertice secundario pra estrutura auxiliar contida no grafo

    void setIdVertice(int id); // define o id do vertice
    void setIdSec (int id);


    int getPeso();
    void setPeso(int peso);
};

#endif // ARESTA_H
