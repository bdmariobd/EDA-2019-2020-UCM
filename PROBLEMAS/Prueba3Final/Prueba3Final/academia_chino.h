
// NOMBRE Y APELLIDOS 
//Mario Blanco Domínguez

// COMENTARIO SOBRE LA SOLUCIÓN:  cada operacion y cada atributo esta comentado ya
// NO OLVIDES PONER EL COSTE JUSTIFICADO DE CADA OPERACIÓN JUNTO A ELLA

#ifndef ACADEMIACHINO
#define ACADEMIACHINO

#include <iostream>     
#include <string>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include<set>
#include<list>
using namespace std;

using dni = string;
using grupo = int;

class academia_chino {
private: 
	unordered_map<dni, pair<grupo,list<dni>::iterator>> alumnos;
	//mapa sin orden clave alumno valor un par que indica su grupo y un iterador a la lista de su grupo
	//guardar el iterador consigue coste constante al borrarlo de la lista de su grupo

	set<dni> grad;
	//conjunto de dni's de alumnos graduados(grupo 6). necesita orden para ordenar 
	//alfabeticamente los alumnos solo del grupo 6

	unordered_map<grupo, list<dni>> grupos;
	//mapa desordenado clave grupo valor lista de alumnos. sirve para poder decir quien es el novato, ya que al insertar siempre al final
	//se queda al final de la lista el novato. el iterador que del que se ha hablado arriba apunta a alguna de estas listas


public:

	//coste: O(1) si el grupo es del 1 al 5 (todo operaciones costantes sobre mapas desordenados) 
	//o O(log n) si el grupo es 6(tiene que insertar en un cjo con orden) 
	//se tiene que insertar un nuevo dni (con su grupo e iterador) al mapa desordenado alumnos
	//se tiene que insertar un nuevo a alumno a la lista del su grupo(contenidas en el mapa desordenado grupo)
	//en caso de ser grupo 6 , se inserta en un conjunto ordenado
	void nuevo_estudiante(dni d, grupo g) {
		if (g < 1 || g>6) throw domain_error("Grupo incorrecto"); //grupo invalido
		if(alumnos.count(d)!=0) throw domain_error("Estudiante existente"); //si ya esta en el mapa de alumnos
		auto it = grupos[g].end(); //fin de lista del grupo g
		alumnos[d] = { g,grupos[g].insert(it,d) }; //inserta en el mapa una clave dni valor : (su grupo, iterador a la lista de su grupo (al final de la lista))
		if (g == 6) grad.insert(d); //en caso de recibir grupo 6, se tiene que insertar en el conjunto ordenado, lo cual subiria el coste
    }

	//coste: O(1), operaciones constantes sobre un mapa desordenado
	//se tiene que devolver el grupo del alumno d mediante acceso al mapa desordenado alumnos
	int grupo_estudiante(dni d)const { 
		auto it = alumnos.find(d); //iterador, busqueda del alumno en mapa desordenado
		if (it == alumnos.end()) throw domain_error("Estudiante no existente");
		int grupo = it->second.first; //acceso a su grupo
		if (grupo == 6) throw domain_error("Estudiante ya graduado");
		return grupo;
	}


	//coste: O(1) si el grupo nuevo es del 1 al 5 (todo operaciones costantes sobre mapas desordenados) 
	//o O(log n) si el grupo nuevo es 6(tiene que insertar en un cjo con orden) siendo n el nº de personas graduadas
	//se tiene que eliminar al alumno de la lista de su grupo actual e insertarlo en la lista de su nuevo grupo 
	//Tambien se tiene que cambiar su grupo y su iterador en el mapa ordenado alumnos. En caso de ya ser 6, no hace nada
	//en caso de ser el nuevo grupo 6, se tiene que insertar en el conjunto ordenado
	void promocionar(dni d) {
		auto it = alumnos.find(d);
		if (it == alumnos.end()) throw domain_error("Estudiante no existente");
		int grupo = it->second.first; //busqueda del grupo
		if (grupo == 6) throw domain_error("Estudiante ya graduado");
		grupos[grupo].erase(it->second.second); //lo borra de la lista de su grupo, al tener el iterador (y ser un acceso a un mapa desordenado) es constante
		auto git = grupos[grupo+1].end(); //fin de lista del grupo g
		alumnos[d] = { grupo + 1, grupos[grupo + 1].insert(git,d) };  //inserta en el mapa una clave dni valor : (su grupo +1, iterador a la lista de su grupo (al final de la lista))
		if(grupo+1==6) grad.insert(d);//en caso de que su nuevo grupo sea 6, se tiene que insertar en el conjunto ordenado, lo cual subiria el coste
	}

	//coste: o(n) siendo n el nº de personas graduadas
	//se vuelca el set en una lista
	list<dni> graduados()const {
		list<dni> l;
		for (auto& a : grad) l.push_back(a); //hago n accesos constantes al set (ya que estoy iterando, no es a un elemento concreto), coste O(N)
		return l;
	}
	//coste O(1), ya que solo son accesos a un mapa desordenado
	//se tiene que acceder a la lista del grupo g y devolver el ultimo insertado
	dni novato(grupo g)const {
		if (g < 1 || g>6) throw domain_error("Grupo incorrecto");
		auto it = grupos.find(g); //iterador para encontrar la lista del grupo g
		if(it == grupos.end() || it->second.empty()) throw domain_error("Grupo vacio"); //si la lista esta vacia o todavia nadie se graduo en este grupo
		return it->second.back(); //devuelvo el ultimo elemento de la lista, o sea, el mas reciente insertado
	}
};

#endif
