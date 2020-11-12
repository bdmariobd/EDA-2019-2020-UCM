// Nombre del alumno Mario Blanco
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include <deque>
#include <stack>

// función que resuelve el problema
bool vocal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' ||
        c == 'o' || c == 'u' || c == 'A' ||
        c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
void volcarPila(std::string& decoded, std::stack<char>& cons) {
    while (!cons.empty()) {
        decoded.push_back(cons.top());
        cons.pop();
    }
}
std::string decodifica(const std::string&msg) {
    std::deque<char> st1, st2;
    bool inicio = true;
    for (char i : msg) {
        if (inicio) st1.push_back(i);
        else st2.push_front(i);
        inicio ^= true;
    }
    while (!st2.empty()) {
        st1.push_back(st2.front());
        st2.pop_front();
    }
    //1º fase decodificada en st1
    std::string decoded;
    std::stack<char> cons;//da la vuelta a las consonantes
    while (!st1.empty()) {
        if (vocal(st1.front())) {
            volcarPila(decoded, cons);
            decoded.push_back(st1.front());
        }
        else cons.push(st1.front());
        st1.pop_front();
    }
    volcarPila(decoded, cons);
    //2ª fase decodificada en decoded
    return decoded;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string msg;
    std::getline(std::cin,msg);
    if (! std::cin)
        return false;
    // escribir sol
    std::cout << decodifica(msg) << '\n';
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-14.1.in");
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