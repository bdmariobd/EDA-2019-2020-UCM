// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include<unordered_map>
#include<vector>
#include<string>
#include <sstream>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool aparece(std::string el,const std::vector<std::string> &v) {
    for (auto& i : v) {
        if (el == i) return true;
    }
    return false;
}
void resuelveCaso() {
    // leer los datos de la entrada
    std::map<std::string, int> antiguo, nuevo;
    std::vector<std::string> menos,ast;
    std::string prim, sec,word;
    //lectura datos y almacenamieto en diccionarios
    getline(std::cin, prim);
    getline(std::cin, sec);
    std::stringstream ss(prim);
    while (ss >> word) {
        ss >> antiguo[word];
    }
    std::stringstream ss2(sec);
    while (ss2 >> word) {
        ss2 >>nuevo[word];
    }
    //comprobadores cambio. En el diccionario nuevo borro los * (los - no porque no existen), por lo que en el diccionario nuevo quedan los +
    for (auto& i : antiguo) {
        if (nuevo.count(i.first) == 0) {
            menos.push_back(i.first);
        }
        else {
            if (i.second != nuevo[i.first]) {
                ast.push_back(i.first);
            }
            nuevo.erase(i.first);
        }
    }
    //escritura resultado
    if (ast.empty() && nuevo.empty()&&menos.empty()) {
        std::cout << "Sin cambios\n---\n"; 
        return;
    }
    if(!nuevo.empty()){ std::cout << '+' << " "; for (auto& i : nuevo) std::cout << i.first << " "; std::cout << "\n"; }
    if (!menos.empty()) { std::cout << '-' << " "; for (auto& i : menos) std::cout << i << " ";std::cout << "\n"; }
    if (!ast.empty()) { std::cout << '*' << " "; for (auto& i : ast) std::cout << i << " "; std::cout << "\n"; }
    std::cout << "---\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
     std::cout <<7%7<<" " << 12 % 7 << " " << 17 % 7 << " " << 19 % 7 << " " << 21 % 7 << " " << 35 % 7 << " ";
    /*
    int numCasos;
    std::cin >> numCasos;
    std::cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
        */
    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}