
// NOMBRE Y APELLIDOS (USUARIO DEL JUEZ)
//Mario Blanco Dominguez.   Usuario E09
// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
/*
Para resolver el problema se utiliza una funcion auxiliar que devuelve un par:
El primer valor es la suma de los valores descendientes + la raiz y el segundo valor es el numero de 
nodos acumuladores encontrados, siendo este segundo valor el que devuelve la función principal.

Si el arbol es vacio(caso base) devuelve 0 como suma y 0 como acumuladores encontrados. Si no, busca en ambos
hijos, comprueba si el nodo actual es acumulador viendo si la raiz es igual a la suma de los hijos.first. 
Devuelve como suma la suma de los dos hijos mas la raiz, y como segundo, si el nodo actual es acumulador, le suma 1
a los acumuladores de los hijos, si no los deja tal cual

El coste de la solución es O(n) siendo n el numero de nodos del arbol, ya que se recorre el arbol pasando por cada
nodo del arbol una sola vez con operaciones que son constantes
*/

#include <iostream>                                             
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


// Implementa aquí la función pedida. Puedes definir las funciones
// auxiliares que necesites

//El primer valor es la suma de los descendientes + la raiz
//El segundo valor es el numero de nodos acumuladores encontrados
std::pair<int, int> busqueda(const bintree<int>& t) { //funcion auxiliar que resuelve el problema
    if (t.empty()) return {0,0}; //caso base
    auto izq = busqueda(t.left()), dcha = busqueda(t.right()); //busqueda en los hijos
    bool acumulador = izq.first + dcha.first == t.root(); //comprueba si el nodo actual es acumulador
    return { izq.first + dcha.first + t.root() , acumulador ? izq.second + dcha.second + 1 : izq.second + dcha.second };
}

int acumuladores(const bintree<int>& t) { //funcion principal
    return busqueda(t).second;
}
void resuelveCaso() {
   auto arbol = leerArbol(-1);
   cout << acumuladores(arbol) << '\n';
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
   // system("PAUSE");
#endif
   return 0;
}
