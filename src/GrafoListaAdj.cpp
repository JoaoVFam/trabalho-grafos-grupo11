#include "GrafoListaAdj.h"
#include <list>
#include <stdlib.h>
#include <stdio.h>
#include <values.h>

const int INF = INT_MAX/2;

using namespace std;

GrafoListaAdj::GrafoListaAdj()
{
    k = 24;
    //construtor
}

GrafoListaAdj::GrafoListaAdj(int num_vertices) // construtor passando o numero de vertices do grafo
{
    k = 24;
    for(int i = 0; i < num_vertices; i++) { // itera sobre o numero de vertices passado
        Vertice vertice = Vertice(i); // instancia um objeto do tipo vertice passando i como id
        this->vertices.push_back(vertice); // adiciona o veertice instanciado na lista de vertices do grafo
    }
}

GrafoListaAdj::~GrafoListaAdj()
{
    //dtor
}

void GrafoListaAdj::adicionarVertice(int id) { // adiciona um vertice com o d passado por parametro
    Vertice vertice = Vertice(id); // instancia o objeto
    vertices.push_back(vertice); // adiciona o vertice na lista de vertices do grafo
}

void GrafoListaAdj::adicionarVertice(Vertice v) {
    vertices.push_back(v);
}

void GrafoListaAdj::removerVertice(int id) { // remove um vertice da lista de acordo com id passado por parametro
    list <Vertice>::iterator it; // iterador de uma lista de vertices

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it) { // itera sobre a lista de vertices do grafo
        if(it->getID() == id){ // compara o id dos vertices com o id passado por parametro
            this->vertices.erase(it); // apaga o vertice da lista
            break; // finaliza o la�o de repeti��o
        }
    }
}

void GrafoListaAdj::adicionarAresta(int id_vertice_1, int id_vertice_2) { // adiciona nas listas de arestas dos dois vertices o id um no outro
    list <Vertice>::iterator it; // iterador de uma lista de vertices

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){ // itera sobre a lista de vertices do grafo

        if(it->getID() == id_vertice_1) // compara o id do vertice com o id 1
            it->adicionaAresta(id_vertice_2); // adiciona uma aresta na lista de vertices do vertice 1, uma aresta que representa o vertice 2
        if(it->getID() == id_vertice_2) // compara o id do vertice com o id 2
            it->adicionaAresta(id_vertice_1); // adiciona uma aresta na lista de vertices do vertice 2, uma aresta que representa o vertice 1
    }
}

void GrafoListaAdj::removerAresta(int id_vertice_1, int id_vertice_2){ // remove nas listas de arestas dos vertices a aresta que relacionam esses dois vertices
    list <Vertice>::iterator it; // iterador

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){ // itera sobre a lista de vertces do grafo
        if(it->getID() == id_vertice_1) // compara o id do vertice com o id 1
            it->removeAresta(id_vertice_2); // remove a aresta do vertice 1 que representa o vertice 2
        if(it->getID() == id_vertice_2) // compara o id do vertice com o id 2
            it->removeAresta(id_vertice_1); // remove a aresta do vertice 2 que representa o vertice 1
    }
}

void GrafoListaAdj::adicionaArestaDirecionada(int id_vertice_saida, int id_vertice_entrada) {
    list <Vertice>::iterator it;

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it) {
        if(it->getID() == id_vertice_saida) {
            it->adicionaAresta(id_vertice_entrada);
            break;
        }
    }
}

void GrafoListaAdj::removeArestaDirecionada(int id_vertice_entrada, int id_vertice_saida) {
    list <Vertice>::iterator it;

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it) {
        if(it->getID() == id_vertice_saida) {
            it->removeAresta(id_vertice_entrada);
            break;
        }
    }
}

Vertice GrafoListaAdj::getVertice(int id_vertice) {
    list <Vertice>::iterator it;

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it) {
        if(it->getID() == id_vertice)
            return *it;
    }
}

