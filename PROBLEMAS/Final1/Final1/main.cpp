
// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)
//MARIO BLANCO DOMÍNGUEZ         E09

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
/*
Se itera la lista hasta el ultimo elemento de la lista original. Si es menor o igual que el pivote, avanzo (constante). Si no, reordeno los nodos(colocando mi elemento
al final de la lista, es decir, en la posición anterior al fantasma) y reordeno las uniones dejadas por el elemento desplazado al final, también con un coste constante.
Se recorren todos los nodos menos el ultimo en la lista original con coste constante. Al final se comprueba si el ultimo original también hay que desplazarlo al final, 
en caso de tener que hacerlo el coste también es constante ya que se trata de lo mismo. 

Conclusión: coste O(N) siendo N el número de elementos.
*/

#include <iostream>               
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class ListaParticion : public deque<int> {
public:
   void print(std::ostream& o = std::cout) const {
       Nodo* i = fantasma->sig;
       while (i != fantasma) {
           o << i->elem<<" ";
           i = i->sig;
       }
   }
   
   // produce la partición de la lista respecto al privote
   void particion(int pivote) {
       Nodo* i = fantasma->sig, *ult=fantasma->ant;
       //puntero i sirve para recorrer la lista y el ultimo sirve como pivote para detener
       while (i != ult) {
           if (i->elem <= pivote) {//si no hay que reordenar, paso al siguiente, con coste constante constante
               i = i->sig;
           }
           else {//si es mayor que el pivote, tengo que colocar el elemento al final de la lista
               Nodo* aux = i->ant; //nodo auxiliar al elemento anterior para modificar su siguiente
               i->ant = fantasma->ant;   //el anterior a mi elemento es el que antes era el ultimo
               i->ant->sig = i;  //el siguiente del anterior ultimo es mi elemento
               fantasma->ant = i; //el ultimo es mi elemento
               aux->sig = i->sig; //reordeno el 'hueco' dejado
               i->sig = fantasma; //el siguiente del ultimo es el fantasma
               aux->sig->ant = aux;
               i = aux->sig; //avanzo
               //en caso de mover al final, el coste es constante
           }
       }
       //si el ultimo de la lista original tiene que ser desplazado al final, se hace de la misma manera que los demás
       if (i->elem > pivote) {
           Nodo* aux = i->ant;
           i->ant = fantasma->ant;
           i->ant->sig = i;
           fantasma->ant = i;
           aux->sig = i->sig;
           i->sig = fantasma;
           aux->sig->ant = aux;
           i = aux->sig;
       }
      // rellenar
   }
};



/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream & o, ListaParticion const& a) {
   a.print(o);
   return o;
}

bool resuelveCaso() {
   int N, pivote;
   cin >> N >> pivote;
   if (!cin)
      return 0;
   
   ListaParticion lista;
   // leemos la lista de la entrada
   int elem;
   for (int i = 0; i < N; ++i) {
      cin >> elem;
      lista.push_back(elem);
   }
   
   
   lista.particion(pivote);
   
   cout << lista << '\n';
   
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
   // system("PAUSE");
#endif
   return 0;
}
