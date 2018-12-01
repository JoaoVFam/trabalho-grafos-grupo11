#ifndef GRAFOLISTAADJ_H
#define GRAFOLISTAADJ_H
#include <list>
#include "GrafoListaAdj.h"
#include "Vertice.h"
#include <iostream>

using namespace std;
/*
*
*@Author grupo11
*
*/

class GrafoListaAdj
{
private:
    list <Vertice> vertices; //lista de vertices que compoem o grafo
    int k; //Quantidade de cores
    bool trivial;
    bool nulo = false;

    int** geraMatrizesFloyd();
    void auxBuscaProfundidade(int* visitados, int vertice_inicial, int cont);


public:
    GrafoListaAdj(); //contrutor
    GrafoListaAdj(int num_vertices); // construtor passando o numero de vertices
    ~GrafoListaAdj(); // destrutor

    void adicionarVertice(int ID); //adiciona um vertice na lista de vertices
    void adicionarVertice(Vertice v);
    void removerVertice(int ID); //remove um vertice da lista procurando-o por seu id
    void adicionarAresta(int id_vertice_1, int id_vertice_2); // adiciona uma liga��o entre dois vertices
    void removerAresta(int id_vertice_1, int id_vertice_2); // remove a liga��o entre dois vertices

    void adicionaArestaDirecionada(int id_vertice_saida, int id_vertice_entrada);
    void removeArestaDirecionada(int id_vertice_saida, int id_vertice_entrada);

    Vertice getVertice(int id_vertice);
    Aresta getAresta(int id_vertice_1, int id_vertice_2);

    int getGrau(int id_vertice); // retorna o grau de um vertice
    int getGrauSaida(int id_vertice);
    int getGrauEntrada(int id_vertice);
    int getOrdem(); // retorna o numero de vertices

    void adicionaPesoAresta(int id_vertice_1, int id_vertice_2, int peso); //apenas para grafos não direcionadoss
    int getPesoAresta(int id_vertice_1, int id_vertice_2); //apenas para grafos não direcionados

    void imprimirVertices(); // imprime a lista de vertices existentes
    void imprimirArestas(int id_vertice); // imprime a lista de arestas de um dado vertice

    bool verificarKRegularidade(int k);
    void setTrivial(bool a);
    void setNulo();
    void mostrarVizinhancaAberta(int id_vertice);
    void mostrarVizinhancaFechada(int id_vertice);

    bool isCompleto();
    bool isTrivial();
    bool isNulo();
    //bool isMultigrafo();

    void imprimeSequenciaGraus();
    void defineCor (Vertice v);

    GrafoListaAdj algoritmoKruskal();
    bool isBipartido();

    int caminhoMinimoFloyd(int id_origem, int id_destino);
    int* buscaProfundidade(int vertice_inicial);

    list<int> fechoTransitivoDireto(int id_vertice);
    list<int> fechoTransitivoIndireto(int id_vertice);

};

#endif // GRAFO_H
