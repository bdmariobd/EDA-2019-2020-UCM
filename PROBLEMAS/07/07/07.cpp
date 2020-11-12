// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include<stack>

typedef struct {
    std::string date;
    int f;
}tAccident;
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (! std::cin)
        return false;
    std::stack<tAccident> pila;
    tAccident aux;
    // función que resuelve el problema
    for (int i = 0;i < n;i++) {
        std::cin >> aux.date>>aux.f;
        while (!pila.empty() && pila.top().f <= aux.f) pila.pop(); //segunda entrega->cambiado < por <=
        if (pila.empty()) std::cout << "NO HAY\n";
        else std::cout << pila.top().date << '\n';
        pila.push(aux);
    }
    std::cout << "---\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-07.1.in");
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