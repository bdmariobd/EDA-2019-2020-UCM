// Nombre del alumno Mario Blanco Dominguez
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>

#include "polinomio.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::pair<int, int> aux(1,1);
    std::cin >> aux.first >> aux.second;
    if (! std::cin)
        return false;
    polinomio p;
    while (!(aux.first == 0 && aux.second == 0)) {
        if (aux.first != 0) p.add(aux);
        std::cin >> aux.first >> aux.second;
    }
    int n,valor;
    std::cin >> n;
    //funcion que resuelve el problema
    for (int i = 0;i < n;i++) {
        std::cin >> valor;
        std::cout << p.evaluar(valor) << " ";
    }
    std::cout << "\n";
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-04.1.in");
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