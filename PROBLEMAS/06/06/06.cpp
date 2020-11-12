// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include<string>

// función que resuelve el problema
bool abierto(const char& i) {
    return i == '(' || i == '{' || i == '[';
}
bool cerrado(const char& i) {
    return i == ')' || i == '}' || i == ']';
}
bool coinciden(const char& i, const char& j) {
    if (i == '(' && j == ')')return true;
    if (i == '[' && j == ']')return true;
    if (i == '{' && j == '}')return true;
    return false;
}
bool resolver(std::string frase) {
    std::stack<char> pila;
    for (char& aux : frase) {
        if (abierto(aux)) {
            pila.push(aux);
        }
        else if (cerrado(aux)) {
            if (!pila.empty() && coinciden(pila.top(), aux)) pila.pop();
            else return false;
        }
    }
    return pila.empty();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string frase;
    std::getline(std::cin, frase);
    if (! std::cin)
        return false;
    // escribir sol
    if (resolver(frase))std::cout << "SI\n";
    else std::cout << "NO\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-06.1.in");
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