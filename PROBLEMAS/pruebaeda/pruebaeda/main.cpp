
// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)
//Mario Blanco Domínguez (09) y Javier Ignacio Sotelino Barriga

#include <iostream>                              
#include <fstream>                              
#include <algorithm>
#include <unordered_map>
#include<vector>
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO

bool resuelveCaso() { //coste de la solucion: O(N+M)
   int N, M;
   cin >> N >> M;
   if (!cin)
      return false;
   unordered_map<string, vector<string>> sucesos; //diccionario NO ORDENADO que almacena la clave(suceso) y un vector con las horas en las que ocurrio
   string suc, hora;
   for (int i = 0;i < N;++i) { //coste O(N) siendo N el numero de avisos
       cin >> suc >> hora;
       sucesos[suc].push_back(hora);
   }
   int orden;
   for (int i = 0;i < M;++i) { //coste O(M) siendo M el numero de datos a consultar
       cin >> suc >> orden;
       if (orden > sucesos[suc].size())cout << "-- ";
       else cout << sucesos[suc][orden-1] << " ";
   }
   cout << "\n";
   
   return true;
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