int GrafoListaAdj::getGrau(int id_vertice){ // retorna o grau de um vertice com o id passado por parametro
    list <Vertice>::iterator it; // iterador

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){ // itera sobre a lista de vertices do grafo
        if(it->getID() == id_vertice){ // procura o vertice que tem o id igual ao passado por par�metro
            return it->getGrau(); // retorna o grau desse vertice
        }
    }
}

int GrafoListaAdj::getGrauSaida(int id_vertice) {
    list <Vertice>::iterator it; //iterador

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it) {
        return it->getGrau(); //o valor do grau armazenado corresponde ao valor do grau de sa�da
    }
}

int GrafoListaAdj::getGrauEntrada(int id_vertice) {
    int grauEntrada = 0;
    list <Vertice>::iterator it;
    for(it = this->vertices.begin(); it != this->vertices.end(); ++it) {
        Aresta* aresta = it->getListaArestas();
        while(aresta != NULL) {
            if(aresta->getIdVertice() == id_vertice) {
                grauEntrada++;
                break;
            }
            aresta = aresta->getProx();
        }
    }
    return grauEntrada;
}

int GrafoListaAdj::getOrdem(){ // retorna o tamanho da lista de vertices
    return this->vertices.size();
}

void GrafoListaAdj::imprimirVertices() { // imprime uma listagem com os id dos vertices presentes no grafo
    list <Vertice>::iterator it;

    cout << "Vertices do grafo: ";
    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){
        cout << it->getID() << " ";
    }
    cout << endl;
}

void GrafoListaAdj::imprimirArestas(int id_vertice){ // imprime uma listagem da arestas de um vertice que tem id igual ao passado por parametro
    list <Vertice>::iterator it;

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){
        if(it->getID() == id_vertice){
            it->imprimirArestas();
        }
    }
}

bool GrafoListaAdj::verificarKRegularidade(int k) {
    list <Vertice>::iterator it;

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){
        if(it->getGrau() != k)
            return false;
    }
    return true;
}

void GrafoListaAdj::mostrarVizinhancaAberta(int id_vertice) {
    list <Vertice>::iterator it;

    for(it = this->vertices.begin(); it!= this->vertices.end(); ++it) {
        if(it->getID() == id_vertice) {
            it->mostrarVizinhanca();
        }
    }
}

void GrafoListaAdj::mostrarVizinhancaFechada(int id_vertice) {
    this->mostrarVizinhancaAberta(id_vertice);
    cout << "mais id do proprio vertice: " << id_vertice << endl;
}

bool GrafoListaAdj::isCompleto() {
    list <Vertice>::iterator it;

    for(it = this->vertices.begin(); it!= this->vertices.end(); ++it) {
        if(it->getGrau() != vertices.size()-1){
            return false;
            break;
        }
    }
    return true;
}

void GrafoListaAdj::imprimeSequenciaGraus() {
    int numVertices = vertices.size();
    int graus[numVertices];

    list <Vertice>::iterator it;

    int k = 0;
    for(it = this->vertices.begin(); it!=this->vertices.end(); ++it) {
        graus[k] = (int) it->getGrau();
        k++;
    }

    //ordena��o do vetor em ordem decrescente
    for(int i = 0; i<numVertices; i++) {
        for(int j = i+1; j<numVertices; j++) {
            if(graus[i] < graus[j]) {
                int aux = graus[i];
                graus[i] = graus[j];
                graus[j] = aux;
            }
        }
    }

    cout << "Sequencia dos graus: ";
    for(int i=0; i<numVertices; i++) {
        cout << graus[i] << ", ";
    }
    cout << endl;
}

/* TODO: acertar bug que está ocorrendo nesta função abaixo que foi comentada
void GrafoListaAdj::defineCor(Vertice v){
    list <Vertice>::iterator it1;
    list<Aresta>::iterator it2;
    for(it1 = this->vertices.begin(); it1 != this->vertices.end(); ++it1){
        for(it2 = v->listaAresta.begin(); it2 != v->listaAresta.end(); ++it2){
            v->listaAresta.i->getCor();

        }
    }
} */

