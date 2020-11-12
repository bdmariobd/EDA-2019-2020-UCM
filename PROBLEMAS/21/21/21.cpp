// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include"bintree_eda.h"


template <class T>
T menor(const bintree<T> t) {
    auto it = t.begin();
    T minimo = *it;
    while (it != t.end()) {
        minimo = std::min(minimo, *it);
        ++it;
    }
    return minimo;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char type;
    std::cin >> type;
    if (! std::cin)
        return false;
    if (type == 'N') {
        bintree<int> t = leerArbol(-1);
        std::cout << menor(t) << '\n';
    }
    else if (type == 'P') {
        std::string aux = "#";
        bintree<std::string> t = leerArbol(aux);
        std::cout << menor(t) << '\n';
    }
    
    
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