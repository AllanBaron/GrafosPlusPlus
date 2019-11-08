#include "Grafo/Grafo.h"

Grafo::Grafo(bool direcionado, bool ponderado)
{
    this->direcionado = direcionado;
    this->ponderado = ponderado;
}

auto Grafo::labelVertice(size_t indice) -> string
{
    return this->label[indice];
}

auto Grafo::validaLabel(string label) -> bool
{
    for(auto var : this->label){
        if(var.compare(label) == 0)
            return false;
    }
    return true;
}

auto Grafo::getDirecionado() -> bool
{
    return direcionado;
}

auto Grafo::getPonderado() -> bool
{
    return ponderado;
}

auto Grafo::busca_Profundidade(size_t indice) -> vector<size_t>
{
    vector<size_t> resultado;
    vector<size_t> visitados(this->label.size(),0);
    size_t qtdVisitados = 0;
    stack<size_t> pilha;
    pilha.push(indice);

    while (!pilha.empty()) {
        size_t nodo = pilha.top();

        if (visitados.at(nodo) == 0) {
            resultado.push_back(nodo);
            visitados.at(nodo) = ++qtdVisitados;
        }

        size_t qtd_visinhos = 0;
        vector<size_t> vizinho = retornarVizinhos(nodo);

        for (size_t var = 0; var < vizinho.size(); var++) {
            if(visitados[vizinho[var]] == 0){
                pilha.push(vizinho[var]);
                break;
            }
            qtd_visinhos++;
        }

        if(qtd_visinhos == vizinho.size())
            pilha.pop();
    }

    return resultado;
}

auto Grafo::busca_Largura(size_t indice) -> vector<size_t>
{
    vector<size_t> resultado;
    vector<size_t> visitados(this->label.size(),0);
    size_t qtdVisitados = 0;
    queue<size_t> fila;
    fila.push(indice);

    while (!fila.empty()) {
        size_t nodo = fila.front();

        if (visitados[nodo] == 0) {
            resultado.push_back(nodo);
            visitados[nodo] = ++qtdVisitados;
        }

        vector<size_t> vizinho = retornarVizinhos(nodo);

        for (size_t var = 0; var < vizinho.size(); ++var) {
            if(visitados[vizinho[var]] == 0){
                fila.push(vizinho[var]);
            }
        }
        fila.pop();
    }
    return resultado;
}

auto Grafo::welshPowell() -> vector<tuple<size_t, int, int>>
{
    vector<tuple<size_t, int, int>> cores;

    for(size_t var = 0; var < label.size(); var++)
        cores.push_back(make_tuple(var, verticeGrau(var), 0));

    sort(cores.begin(), cores.end(),[](tuple<size_t, int, int> &a, tuple<size_t, int, int> &b){return get<1>(a) > get<1>(b);});


    int corAtual = 1;
    size_t contador = 0;
    bool vizinhoCor = false;
    while (get<2>(*min_element(cores.begin(), cores.end(),[](tuple<size_t, int, int> &a, tuple<size_t, int, int> &b) { return get<2>(a) < get<2>(b);})) == 0) {
        auto vizinhos = retornarVizinhos(get<0>(cores.at(contador)));
        for(size_t var = contador; var < cores.size() ; var++){
            if(get<2>(cores.at(var)) == 0 && (find(vizinhos.begin(), vizinhos.end(), get<0>(cores.at(var))) == vizinhos.end())){
                for(size_t vizinhoDoVizinho : retornarVizinhos(get<0>(cores.at(var)))){
                    for(auto vec : cores){
                        if(get<0>(vec) == vizinhoDoVizinho && get<2>(vec) == corAtual){
                            vizinhoCor = true;
                            break;
                        }
                    }
                }
                if(!vizinhoCor)
                    get<2>(cores.at(var)) = corAtual;
                vizinhoCor = false;
            }
        }
        corAtual++;
        contador++;
    }
    return cores;
}

