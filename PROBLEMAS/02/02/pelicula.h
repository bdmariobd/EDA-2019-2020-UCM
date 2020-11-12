
// Mario Blanco 

#ifndef peli
#define peli

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include<string>
#include "horas.h"

class pelicula{
    private:
        std::string titulo; 
        horas ini; // los minutos
        horas dur; // los segundos 


    public:
        pelicula(){}
        pelicula(std::string titula, horas ini, horas dur) {
            titulo = titula;
            this->ini = ini;
            this->dur = dur;
        }
        horas inicio()const { return ini; }
        horas duracion()const { return dur; }
        std::string nombre()const { return titulo; }
        bool operator<(pelicula const& other) const {
            return inicio() + duracion() < other.inicio() + other.duracion() ||
                (inicio() + duracion() == other.inicio() + other.duracion() && nombre()<other.nombre());
        }

        void read(std::istream& input = std::cin) {
            input >> ini >> dur;
            input.ignore();
            getline(input,titulo);
        }

        
};

inline std::istream& operator>>(std::istream& entrada, pelicula& p) {
    p.read(entrada);
    return entrada;
}
#endif