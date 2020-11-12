
// Mario Blanco E09

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "horas.h"

bool resuelveCaso() {
    int t, h;
    cin >> t >> h;
    if (t == 0 && h == 0)return false;
    vector<horas> datos(t);
    for (horas& i : datos) cin >> i;
    for (int i = 0;i < h;i++) {
        try {
            horas aux;
            cin >> aux;
            auto lower = lower_bound(datos.begin(), datos.end(), aux);
            if (lower == datos.end())cout << "NO\n";
            else cout << *lower << "\n";
        }
        catch (domain_error & e) {
            cout << e.what();
        }
    }
    cout << "---\n";
   return true;
}
int main() {
   // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
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
