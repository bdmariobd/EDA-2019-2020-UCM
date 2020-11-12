
// Mario Blanco E09

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "horas.h"
#include "pelicula.h"
bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0)return false;
    vector<pelicula> datos(n);
    for (pelicula& i : datos) cin >> i;
    sort(datos.begin(), datos.end());
    for (pelicula& i : datos) cout << i.inicio() + i.duracion() << " " << i.nombre()<<"\n";
    cout << "---\n";
   return true;
}
int main() {
   // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("sample-02.1.in");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // restablecimiento de cin
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("pause");
#endif
   return 0;
}
