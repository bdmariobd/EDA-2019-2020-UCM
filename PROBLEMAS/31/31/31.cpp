// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <map>
#include<vector>
#include <string>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n==0)
        return false;
    std::map<std::string, std::vector<int>> dicc;
    std::string line, word;
    std::cin.ignore();

    for (int i = 0;i < n;++i) {
        getline(std::cin, line);
        std::stringstream ss(line);
        while (ss >> word) {
            if (word.length() > 2) {
                for (char& c : word) c = tolower(c);
                //inserto si esta vacio o si no he insertado ya el mismo valor
                if(dicc[word].empty() || dicc[word].back()!=i+1) dicc[word].push_back(i+1);
            }
        }
    }
    //escribir sol
    for (auto i : dicc) {
        std::cout << i.first << " ";
        for (int j :i.second) {
            std::cout << j << " ";
        }
        std::cout << '\n';
    }
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
