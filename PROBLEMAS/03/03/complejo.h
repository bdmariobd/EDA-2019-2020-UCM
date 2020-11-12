#ifndef COMPLEJO
#define COMPLEJO

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include<math.h>

class complejo {
private: float real, imag;
public:
	complejo(float real = 0, float imag = 0) {
		this->real = real;
		this->imag = imag;
	}
	float Real()const { return real; }
	float Imag()const { return imag; }
	complejo operator+(complejo const& other)const {
		return { Real() + other.Real() , Imag() + other.Imag() };
	}
	complejo operator*(complejo const& other)const {
		return { Real() * other.Real() - Imag() * other.Imag(), Real() * other.Imag() + Imag() * other.Real() };
	}
	float modulo()const {
		return sqrt(pow(Real(), 2) + pow(Imag(), 2));
	}
};


#endif // !COMPLEJO

