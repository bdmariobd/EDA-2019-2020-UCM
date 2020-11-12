//Nombre del alumno Mario Blanco Dominguez
// Usuario del Juez E09
#ifndef pol
#define pol

#include<vector>
#include<math.h>
class polinomio {
private:
	std::vector <std::pair<int, int>> p;
	
public:
	polinomio() {}
	int binarySearch(int ini, int fin, const std::pair<int, int>& mon) {
		if (ini == fin) return ini;
		else {
			int mitad = (ini + fin) / 2;
			if (p[mitad].second > mon.second) return binarySearch(ini, mitad, mon);
			else if (p[mitad].second < mon.second) return binarySearch(mitad+1, fin, mon);
			else {//igual exponente, sumo coeficientes
				p[mitad].first += mon.first;
				return -1;
			}
		}
	}
	void add(const std::pair<int,int> & mon) {
		int pos = binarySearch(0, p.size(), mon);
		if (pos != -1) p.insert(p.begin() + pos, mon); 
	}
	int evaluar(int n)const {
		int res = 0;
		for (auto& i:p) {
			res += i.first* pow(n,i.second);
		}
		return res;
	}
};
#endif // !pol

