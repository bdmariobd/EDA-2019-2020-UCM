// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include "treemap_eda.h"

// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n==0)
        return false;
    map<std::string, int> notas;
    std::string nota, alumno;
    std::cin.ignore();
    for (int i = 0;i < n;++i) {
        std::getline(std::cin,alumno);
        std::getline(std::cin, nota);
        notas[alumno] += (nota == "CORRECTO" ? 1 : -1);
    }
    // escribir sol
    for (auto i : notas) 
        if(i.valor != 0)
            std::cout <<  i.clave << ", " << i.valor << '\n';
     std::cout << "---\n";

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
