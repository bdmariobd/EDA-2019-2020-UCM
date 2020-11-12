#ifndef carnet_puntos_h
#define carnet_puntos_h

#include <algorithm>
#include <iostream>
#include <string>
#include<unordered_map>

using dni = std::string;
using puntos = int;

class carnet_puntos {
private:
	std::unordered_map<dni, puntos> cond;
	std::unordered_map<puntos, int> condXptos;
	//se utiliza un mapa desordenado porque no interesa el orden y conseguimos
	//coste constante en operaciones de inserción, borrado y consulta.
	//se usa un mapa desordenado clave puntos valor cantidad de personas para hacer la operacion
	//cuantos_con_puntos constante
public:
	void nuevo(dni d){  //coste O(1)
		if (cond.count(d) > 0) throw std::domain_error("Conductor duplicado");
		cond[d] = 15;
		condXptos[15]++;
	}
	void quitar(dni d, puntos p) { //coste O(1)
		if (cond.count(d) <= 0) throw std::domain_error("Conductor inexistente");
		puntos nuevos = std::max(0, cond[d] - p);
		condXptos[cond[d]]--;
		condXptos[nuevos]++;
		cond[d] =nuevos;
	}
	void consultar(dni d) { //coste O(1)
		if (cond.count(d) <= 0) throw std::domain_error("Conductor inexistente");
		std::cout << "Puntos de " << d << ": " << cond[d] << '\n';
	}
	void cuantos_con_puntos(puntos p) { //coste O(1)
		if (p < 0 || p>15) throw std::domain_error("Puntos no validos");
		int cantidad;
		if (condXptos.count(p) <= 0) cantidad= 0;
		else cantidad= condXptos[p];
		std::cout << "Con " << p << " puntos hay " << cantidad << '\n';
	}
};
#endif // !carnet_puntos