auto Grafo::dsatur() -> vector<tuple<size_t, int, int, int>>
{
    vector<tuple<size_t, int, int, int>> cores;
    
    for(size_t var = 0; var < label.size(); var++)
        cores.push_back(make_tuple(var, verticeGrau(var), 0, 0));

    sort(cores.begin(), cores.end(),[](tuple<size_t, int, int, int> &a, tuple<size_t, int, int, int> &b){ return get<1>(a) > get<1>(b); });

    int corAtual;
    size_t contador = 0;

    while (get<3>(*min_element(cores.begin(), cores.end(),[](tuple<size_t, int, int, int> &a, tuple<size_t, int, int, int> &b) { return get<3>(a) < get<3>(b);})) == 0) {
        corAtual = 1;
        for(auto vizinhos : retornarVizinhos(get<0>(cores.at(contador)))){
            if(get<3>(*find_if(cores.begin(), cores.end(),[&vizinhos](tuple<size_t, int, int, int> &a){ return get<0>(a) == vizinhos; })) == corAtual){
                corAtual++;
            }
        }
        //cout << corAtual << endl;
        bool saturacao = true;
        for(auto vizinhos : retornarVizinhos(get<0>(cores.at(contador)))){
            for(auto var : retornarVizinhos(get<0>(*find_if(cores.begin(), cores.end(),[&vizinhos](tuple<size_t, int, int, int> &a){ return get<0>(a) == vizinhos; })))){
                if(get<3>(*find_if(cores.begin(), cores.end(),[&var](tuple<size_t, int, int, int> &a){ return get<0>(a) == var; })) == corAtual)
                    saturacao = false;
            }
            if(saturacao)
                get<2>(*find_if(cores.begin(), cores.end(),[&vizinhos](tuple<size_t, int, int, int> &a){ return get<0>(a) == vizinhos; })) += 1;
        }

        get<3>(cores.at(contador)) = corAtual;
        /*
        cout << "Saturacao:" << endl;
        for(auto var : cores)
            cout << '|' << get<0>(var);
        cout << endl;
        for(auto var : cores)
            cout << '|' << get<1>(var);
        cout << endl;
        for(auto var : cores)
            cout << '|' << get<2>(var);
        cout << endl;
        for(auto var : cores)
            cout << '|' << get<3>(var);
        cout << endl;
        */

        tuple<size_t, int, int, int> prox = make_tuple(-1, -1, -1, -1);
        for (auto var : cores) {
            if(get<2>(var) > get<2>(prox) && get<3>(var) == 0 /*&& get<1>(var) != get<1>(prox)*/)
                prox = var;
        }

        for (size_t var = 0; var < cores.size(); var++) {
            if(get<0>(prox) == get<0>(cores.at(var))){
                contador = var;
                break;
            }
        }
        //cout << contador << endl;
    }
    return cores;
}

auto Grafo::verticeGrau(size_t index) -> size_t
{
    return this->retornarVizinhos(index).size();
}

auto Grafo::prim(size_t index) -> vector<tuple<size_t, size_t, double>>
{
    vector<tuple<size_t, size_t, double>> solution;
    vector<size_t> control(this->label.size());

    iota(control.begin(), control.end(), 0);

    control.erase(find(control.begin(), control.end(), index));

    while (!control.empty()) {
        vector<tuple<size_t, size_t, double>> s;

        for(auto var : control){
            for (auto vizinho : retornarVizinhos(var)){
                if(find(control.begin() , control.end(), vizinho) == control.end())
                    s.push_back(make_tuple(vizinho, var,  existeAresta(vizinho, var)));
            }
        }

        sort(s.begin(), s.end(), [](tuple<size_t, size_t, double>& a, const tuple<size_t, size_t, double>& b){ return (get<2>(a) < get<2>(b)); });

        solution.push_back(s.at(0));
        index = get<1>(s.at(0));

        s.clear();

        control.erase(find(control.begin(), control.end(), index));
    }
    return solution;
}

auto Grafo::kruskal() -> vector<tuple<size_t, size_t, double>>
{
    vector<tuple<size_t, size_t, double>> solution;
    vector<tuple<size_t, size_t, double>> control;
    vector<vector<size_t>> forest;

    for(size_t var = 0;var < size_t(label.size());var++)
        forest.push_back({var});

    for (size_t cont = 0;cont < size_t(label.size());cont++) {
        for(auto var : retornarVizinhos(cont)){
            if(find_if(control.begin(), control.end(),[=](tuple<size_t, size_t, double>& a) { return (get<1>(a) == cont && get<0>(a) == var); }) == control.end())
                control.push_back(make_tuple(cont, var, existeAresta(cont, var)));
        }
    }

    sort(control.begin(), control.end(), [](tuple<size_t, size_t, double>& a, tuple<size_t, size_t, double>& b){ return (get<2>(a) < get<2>(b)); });

    for(auto var : control){
        size_t var0 = 0, var01 = 0, var1 = 0, var10 = 0;
        for(size_t x = 0; x < size_t(forest.size()) ; x++){
            for(size_t x1 = 0; x1 < size_t(forest.at(x).size()) ; x1++){
                if(forest.at(x).at(x1) == get<0>(var)){
                    var0 = x;
                    var01 = x1;
                }
                if(forest.at(x).at(x1) == get<1>(var)){
                    var1 = x;
                    var10 = x1;
                }
            }
        }
        if(var0 != var1){
            solution.push_back(var);
            forest.at(var0).insert(forest.at(var0).end(), forest.at(var1).begin(), forest.at(var1).end());
            forest.erase(forest.begin() + int(var1));
        }
    }
    control.clear();
    return solution;
}

Grafo::~Grafo() = default;
