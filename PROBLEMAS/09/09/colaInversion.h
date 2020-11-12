#ifndef inserccion
#define inserccion

#include <stdexcept>  // std::domain_error
#include <iostream>
#include"queue_eda.h"

template <class T>
class invertida : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void invierte() {
		if (this->empty()) return;
		Nodo* i,*siguiente,*aux;
		i = this->prim;
		siguiente = i->sig;
		while (siguiente != nullptr) {
			aux = siguiente->sig;
			siguiente->sig = i;
			i = siguiente;
			siguiente = aux;
		}
		aux = this->ult;
		this->ult = this->prim;
		this->prim = aux;
		this->ult->sig = nullptr;
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

