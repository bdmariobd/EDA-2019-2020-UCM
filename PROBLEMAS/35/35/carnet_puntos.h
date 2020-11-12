#ifndef carnet_puntos_h
#define carnet_puntos_h

#include <algorithm>
#include <iostream>
#include <string>
#include<unordered_map>
#include<list>
#include<map>
using dni = std::string;
using puntos = int;

class carnet_puntos {
private:
	std::unordered_map<dni, std::pair<std::list<dni>::iterator,puntos>> cond;
	std::unordered_map<puntos, std::list<dni>> condPtos;

	 /*
	 Para obtener costes óptimos, se utiliza un mapa desordenado clave puntos valor lista de dni's para los puntos
	 para los conductores, se utiza un mapa desordenado clave dni valor par de puntos e iterador a la lista antes mencionada
	 Al almacenar el iterador la operacion erase se vuelve constante
	 */
public:
	void nuevo(dni d){  //coste O(1)
		if (cond.count(d) > 0) throw std::domain_error("Conductor duplicado");
		auto it = condPtos[15].end();
		//el insert de las listas devuelve el iterador que apunta a la posicion
		cond[d] = { condPtos[15].insert(it,d),15 };
	}
	void quitar(dni d, puntos p) { //coste O(1)
		if (cond.count(d) <= 0) throw std::domain_error("Conductor inexistente");
		if (p == 0)return;
		puntos ant = cond[d].second, nuevos = std::max(0, ant- p);
		if (ant == nuevos) return;
		condPtos[ant].erase(cond[d].first);
		auto it = condPtos[nuevos].end();
		cond[d] = { condPtos[nuevos].insert(it,d),nuevos };

	}
	void recuperar(dni d, puntos p) {//coste O(1)
		if (cond.count(d) <= 0) throw std::domain_error("Conductor inexistente");
		if (p == 0)return;
		puntos  ant = cond[d].second, nuevos = std::min(15, ant + p);
		if (ant == nuevos) return;
		condPtos[ant].erase(cond[d].first);
		auto it = condPtos[nuevos].end();
		cond[d] = { condPtos[nuevos].insert(it,d),nuevos };
	}
	void consultar(dni d) { //coste O(1)
		if (cond.count(d) <= 0) throw std::domain_error("Conductor inexistente");
		std::cout << "Puntos de " << d << ": " << cond[d].second << '\n';
	}
	void cuantos_con_puntos(puntos p) { //coste O(1)
		if (p < 0 || p>15) throw std::domain_error("Puntos no validos");
		int cantidad;
		if (condPtos.count(p) <= 0) cantidad= 0;
		else cantidad= condPtos[p].size();
		std::cout << "Con " << p << " puntos hay " << cantidad << '\n';
	}
	void lista_por_puntos(puntos p) {  //coste O(conductores con p ptos)
		if (p < 0 || p>15) throw std::domain_error("Puntos no validos");
		std::cout << "Tienen " << p << " puntos: ";
		if (condPtos.count(p) <= 0) {
			std::cout << '\n';
			return;
		}
		auto it = condPtos[p].rbegin(), end = condPtos[p].rend(); //iterador reverse
		while (it != end) {
			std::cout << *it << " ";
			++it;
		}
		std::cout<<'\n';

	}
};
#endif // !carnet_puntos

