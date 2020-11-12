// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include "insertqeue.h"

// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    insert_queue<int> q1, q2;
    int aux;
    std::cin >> aux;
    while (aux != 0) {
        q1.push(aux);
        std::cin >> aux;
    }
    std::cin >> aux;
    while (aux != 0) {
        q2.push(aux);
        std::cin >> aux;
    }
    // escribir sol
    q1.insert(q2);
    q1.print();
    
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