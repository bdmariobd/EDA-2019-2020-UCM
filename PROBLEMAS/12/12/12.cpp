// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include<queue>

// función que resuelve el problema

int resolver(std::queue<int>& alumnos, int k) {
    int i = 0,aux;
    while (alumnos.size() != 1) {
        aux = alumnos.front();
        alumnos.pop();
        alumnos.push(aux);
        ++i;
        if (i == k) {
            alumnos.pop();
            i = 0;
        }
    }
    return alumnos.front();
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    std::cin >> n >> k;
    if (n==0 || k==0)
        return false;
    std::queue<int> alumnos;
    for (int i = 1;i <= n;++i) alumnos.push(i);

    // escribir sol
    std::cout << resolver(alumnos, k) << '\n';

    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-12.1.in");
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
