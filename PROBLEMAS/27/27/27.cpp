// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <vector>
#include <sstream>

bintree<int> preorden(const std::vector<int> & v, std::pair<int,int> i) {
    if (i.first > i.second) return {};
    int raiz = v[i.first], ind=i.first+1;
    while (ind <= i.second && v[ind] < raiz) ++ind;
    auto izq = preorden(v, { i.first + 1, ind -1 });
    auto dcha = preorden(v, { ind,i.second });

    return { izq,raiz,dcha };
}

void postOrden(const bintree<int>& t) {
    if (t.empty()) return;
    if (t.left().empty() && t.right().empty()) { std::cout << t.root() << " "; return; }
    postOrden(t.left()); postOrden(t.right());
    std::cout << t.root() << " "; 
    return;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string linea;
    getline(std::cin, linea);
    if (!std::cin)

        return false;
    int n;
    std::vector<int> v;
    std::stringstream ss(linea);
    while (ss >> n) v.push_back(n);
    postOrden(preorden(v, { 0,v.size() - 1 }));
    std::cout <<'\n';
    
    
    // escribir sol
    
    
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