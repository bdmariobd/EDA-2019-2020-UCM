// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "modifiedConjunto.h"


// función que resuelve el problema

template <class T>
void resolver(T centinela, int k) {
    set<T> cjto;
    T elem;
    std::cin >> elem;
    while (elem != centinela) {
        cjto.insert(elem);
        if (cjto.size() > k) cjto.borrarMenor();
        std::cin >> elem;
    }
    cjto.print(std::cout);
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char type;
    std::cin >> type;
    if (! std::cin)
        return false;
    int k;
    std::cin >> k;
    if (type == 'N') resolver<int>(-1, k);
    else resolver<std::string>("FIN",k);
    std::cout << "\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-05.1.in");
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