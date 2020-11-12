// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "bintree_eda.h"

bintree<int> construir(const std::vector<int>& pre, const std::vector<int>& in, 
        std::pair<int,int> preorden, std::pair<int, int> inorden) {
    if (preorden.first > preorden.second) return {};
    int raiz = pre[preorden.first];
    int pRaiz = inorden.first;
    while (in[pRaiz] != raiz) {
        ++pRaiz;
    }
    int izqTam = pRaiz - inorden.first;
    auto izq = construir(pre, in, { preorden.first + 1, preorden.first + izqTam }, { inorden.first, pRaiz - 1 });
    auto dcha = construir(pre, in, { preorden.first + 1 + izqTam, preorden.second }, { pRaiz+1, inorden.second });

    return {izq,raiz,dcha};
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string aux;
    std::getline(std::cin, aux);
    if (! std::cin)
        return false;
    std::vector<int> pre;
    std::stringstream ss(aux);
    int n;
    while(ss>>n) pre.push_back(n);

    std::getline(std::cin, aux);
    std::vector<int> in;
    std::stringstream ss2(aux);
    while (ss2 >> n) in.push_back(n);
    // escribir sol
    bintree<int> t = construir(pre, in, { 0,pre.size()-1 }, { 0,pre.size()-1 });
    std::vector<int> post = t.postorder();
    for (int& i : post) std::cout << i << " ";
    std::cout << '\n';
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}