int GrafoListaAdj::getPesoAresta(int id_vertice_1, int id_vertice_2)
{
    list<Vertice>::iterator it;
    int peso_aresta_1 = 1, peso_aresta_2 = 2; // irá armazenar o peso salvo nas arestas dentro de cada vertice
    for(it = vertices.begin(); it != vertices.end(); ++it) {
        if(it->getID() == id_vertice_1) {
            for(Aresta* a = it->getListaArestas(); a != NULL; a = a->getProx()) {
                if(a->getIdVertice() == id_vertice_2) {
                    peso_aresta_1 = a->getPeso();
                    break;
                }
            }
        }
        if(it->getID() == id_vertice_2) {
            for(Aresta* a = it->getListaArestas(); a != NULL; a = a->getProx()) {
                if(a->getIdVertice() == id_vertice_1) {
                    peso_aresta_2 = a->getPeso();
                    break;
                }
            }
        }

    }
    if(peso_aresta_1 == peso_aresta_2) {
        return peso_aresta_1;
    } else {
        //retorna o maior valor inteiro possível para representar a ausencia de aresta
        return INF;
    }
}

void GrafoListaAdj::adicionaPesoAresta(int id_vertice_1, int id_vertice_2, int peso) {
    list<Vertice>::iterator it;
    for(it = vertices.begin(); it != vertices.end(); ++it) {
        if(it->getID() == id_vertice_1) {
            for(Aresta* a = it->getListaArestas(); a != NULL; a = a->getProx()) {
                if(a->getIdVertice() == id_vertice_2) {
                    a->setPeso(peso);
                    break;
                }
            }
        }
        if(it->getID() == id_vertice_2) {
            for(Aresta* a = it->getListaArestas(); a != NULL; a = a->getProx()) {
                if(a->getIdVertice() == id_vertice_1) {
                    a->setPeso(peso);
                    break;
                }
            }
        }
    }
}


GrafoListaAdj GrafoListaAdj::algoritmoKruskal() {
    GrafoListaAdj mst; //minimal spanning tree
    list<Vertice>::iterator it;
    for(it = vertices.begin(); it != vertices.end(); ++it) {
        mst.adicionarVertice(it->getID());
    }
}



bool GrafoListaAdj::isBipartido()
{
    int tam,i;
    tam = this->vertices.size(); //pega quantidade de vertices tem no grafo
    int cores[tam];  // cria vetor de cores
    for(i=0;i<tam;i++)
    {
        cores[i]=-1;      // preenche vetor com -1 que significa não oolorido
    }
    list <Vertice>::iterator it;
    for(it = this->vertices.begin(); it != this->vertices.end(); ++it) //percorre  o vetor de vertices do grafo
    {
        int indice = it->getID(); // armazena id do vertice pra verificar no vetor de cores na sua respectiva posição
        if(cores[indice]==-1)  // se o vertice atual está sem cor atribui-se a cor um como padrão
        {
            cores[indice]=1;
        }
        int aux;
        Aresta* p= it->getListaArestas();
        while(p=!"null")  //percorre a lista de adjacencias do vertice atual
        {
            aux=p->getIdVertice(); // armazena id do vertice adjacente pra verificar no vetor de cores a cor do mesmo
            if(cores[aux]==-1)   //se o vertice não tiver colorido
             {
                cores[aux]=1-cores[indice];  // colore-se com a cor contraria
             }else if(cores[aux]==cores[indice]) // caso esteja colorido com  mesma cor significa que não é um grafo bipartido retornando false
            {
                return false;
            }
            p=p->getProx();
        }
        return true; //caso tenha percorrido o grafo sem achar vertices ligados com a mesma cor o grafo é bipartido
    }

}

void GrafoListaAdj::setNulo() {
    nulo = true;
}

void GrafoListaAdj::setTrivial(bool a) {
    trivial = a;
}

bool GrafoListaAdj::isNulo() {
    return nulo;
}

bool GrafoListaAdj::isTrivial() {
    return trivial;
}

