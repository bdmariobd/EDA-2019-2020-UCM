// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
//1st: equipos necesarios. 2nd: atrapados max
std::pair<int, int> excursionistas(const bintree<int> t) {
    if (t.empty())return { 0,0 };
    auto izq = excursionistas(t.left());
    auto dcha = excursionistas(t.right());
    return {
        t.root() == 0 ? //si no hay que rescatar, no modifico 
        izq.first + dcha.first : izq.first + dcha.first==0?  //si hay que rescatar, compruebo que no habia un equipo de rescate. Si habia no modifico
            1: izq.first + dcha.first
        , t.root()+ std::max(izq.second, dcha.second)
    };
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> t = leerArbol(-1);
    auto sol = excursionistas(t);
    std::cout << sol.first << " " << sol.second << '\n';
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