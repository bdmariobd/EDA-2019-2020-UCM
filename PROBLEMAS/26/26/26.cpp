// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema

//1st: elemento minimo.  2nd: elemento maximo.  Si son =-2, no es de busqueda
std::pair<int, int> esBusqueda(const bintree<int>& t) {
    if (t.empty()) return { -1,-1 };
    auto izq = esBusqueda(t.left()), dcha = esBusqueda(t.right());
    if (izq.first == -2 || dcha.first == -2) return  { -2,-2 };

    int min = izq.first == -1 ? t.root() : izq.first;
    int max = dcha.second == -1 ? t.root() : dcha.second;
    if ((izq.first == -1 || izq.second < t.root()) && (dcha.first == -1 || dcha.first > t.root())) return { min,max };
    return { -2,-2 };

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::cout << (esBusqueda(leerArbol(-1)).first == -2 ? "NO" : "SI") << '\n';
    
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