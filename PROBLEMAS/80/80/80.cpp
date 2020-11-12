// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
std::pair<bool, int> correcto(const  bintree<int> t) {
    if (t.empty()) return { true,0 };
    if ((!t.left().empty() && t.root() - t.left().root() < 18)) return { false,0 };
    if ((!t.right().empty() && t.root() - t.right().root() < 18)) return { false,0 };
    if( t.left().empty() && !t.right().empty()||
        (!t.left().empty() && !t.right().empty() && t.left().root() - t.right().root()<2)) return { false,0 };
    auto izq = correcto(t.left());
    if (!izq.first) return { false,0 };
    auto dcha = correcto(t.right());
    if (!dcha.first) return { false,0 };
    return { true, std::max(izq.second, dcha.second)+1 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> t = leerArbol(-1);
    auto sol = correcto(t);
    if (!sol.first)std::cout << "NO\n";
    else std::cout << "SI "<<sol.second<<'\n';
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}