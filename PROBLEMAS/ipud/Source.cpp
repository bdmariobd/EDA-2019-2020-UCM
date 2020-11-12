#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include<sstream>
#include"ipud.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string acc,aux, aux2;
    int nAux;
    std::cin >> acc;
    if (! std::cin)
        return false;
    ipud reproductor;
    while (acc != "FIN") {
        try {
            if (acc == "addSong") {
                std::cin >> aux >>aux2>>nAux;
                reproductor.addSong(aux,aux2,nAux);
            }
            if (acc == "addToPlaylist") {
                std::cin >> aux;
                reproductor.addToPlaylist(aux);
            }
            if (acc == "current") {
               
                 reproductor.current();
            }
            if (acc == "play") {
               
                reproductor.play();
            }
            if (acc == "totalTime") {
               reproductor.totalTime();
            }
            if (acc == "recent") {
            std:cin >> nAux;
               reproductor.recent(nAux);
            }
            if(acc== "deleteSong"){
                std::cin >> aux;
                reproductor.deleteSong(aux);
			}
        }
        catch (std::domain_error e) {
            std::cout << e.what()<<'\n';
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