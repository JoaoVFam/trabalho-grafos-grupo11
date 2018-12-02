#include "GrafoListaAdj.h"
#include <list>
#include <algorithm>
#include "limits.h"

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
    Aresta novaaresta = Aresta(id_vertice_1,id_vertice_2);
    this->ArestasGrafo.push_back(novaaresta);
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
    Aresta novaaresta = Aresta(id_vertice_entrada,id_vertice_saida);
    this->ArestasGrafo.push_back(novaaresta);
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
        graus[k] = it->getGrau();
    }

    //ordena��o do vetor em ordem decrescente
    int aux;
    for(int i = 0; i<numVertices; i++) {
        for(int j = i+1; j<numVertices; j++) {
            if(graus[i] < graus[j]) {
                aux = graus[i];
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

// TODO: acertar bug que está ocorrendo nesta função abaixo que foi comentada
void GrafoListaAdj::defineCor(Vertice v){
    list <Vertice>::iterator it1;
    list<Aresta>::iterator it2;
    for(it1 = this->vertices.begin(); it1 != this->vertices.end(); ++it1){
        for(it2 = v->listaAresta.begin(); it2 != v->listaAresta.end(); ++it2){
            v->listaAresta.i->getCor();

        }
    }
}

int GrafoListaAdj::getPesoAresta(int id_vertice_1, int id_vertice_2)
{
    list<Vertice>::iterator it;
    int peso_aresta_1, peso_aresta_2; // irá armazenar o peso salvo nas arestas dentro de cada vertice
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
        cout << "getPesoAresta funcionou!" << endl;
        return peso_aresta_1;
    } else {
        cout << "getPesoAresta pesos das arestas nao batem (talvez sejam direcionadas ou nao existe aresta): return 0" << endl;
        return 0;
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
        list <Aresta>::iterator it2;
        for(it2 =it->ListaAresta.begin() ; it2 != it->ListaAresta.end(); ++it)
        {
            aux=it2->getIdVertice(); // armazena id do vertice adjacente pra verificar no vetor de cores a cor do mesmo
            if(cores[aux]==-1)   //se o vertice não tiver colorido
             {
                cores[aux]=1-cores[indice];  // colore-se com a cor contraria
             }else if(cores[aux]==cores[indice]) // caso esteja colorido com  mesma cor significa que não é um grafo bipartido retornando false
            {
                return false;
            }

        }
        return true; //caso tenha percorrido o grafo sem achar vertices ligados com a mesma cor o grafo é bipartido
    }

}

GrafoListaAdj GrafoListaAdj::algoritmoKruskal()
{

        GrafoListaAdj arvore;
        list<Vertice> solucaov;
        int qtd = this->vertices.size()-1;
        int i;
        int no1,no2;
        bool n1,n2;
        Vertice *aux;
        list<Aresta>Candidatas = this->ArestasGrafo;
        Candidatas.sort([](Aresta *aresta1, Aresta *aresta2) {
        return aresta1->getPeso() < aresta2->getPeso();
    });
        list <Aresta>::iterator it;
        list<Vertice>::iterator it2;
        for(i=0;i<qtd;i++)
        {
            no1 = Candidatas.begin()->getIdVertice();
            no2 = Candidatas.begin()->getIdSec();
            n1= (std::find(solucaov.begin(), solucaov.end(), no1) != solucaov.end());
            n2= (std::find(solucaov.begin(), solucaov.end(), no2) != solucaov.end());

            if(!n1 && !n2)
            {
                solucaov.push_back(achavertice(no2));
                solucaov.push_back(achavertice(no1));
                arvore.ArestasGrafo.push_back(Candidatas.front());
                Candidatas.pop_front();

            }
            if(n1 && !n2)
            {
                int verifica = 0;
                it2=vertices.begin();
                bool teste;
                while(it2->getID()!= no2)
                {
                    it2++;
                }
                for(it = it2->ListaAresta.begin();it != it2->ListaAresta.end(); ++it)
                {

                    teste= (std::find(solucaov.begin(), solucaov.end(), it2) != solucaov.end());
                    if(teste) verifica++;

                }
                if(verifica==0)
                {
                    arvore.ArestasGrafo.push_back(Candidatas.front());
                    Candidatas.pop_front();
                    solucaov.push_back(achavertice(no2));

                }else
                {
                    Candidatas.pop_front();
                }



            }
            if(n2==true && n1==false)
            {
                int verifica = 0;
                it2=vertices.begin();
                bool teste;
                while(it2->getID()!= n1)
                {
                    it2++;
                }
                for(it = it2->ListaAresta.begin();it != it2->ListaAresta.end(); ++it)
                {

                    teste= (std::find(solucaov.begin(), solucaov.end(), it2) != solucaov.end());
                    if(teste==true) verifica++;

                }
                if(verifica==0)
                {
                    arvore.ArestasGrafo.push_back(Candidatas.front());
                    Candidatas.pop_front();
                    solucaov.push_back(achavertice(no1));
                }else
                {
                    Candidatas.pop_front();
                }
            }
        }

}

GrafoListaAdj GrafoListaAdj::algoritmoPrim(Vertice v)
{

     GrafoListaAdj Primsolut;
     int tam = this->vertices.size();
     list<Aresta>Candidatas;
     list<Aresta>Solucao;
     list<Vertice>Solut;
     int idno;
     Vertice *vc;
     vc =&v;
     Aresta arestaux;
     list<Vertice>::iterator it;
     list<Aresta>::iterator ita;

     while(Solut.size()<tam) // loop pra cobrir todos os vertices
     {
         int controle =0;
         for(ita=vc->ListaAresta.begin();ita!=vc->ListaAresta.end();ita++)
         {
              ita->setIdSec(ita->getIdVertice());
         }
         Candidatas.sort([](Aresta *aresta1, Aresta *aresta2) {
             return aresta1->getPeso() < aresta2->getPeso();
         });
         for(it= Solut.begin();it!=Solut.end();it++)
         {
             if(Candidatas.begin()->getIdVertice()==it->getID())
             {
                 controle++;
             }

         }
         if(controle!=0)
         {
             Candidatas.pop_front();
         }else {


             Primsolut.adicionarVertice(Candidatas.front().getIdVertice());
             Primsolut.adicionarVertice(Candidatas.front().getIdSec());
             Primsolut.adicionarAresta(Candidatas.front().getIdSec(),Candidatas.front().getIdVertice());
             Solut.push_back(v);
             idno = Candidatas.front().getIdVertice();
             it = this->vertices.begin();
             while (it->getID() != idno) {
                 it++;
             }
             vc = &*it;
             Candidatas.pop_front();

         }
     }


}
void GrafoListaAdj::algoritimoDjsktra(Vertice c)
{
    list<Vertice> S = this->vertices;
    int i;
    int tam = this->vertices.size();
    int distancia[tam];
    bool visitado[tam];
    for(i=0;i<tam;i++)
    {
        visitado[i]=false;
        distancia[i]= INT_MAX;
    }
    distancia[c.getID()]=0;
    while (!S.empty())
    {
        if(visitado[S.front().getID()]==false)
        {
            visitado[S.front().getID()]= true;
            list<Aresta>::iterator it;
            for(it=S.front().ListaAresta.begin();it!=S.front().ListaAresta.end();it++)
            {
                if(it->getPeso()+distancia[S.front().getID()]<distancia[it->getIdVertice()])
                {
                    distancia[it->getIdVertice()] = it->getPeso()+distancia[S.front().getID()];
                }

            }
        }
        S.pop_front();

    }



}
void GrafoListaAdj::DFS() {

    int tam,i;
    tam = this->vertices.size();
    bool visitados = new bool [tam];
    for(i=0;i<tam;i++)
    {
        visitados[i]= false;
    }
    for(i=0;i<tam;i++)
    {
        if(visitados[i]==false)
        {
            DFSAux(i,visitados[]);
        }
    }

}

void GrafoListaAdj::DFSAux(int i, bool *visitado) {

    visitado[i] = true;

    list<Vertice>::iterator it = this->vertices.begin();
    advance(it, i);
    list<Aresta>::iterator it2;
    for (it2 = it->ListaAresta.begin(); it2 != it->ListaAresta.end(); it2++) {

        if (!visitado[it->getID()] == false) {
            DFSAux(it2->getIdVertice(), visitado);
        }

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

void GrafoListaAdj::sequenciaGrau() {
    list <Vertice>::iterator it;
    cout<<endl<<"[";
    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){
        cout << it->getGrau()<< ", " ;
    }
    cout<<"]" <<endl;
}
Vertice GrafoListaAdj::achavertice(int id)
{
    list <Vertice>::iterator it;
    it = this->vertices.begin();
    while (it->getID() != id) {
        it++;
    }
    return *it;


}

