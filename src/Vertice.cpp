#include "Vertice.h"
#include <list>
#include <iostream>
#include <iterator>


using namespace std;

Vertice::Vertice()
{
    this->contAresta = 0;
    this->grau = 0;
    this->cor = 0;
    //contrutor sem par�metros, n�o � feito nada nele
}

Vertice::Vertice(int id) {
    //this->contAresta = 0;
    this->grau = 0;
    this->ID = id;
    this->cor = 0;
    //contrutor passando o id do vertice
}

Vertice::~Vertice()
{
    //dtor
}

int Vertice::getID(){
    return this->ID; // retorna o id do vertice
}

int Vertice::getGrau(){
    return this->grau; // retorna grau do vertice
}

void Vertice::adicionaAresta(int id_vertice_adjacente) {
    this->grau++; //incrementa o numero de graus do vertice
    list <int>::iterator it;
    for(it = this->idAdjascentes.begin(); it != this->idAdjascentes.end(); ++it) {
        int idAdjacente = (int) * it; //pega valor da lista apontado por it
        if(idAdjacente == id_vertice_adjacente) {
            this->multiAresta = true;
        }
    }
    idAdjascentes.push_back(id_vertice_adjacente);
    Aresta novaAresta = Aresta(id_vertice_adjacente);
    this->ListaAresta.push_back(novaAresta);
}

void Vertice::removeAresta(int id_vertice_adjacente) {
    std::list<Aresta>::iterator i;
    for (i = ListaAresta.begin(); i != ListaAresta.end(); i++) {
        if (i->getIdVertice() == id_vertice_adjacente) {
            ListaAresta.erase(i);
            grau--;
        }


    }
}
void Vertice::imprimirArestas(){ // imprime os ids dos vertice que esse vertice est� ligado
    std::list <Aresta>::iterator i;
    for(i=ListaAresta.begin();i!=ListaAresta.end();i++){

        cout<< "" << i->getIdVertice();
    }

}

void Vertice::mostrarVizinhanca() {
    std::list <Aresta>::iterator i;
    cout << "Vertices adjacentes ao vertice " << this->getID() << ": ";
    for (i = ListaAresta.begin(); i != ListaAresta.end(); i++) {
        cout << i->getIdVertice() << " ";
    }
    cout << endl;
}





bool Vertice::temMultiAresta() {
    return multiAresta;
}
