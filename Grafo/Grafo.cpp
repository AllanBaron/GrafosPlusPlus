#include "Grafo/Grafo.h"

Grafo::Grafo(bool direcionado, bool ponderado)
{
    this->direcionado = direcionado;
    this->ponderado = ponderado;
    this->qtdVertice = 0;
}

string Grafo::labelVertice(int indice){
    return this->label[indice];
}

bool Grafo::validaLabel(string label){
    for (int var = 0; var < qtdVertice; ++var)
        return !(this->label[var] == label);

    return true;
}

bool Grafo::getDirecionado()
{
    return direcionado;
}

bool Grafo::getPonderado()
{
    return ponderado;
}

vector<int> Grafo::busca_Profundidade(int indice)
{
    vector<int> resultado;
    vector<int> visitados(this->label.size(),0);
    int qtdVisitados = 0;
    stack<int> pilha;
    pilha.push(indice);

    while (!pilha.empty()) {
        int nodo = pilha.top();

        if (visitados.at(nodo) == 0) {
            resultado.push_back(nodo);
            visitados.at(nodo) = ++qtdVisitados;
        }

        int qtd_visinhos = 0;
        vector<int> vizinho = retornarVizinhos(nodo);

        for (int var = 0; var < vizinho.size(); var++) {
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

vector<int> Grafo::busca_Largura(int indice){
    vector<int> resultado;
    vector<int> visitados(this->label.size(),0);
    int qtdVisitados = 0;
    queue<int> fila;
    fila.push(indice);

    while (!fila.empty()) {
        int nodo = fila.front();

        if (visitados[nodo] == 0) {
            resultado.push_back(nodo);
            visitados[nodo] = ++qtdVisitados;
        }

        vector<int> vizinho = retornarVizinhos(nodo);

        for (int var = 0; var < vizinho.size(); ++var) {
            if(visitados[vizinho[var]] == 0){
                fila.push(vizinho[var]);

            }

        }
           fila.pop();
    }
    return resultado;
}

auto Grafo::welshPowell() -> vector<int> {
   vector< pair<int, string> > grau;
   vector<int> paleta(this->label.size(),0);

   for (string var: this->label)
       grau.push_back( make_pair(verticeGrau(var) ,var) );
/*
   for (int var = 0;var < grau.size(); var++) {
       cout << grau.at(var).first << " : " <<  grau.at(var).second << endl;
   }
   cout << endl;*/

   sort(grau.begin(), grau.end());
   reverse(grau.begin(), grau.end());

   int cor = 1;
   for (int var = 0;var < paleta.size();var++) {
       if(paleta.at(var) == 0){
           paleta.at(var) = cor;

           int origem = find(this->label.begin(), this->label.end(), grau.at(var).second) - this->label.begin();
           for (int var1 = var;var1 < paleta.size();var1++) {
               int destino = find(this->label.begin(), this->label.end(), grau.at(var1).second) - this->label.begin();
               if(existeAresta(origem, destino) == 0.0 && paleta.at(var1) == 0)
                   paleta.at(var1) = cor;
           }
       }
       cor++;
   }
   return paleta;
}

auto Grafo::dsatur() -> vector<int> {
    //vector<tuple <int,int,int,int,int>> c;
    vector< pair<int, int> > grau;
    vector<int> paleta(this->label.size(), 0);
    vector<int> saturacao(this->label.size(), 0);

    for (int var = 0; var < this->label.size(); var++)
        grau.push_back( make_pair(verticeGrau(var) ,var) );
    /*
    for (int var = 0;var < grau.size(); var++) {
        cout << grau.at(var).first << " : " <<  grau.at(var).second << endl;
    }
    cout << endl;
    */

    sort(grau.begin(), grau.end());
    reverse(grau.begin(), grau.end());

    //cout << "A: " << grau.at(4).second <<" B: "<< grau.at(1).second <<" C: "<< grau.at(3).second <<" D: "<< grau.at(2).second <<" E: "<< grau.at(0).second <<endl;
    /*
    sort(grau.begin(), grau.end(), [](pair<int, int> const& l, pair<int, int> const& r) {
        return l.first > r.first;
    });
    */
    bool trava = true;
    int id = 0, cor, t = 0;
    while (trava) {
        cor = 1;
        vector<int> vi = retornarVizinhos(grau.at(id).second);
/*
        for(int var : vi)
            cout << var << '|';
        cout << endl;
*/
        for (int var = 0;var < vi.size() ;) {
            int cot;
            for(int var1 = 0;var1 < grau.size();var1++){
                if(grau.at(var1).second == vi.at(var))
                    cot = var1;
            }
//          cout << cot <<"|"<<cor << endl;

            if(paleta.at(cot) == cor){
                cor++;
                var = 0;
            }else
                var++;
   //         cout<<var<<endl;
        }
        paleta.at(id) = cor;

        for (int var = 0; var < paleta.size(); var++) {
            //vector<int> vec = retornarVizinhos(grau.at(var).second);
            /*if(var == id)
                var++;*/
            bool tem_cor = false;
            for(int var_0 : retornarVizinhos(grau.at(var).second)){
                if(paleta.at(var_0) == cor && id != var_0)
                    tem_cor = true;
            }
            if(existeAresta(grau.at(id).second, grau.at(var).second) > 0.0 && !tem_cor)
                saturacao.at(var) += 1;
        }
        /*
        cout << "labe: ";
        for (int var = 0;var < grau.size(); var++) {
            cout << this->label.at(grau.at(var).second) << "|";
        }
        cout << endl;

        cout << "Grau: ";
        for (int var = 0;var < grau.size(); var++) {
            cout << grau.at(var).first << "|";
        }
        cout << endl;

        cout << "Satu: ";
        for(int var : saturacao)
            cout << var << '|';
        cout << endl;

        cout << "Pale: ";
        for(int var : paleta)
            cout << var << '|';
        cout << endl;
        */
        //vector<int> vetJC;
        if(id != paleta.size() - 1){
        vector< pair<int, int> > maiorSaturacao;
        for(int i = 0; i < saturacao.size(); i++){
            if(paleta.at(i) == 0){
                if(maiorSaturacao.size()) {
                    if(saturacao.at(i) > maiorSaturacao.at(0).second) {
                        maiorSaturacao.at(0).first = i;
                        maiorSaturacao.at(0).second = saturacao.at(i);
                    }
                    else if (saturacao.at(i) == maiorSaturacao.at(0).second) {
                        if(grau.at(i).first > grau.at(maiorSaturacao.at(0).first).first) {
                            maiorSaturacao.at(0).first = i;
                            maiorSaturacao.at(0).second = saturacao.at(i);
                        }
                    }
                }
                else {
                    maiorSaturacao.push_back(make_pair(i, saturacao.at(i)));
                }
            }
        }
        /*
        cout << "Label: " << label.at(maiorSaturacao.at(0).first) << endl;
        cout << "Index: " << maiorSaturacao.at(0).first << endl;
        cout << "Grau: " << maiorSaturacao.at(0).second << endl;
//        trava = false;
        */
        id = maiorSaturacao.at(0).first;
        }
        //cout << "id: " << id << endl;
        int s = 0;
        for (int var = 0; var < paleta.size(); ++var) {
            if(paleta.at(var) != 0)
                s++;
        }
        if(s == paleta.size())
            trava = false;

    }
    return paleta;
}

int Grafo::verticeGrau(string label){
    int index = find(this->label.begin(), this->label.end(), label) - this->label.begin();
    return this->retornarVizinhos(index).size();
}

int Grafo::verticeGrau(int index){
    return this->retornarVizinhos(index).size();
}

auto Grafo::prim(size_t index) -> int {
    vector<tuple<size_t, size_t, double>> solution;
    vector<size_t> control;
    int result = 0;

    for (size_t i=0; i < this->label.size(); i++)
        control.push_back(i);

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

    for(auto var : solution)
        result += get<2>(var);

    return result;
}

auto Grafo::kruskal() -> int {
    vector<tuple<size_t, size_t, double>> solution;
    vector<tuple<size_t, size_t, double>> control;
    vector<vector<size_t>> forest;
    int result = 0;

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
    for(auto var : solution)
        result += get<2>(var);
    return result;
}
Grafo::~Grafo() = default;
