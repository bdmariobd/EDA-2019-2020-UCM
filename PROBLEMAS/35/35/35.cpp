// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include<sstream>
#include "carnet_puntos.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string acc,aux;
    int nAux;
    std::cin >> acc;
    if (! std::cin)
        return false;
    carnet_puntos conductores;
    while (acc != "FIN") {
        try {
            if (acc == "nuevo") {
                std::cin >> aux;
                conductores.nuevo(aux);
            }
            if (acc == "cuantos_con_puntos") {
                std::cin >> nAux;
                conductores.cuantos_con_puntos(nAux);
            }
            if (acc == "lista_por_puntos") {
                std::cin >> nAux;
                conductores.lista_por_puntos(nAux);
            }
            if (acc == "recuperar") {
                std::cin >> aux >> nAux;
                conductores.recuperar(aux, nAux);
            }
            if (acc == "quitar") {
                std::cin >> aux >> nAux;
                conductores.quitar(aux, nAux);
            }
            if (acc == "consultar") {
                std::cin >> aux;
                conductores.consultar(aux);
            }
        }
        catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what()<<'\n';
        }
        std::cin.ignore();
        std::cin >> acc;
    }
    std::cout << "---\n";
    // escribir sol
    
    
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