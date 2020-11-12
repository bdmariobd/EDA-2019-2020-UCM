#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include<sstream>
#include <unordered_map>
#include <list>

using namespace std;
using cancion = string;
using artista = string;
class ipud {
private:
	int tpl=0;
	struct tCancion {
		artista autor;
		int duracion;
		list<cancion>::iterator enRecientes, enPlaylist;
	};
	list<cancion> playlist;
	unordered_map<cancion, tCancion> ipod;
	list<cancion>recientes;

public:
	void addSong(const cancion & S, const artista& A, const int& D) {
		if (ipod.count(S) != 0) throw domain_error("ERROR addSong");
		tCancion nuevo{ A,D,recientes.end(),playlist.end()}; //
		ipod[S] = nuevo;
	}
	void addToPlaylist(const cancion &S) {
		if (ipod.count(S) == 0) throw domain_error("ERROR addToPlaylist");
		if (ipod[S].enPlaylist != playlist.end()) { return; }
		ipod[S].enPlaylist = playlist.insert(playlist.end(), S);
		tpl += ipod[S].duracion;// donde y el que. añade por el final y actualizo el it
	}
	void current()const {
		if(playlist.empty())throw domain_error("ERROR current");
		cancion actual = *playlist.begin();
		cout<<actual<<"\n";
	}
	void play() {
		if (playlist.empty()) printf("No hay canciones en la lista\n");
		else {
			cancion Actual = *playlist.begin();
			cout << "Sonando " << Actual << "\n";
			if (ipod[Actual].enRecientes != recientes.end()) { //ya esta
				recientes.erase(ipod[Actual].enRecientes);
				
			}
			ipod[Actual].enRecientes = recientes.insert(recientes.end(), Actual);	
			playlist.erase(playlist.begin());
			tpl -= ipod[Actual].duracion;
			ipod[Actual].enPlaylist = playlist.end();

		}
	}
	void totalTime() const{
		cout << "Tiempo total: ";
		if (playlist.empty()) cout << 0 << "\n";
		else cout << tpl << "\n";
	}
	void recent(int N) const {
		if (recientes.empty())cout << "No hay canciones recientes\n";
		else{
			cout << "Las " << N << " mas recientes son\n";
			auto fin = recientes.end(), it = recientes.begin();
			for(int i=0;it!=fin && i<N ;++i){
				cout <<"    "<<*it << "\n";
				it++;
			}
		}

	}
	void deleteSong(cancion S) {
		if (ipod.count(S) == 0) return;
		if (!playlist.empty() && ipod[S].enPlaylist != playlist.end()) {
			tpl -= ipod[S].duracion;
			playlist.erase(ipod[S].enPlaylist);
		}
			
		if (!recientes.empty() && ipod[S].enRecientes != recientes.end())
		recientes.erase(ipod[S].enRecientes);

		ipod.erase(S);
	}
};