
// Mario Blanco E09

#ifndef HORAS_H
#define HORAS_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument

class horas {
private:
   int HH; // las horas
   int MM; // los minutos
   int SS; // los segundos 
public:
   // constructora
   horas(int h=0, int m=0, int s=0) {
       if (valido(h,m,s)) {
           HH = h;
           MM = m;
           SS = s;
       }
       else throw std::domain_error("ERROR\n");
   }
   
   // observadoras
   int hora() const { return HH; }
   int minuto() const { return MM; }
   int segundo() const { return SS; }
   bool valido(int h , int m , int s) const {
       return 0 <= h && h <= 23 && 0 <= m && m <= 59 && 0 <= s && s <= 59;
   }
   // operador de comparación
   bool operator<(horas const& h) const {
       return this->hora() * 3600 + this->minuto() * 60 + this->segundo() <
           h.hora() * 3600 + h.minuto() * 60 + h.segundo();
   }

   void read(std::istream & input = std::cin) {
       int h, m, s;
       char aux;
       input >> h >> aux >> m >> aux >> s;
       if (valido(h, m, s)) {
           HH = h;
           MM = m;
           SS = s;
       }
       else throw std::domain_error("ERROR\n");
   }
   void print(std::ostream& o = std::cout) const {
      o << std::setfill('0') << std::setw(2) << HH << ':'
        << std::setfill('0') << std::setw(2) << MM << ':'
        << std::setfill('0') << std::setw(2) << SS;
   }
};

inline std::ostream & operator<<(std::ostream & salida, horas const& h) {
   h.print(salida);
   return salida;
}

inline std::istream & operator>>(std::istream & entrada, horas & h) {
   h.read(entrada);
   return entrada;
}

#endif
