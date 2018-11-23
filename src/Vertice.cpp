#include "Vertice.h"
#include <list>
#include <iostream>
#include <iterator>


using namespace std;

Vertice::Vertice()
{
    this->contAresta = 0;
    this->grau = 0;
    this->primeiraAresta = NULL;
    this->cor = 0;
    //contrutor sem par�metros, n�o � feito nada nele
}

Vertice::Vertice(int id) {
    //this->contAresta = 0;
    this->grau = 0;
    this->ID = id;
    this->primeiraAresta = NULL;
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
    Aresta* aresta = new Aresta(id_vertice_adjacente); //instacia novo objeto do tipo aresta
    aresta->setProx(primeiraAresta);
    primeiraAresta = aresta;
}

void Vertice::removeAresta(int id_vertice_adjacente){
    if(this->primeiraAresta == NULL){
        cout << "        LISTA VAZIA" << endl;
    // se j� � o primeiro, desvie o quanto antes para removePrimeiraAresta
    } else if(this->primeiraAresta->getIdVertice() == id_vertice_adjacente) {
        this->removePrimeiraAresta();
        return;
    } else {
        Aresta* anterior = primeiraAresta; //inicializa a aresta anterior com a primeira da lista
        Aresta* atual = anterior->getProx(); //a aresta atual com a pr�xima aresta
        while(atual != NULL) {
            if(atual->getIdVertice() == id_vertice_adjacente) {
                break; //se achou n�o precisa continuar procurando
            } else { //j� que vai analisar outro item, ent�o atualiza as arestas
                anterior = atual;
                atual = atual->getProx();
            }
        }
        if(atual != NULL) { //se chegou no fim sem achar nada, nada deve ser feito
            anterior->setProx(atual->getProx()); //atualiza a lista pegando o pr�ximo do atual
            delete atual; //mata o atual
            this->grau--;
        }
    }
}

void Vertice::imprimirArestas(){ // imprime os ids dos vertice que esse vertice est� ligado
    cout << "Lista de arestas (vertice " << this->ID << "): ";
    for(Aresta* a = this->primeiraAresta; a != NULL; a = a->getProx()){
        cout << a->getIdVertice() << " ";
    }
    cout << endl;
}

void Vertice::removePrimeiraAresta() {
    Aresta* p = this->primeiraAresta;
    this->primeiraAresta = p->getProx();
    delete p;
    this->grau--;
}

Aresta* Vertice::getListaArestas() {
    return this->primeiraAresta;
}

void Vertice::mostrarVizinhanca() {
    Aresta* p = this->primeiraAresta;
    cout << "Vertices adjacentes ao vertice " << this->getID() << ": ";
    while(p != NULL) {
        cout << p->getIdVertice() << " ";
        p = p->getProx();
    }
    cout << endl;
}


int Vertice::getCor(){
    return this->cor;
}

void Vertice::setCor(int cor){
    this->cor = cor;
}

bool Vertice::temMultiAresta() {
    return multiAresta;
}
