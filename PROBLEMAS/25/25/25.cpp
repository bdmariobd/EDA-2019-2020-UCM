// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

bool multiplo7(int n) {
    if (n == 7) return false;
    return n % 7 == 0;
}
bool esPrimo(int n) {
    int i = 2;
    while (i < n) {
        if (n % i == 0)return false;
        ++i;
    }
    return true;
}
//1st: elemento.  2nd: profundidad
std::pair<int, int> primos(const bintree<int>& t) {
    if (t.empty()) return { -1,0 };
    //if (t.left().empty() && t.right().empty()) {
    if(multiplo7(t.root())) return { t.root(),1 };
    if(esPrimo(t.root())) return { -1,0 };
    //no es primo pero tampoco multiplo, miro hijos
    auto izq = primos(t.left()), dcha = primos(t.right());
    if (izq.first == -1) return { dcha.first,dcha.second + 1 };
    if (dcha.first == -1) return  { izq.first,izq.second + 1 };
    if (dcha.second < izq.second) return{ dcha.first,dcha.second + 1 };
    return { izq.first,izq.second + 1 };

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    auto sol = primos(leerArbol(-1));
    if (sol.first == -1) std::cout << "NO HAY \n";
    else  std::cout << sol.first << " " << sol.second << '\n';  
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