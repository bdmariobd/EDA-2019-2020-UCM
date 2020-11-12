// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
template <typename T>
bool ladosSimetricos(const bintree<T>& izq, const bintree<T>& dcha) {
    if ((izq.empty() && !dcha.empty()) || (!izq.empty() && dcha.empty())) return false;
    if (izq.empty() && dcha.empty()) return true;
    return izq.root()==dcha.root() && ladosSimetricos(izq.left(), dcha.right()) && ladosSimetricos(izq.right(), dcha.left());
}
template <typename T>
bool simetrico(const bintree<T>& t) {
    return t.empty()? true: ladosSimetricos(t.left(), t.right());
}
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> t = leerArbol('.');
    std::cout << (simetrico(t) ? "SI" : "NO") << '\n';
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