// NOMBRES Y APELLIDOS
//Mario Blanco Domínguez  (E09)
//Javier Ignacio Sotelino Barriga   (E67)
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

//1st devuelve el camino de pares mas largo encontrado
//2nd profundidad de pares 
std::pair<int, int> resolver(const bintree<int>& t) {
    if (t.empty()) return { 0,0 };
    auto izq = resolver(t.left()), dcha = resolver(t.right());
    bool par = t.root() % 2 == 0;
    return {
        //si es par, devuelvo el maximo entre los ya encontrados y el formado por la raiz. Si es impar, no tengo en cuenta el formado por la raiz
        par? std::max(std::max(izq.first,dcha.first),izq.second+dcha.second+1): std::max(izq.first,dcha.first),
        //si el nodo es impar, corto la profundidad
        par?std::max(izq.second,dcha.second)+1:0
    };

}
int caminoPares(bintree<int> arbol) {
   // completar (posiblemente definiendo también otras funciones)
    return resolver(arbol).first;
}

void resuelveCaso() {
   bintree<int> arbol = leerArbol(-1);
   cout << caminoPares(arbol) << '\n';
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   for (int i = 0; i < numCasos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
