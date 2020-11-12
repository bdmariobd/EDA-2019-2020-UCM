// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include<queue>
// función que resuelve el problema
void resolver(std::deque<int> &dq) {
    std::queue<int> aux;
    int n = dq.size();
    for (int i = 0;i < n;++i) {
        if (dq.front() >= 0) dq.push_back(dq.front());
        else aux.push(dq.front());
        dq.pop_front();
    }
    while (!aux.empty()) {
        dq.push_front(aux.front());
        aux.pop();
    }
    for (auto& i : dq) std::cout << i<<" ";
    std::cout << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,aux;
    std::cin >> n;
    if (n==0)
        return false;
    std::deque<int> dq;
    for (int i = 0;i < n;++i) {
        std::cin >> aux;
        dq.push_back(aux);
    }
    resolver(dq);
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
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
