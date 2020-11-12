// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
#include "InserccionColagistica_10.h"


// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    insert_queue<int> v1,v2;
    int n1;
    std::cin >> n1;
    if (! std::cin)
        return false;
    int n2, aux, pos;
    for (int i = 0;i < n1;i++) {
        std::cin >> aux;
        v1.push(aux);
    }
    std::cin >> n2>>pos;
    for (int i = 0;i < n2;i++) {
        std::cin >> aux;
        v2.push(aux);
    }
    // escribir sol
    v1.insert(v2, pos);
    v1.print();
    std::cout << '\n';
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-10.1.in");
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