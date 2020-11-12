#ifndef inserccion
#define inserccion

#include <stdexcept>  // std::domain_error
#include <iostream>
#include"queue_eda.h"

template <class T>
class insert_queue : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void insert(insert_queue & other) {
		if (other.empty()) return;
		if (this->empty()) {
			this->prim = other.prim;
			this->ult = other.ult;
			this->nelems = other.nelems;
			other.prim = nullptr;
			other.ult = nullptr;
			other.nelems = 0;
			return;
		}
		Nodo* i = this->prim, * j = i->sig, * k = other.prim;
		if (k->elem <= i->elem) {
			Nodo* aux = k;
			while (aux->sig != nullptr && aux->sig->elem <= i->elem) aux = aux->sig;
			this->prim = k;
			k = aux->sig;
			aux->sig = i;
			
		}
		while (j!=nullptr && k!=nullptr) {
			if (k->elem<= j->elem && k->elem>= i->elem) {
				Nodo* aux = k;
				while (aux->sig != nullptr && aux->sig->elem <= j->elem) aux = aux->sig;
				i->sig = k;
				k = aux->sig;
				aux->sig = j;
			}
			i = j;
			j = j->sig;
		}
		if (j == nullptr) {
			i->sig = k;
			this->ult = other.ult;
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
		o << '\n';
	}
}
;
#endif // !inserccion