/*
bool GrafoListaAdj::isMultigrafo() {
    return Vertice::temMultiAresta();
}
*/

//constroi a matriz de caminhos mpinimos do grafo através do algoritmo de Floyd
int** GrafoListaAdj::geraMatrizesFloyd() {
    int n = getOrdem();
    int** distancias = (int **) malloc(sizeof(int *) * n);
    for(int i=0; i < n; i++){
        distancias[i] = (int *) malloc(sizeof(int) * n);
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i==j)
                distancias[i][j] = 0;
            else
                distancias[i][j] = this->getPesoAresta(i+1, j+1);
        }
    }

    for(int aux = 0; aux < n; aux++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j<n; j++)
                if(distancias[i][j] > distancias[i][aux] + distancias[aux][j])
                    distancias[i][j] = distancias[i][aux] + distancias[aux][j];

    return distancias;
}

//executa o algoritmo de floyd e consulta o valor do caminho minimo gerado
int GrafoListaAdj::caminhoMinimoFloyd(int id_origem, int id_destino) {
    int** distancias = geraMatrizesFloyd();
    return distancias[id_origem-1][id_destino-1];
}

//preenche o vetor dos vertices visitados de acordo com o grau da profundidade
void GrafoListaAdj::auxBuscaProfundidade(int* visitados, int vertice_inicial, int cont) {
    Vertice v = this->getVertice(vertice_inicial);
    visitados[vertice_inicial - 1] = cont;
    for(Aresta* a = v.getListaArestas(); a != NULL; a = a->getProx()){
        if(!visitados[a->getIdVertice() - 1] || visitados[a->getIdVertice() - 1] > cont)
            auxBuscaProfundidade(visitados, a->getIdVertice(), cont+1);
    }
}

//inicializa o vetor dos vertices visitados com o valor zero e chama método auxiliar
int* GrafoListaAdj::buscaProfundidade(int vertice_inicial) {
    int cont = 1, n = getOrdem();
    int* visitados = (int *) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        visitados[i] = 0;
    auxBuscaProfundidade(visitados, vertice_inicial, cont);
    return visitados;
}

//retorna lista contendo os ids ds vertices que compoem o fecho transitivo direto do vertice
list<int> GrafoListaAdj::fechoTransitivoDireto(int id_vertice) {
    list<int> ftd;
    int* buscaProfundidade = this->buscaProfundidade(id_vertice);
    int i = 0;
    while(i < this->getOrdem()) {
        if(!buscaProfundidade[i])
            i++;
        else {
            ftd.push_back(i+1);
            i++;
        }
    }
    return ftd;
}

//retorna lista contendo os ids ds vertices que compoem o fecho transitivo indireto do vertice
list<int> GrafoListaAdj::fechoTransitivoIndireto(int id_vertice) {
    list<int> fti;
    list <Vertice>::iterator it;
    for(it = vertices.begin(); it != vertices.end(); ++it){
        int vertice_id = it->getID();
        int* busca = this->buscaProfundidade(vertice_id);
        if(busca[id_vertice - 1])
            fti.push_back(vertice_id);
    }
    return fti;
}

list<int> GrafoListaAdj::ordenacaoTopologica() {
    list<int> ordenacaoTopologica;
    int n = getOrdem();
    int* grausEntrada = (int *) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        grausEntrada[i] = this->getGrauEntrada(i+1);
    }

    int cont = 0;
    while(cont < n) {
        for(int i = 0; i < n; i++){
            if(grausEntrada[i] == 0){
                grausEntrada[i] = -1; //simboliza que o vertice já foi adicionado na lista
                ordenacaoTopologica.push_back(i+1);
                Aresta* a = this->getVertice(i+1).getListaArestas();
                while(a != NULL) {
                    grausEntrada[a->getIdVertice() - 1]--; //remove o vertice adicionado da lista e diminui o grau de entrada dos outrosx
                    a = a->getProx();
                }
                cont++;
                break;
            }
        }
    }
    return ordenacaoTopologica;
}
