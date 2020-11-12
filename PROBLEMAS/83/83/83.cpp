// Nombre del alumno Mario Blanco
// Usuario del Juez E09 


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
// función que resuelve el problema

//1º mas grande encontrado en los hijos    2º que contiene raiz
std::pair<int,int> subarbol(const bintree<char> t) {
    if (t.empty()) return { 0,0 };
    auto izq = subarbol(t.left()), dcha = subarbol(t.right());
    int maximo = t.left().empty() || t.right().empty() ? 1 : 1 + std::min(izq.second, dcha.second);
    return { std::max(maximo, std::max(izq.first,dcha.first))  , maximo };    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    auto sol = subarbol(leerArbol('.'));
    std::cout << std::max(sol.first,sol.second) << '\n';
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