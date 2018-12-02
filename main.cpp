#include <iostream>
#include <GrafoListaAdj.h>
#include <fstream>
#include <cstdlib>

/*
*
*@Author grupo11
*
*
*/

using namespace std;


void gerarGrafoPorArquivo(std::string nome_arquivo ,GrafoListaAdj* grafo, bool ponderado, bool eDigrafo) // aceita como par�metro o nome do arquivo na pasta e o grafo que se deseja popular
{
    string caminhoArquivo = "instancias_grafos/" + nome_arquivo + ".txt";
    ifstream inFile(caminhoArquivo.c_str());
    int numero_vertices;
    int vertice_1, vertice_2, peso;
    //inFile.open(caminhoArquivo); // abre o arquivo

    //instancias_grafos/grafo_1000_1
    if(!inFile) {        //verifica se o arquivo foi encontrado
        cerr << "incapaz de ler o arquivo";
        exit(1);
    }

    inFile >> numero_vertices; // adiciona o primeiro n�mero encontrado no arquivo como inteiro em numero_vertices
    if(numero_vertices == 0) {
        grafo->setNulo();
    }
    if(numero_vertices == 1) {
        grafo->setTrivial(true);
    }
    else {
        grafo->setTrivial(false);
    }

    for(int i=1; i<=numero_vertices; i++){ //itera sobre o n�mero de vertices para adicionar os vertices no grafo
        grafo->adicionarVertice(i); // � adicionado um vertice no grafo com o id = i

    }
    if(ponderado) {
        if(eDigrafo) {
            while(inFile >> vertice_1 && inFile >> vertice_2 && inFile >> peso){ //enquanto encontrar os pares de valores no arquivo, � adicionada uma aresta ao grafo
                grafo->adicionaArestaDirecionada(vertice_1, vertice_2);
                grafo->adicionaPesoAresta(vertice_1, vertice_2, peso);
            }
        } else {
            while(inFile >> vertice_1 && inFile >> vertice_2 && inFile >> peso){ //enquanto encontrar os pares de valores no arquivo, � adicionada uma aresta ao grafo
                grafo->adicionarAresta(vertice_1, vertice_2);
                grafo->adicionaPesoAresta(vertice_1, vertice_2, peso);
            }
        }
    } else {
        if(eDigrafo) {
            while(inFile >> vertice_1 && inFile >> vertice_2 )
                grafo->adicionaArestaDirecionada(vertice_1, vertice_2);
        } else {
              while(inFile >> vertice_1 && inFile >> vertice_2 )
                grafo->adicionarAresta(vertice_1, vertice_2);
        }
    }
    inFile.close(); // fechando leitor
}

int main()
{
    cout << "Trabalho 1 de grafos: " << endl;

    cout << "digite o nome do arquivo que se deseja usar (nao inclua .txt ao escrever o nome): ";
    string nomeArquivo;
    cin >> nomeArquivo;

    cout << "o grafo e ponderado('S' ou 'N')?";
    char cponderado;
    bool ponderado;
    cin >> cponderado;
    if(cponderado == 'S')
        ponderado = true;
    else
        ponderado = false;

    cout << "o grafo e direcionado('S' ou 'N')?";
    char cdigrafo;
    bool eDigrafo;
    cin >> cdigrafo;
    if(cponderado == 'S')
        eDigrafo = true;
    else
        eDigrafo = false;


    GrafoListaAdj grafo;
    gerarGrafoPorArquivo(nomeArquivo, &grafo, ponderado, eDigrafo); // popula o grafo atrav�s do arquivo
    int num_vertices = grafo.getOrdem();


    cout << "N�mero de vertices: " << num_vertices << endl;
    grafo.imprimirVertices();
    for(int i=0; i <= num_vertices; i++){
        grafo.imprimirArestas(i);
    }

    grafo.imprimeSequenciaGraus();
    if(grafo.isCompleto()) {
        cout << "grafo e completo" << endl;
    } else {
        cout << "grafo nao e completo" << endl;
    }

    grafo.mostrarVizinhancaFechada(2);
    cout <<"peso: " << grafo.getPesoAresta(1, 2) << endl;
    cout << "Floyd " << grafo.caminhoMinimoFloyd(1, 2) << endl;
    cout << "BuscaProfundidade: ";
    list<int> vet = grafo.ordenacaoTopologica();
    list<int>::iterator it;
    for(it = vet.begin(); it != vet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    return 0;
}
