#ifndef inserccion
#define inserccion

#include <stdexcept>  // std::domain_error
#include <iostream>
#include"queue_eda.h"

template <class T>
class insert_queue : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void insert(insert_queue<T>& other, int p) {
		if (p == 0) {
			Nodo* aux = other.ult;
			aux->sig = this->prim;  //el ultimo de la que recibo tiene como siguiente el primero
			this->prim = other.prim; //cambio el primero de la lista
		}
		else {
			Nodo* aux = this->prim;
			for (int i = 0;i < p - 1;i++) aux = aux->sig; //aux apunta al que se le va a a insertar a continuacion
			Nodo* aux2 = other.ult; //puntero al ultimo que recibo
			aux2->sig = aux->sig;  //concatena el ultimo que recibo con el resto de la lista
			aux->sig = other.prim; //insercion el inicio de other

			if (p == this->size()) this->ult = other.ult;
		}
		this->nelems += other.nelems;
		//borrar other
		other.prim = nullptr;
		other.ult = nullptr;
		other.nelems = 0;
	}
	void print(std::ostream& o = std::cout) const {
		Nodo* i = this->prim;
		while (i != nullptr) {
			o << i->elem << " ";
			i = i->sig;
		}
	}
}
;
#endif // !inserccion

