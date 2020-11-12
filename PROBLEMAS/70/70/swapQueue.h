#ifndef swap_h
#define swap_h

#include <stdexcept>  // std::domain_error
#include <iostream>
#include"queue_eda.h"

template <class T>
class swap_queue : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void swap() {
		auto* i = this->prim, *j=i->sig;
		if (j == nullptr) return;
		auto* sigAux = j->sig, *antAux=i;
		this->prim = j;
		j->sig = i;
		i->sig = sigAux;
		i = sigAux;
		if (i == nullptr) {
			this->ult = antAux; return;
		}
		
		while (i != nullptr && j != nullptr) {
			j = i->sig;
			antAux = i;
			sigAux = j->sig;
			j->sig = i;
			i->sig = sigAux;
			i = sigAux;
		}
		if (i == nullptr) this->ult = antAux;

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
#endif // !swap_h

