#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>

class Complex
{
public:
	Complex(float real, float imag);
	float getReal();
	float getImaginary();
	float modulus();
	Complex conjugate();
	std::string to_string();
	friend Complex operator*(Complex left, Complex right);
	friend Complex operator+(Complex left, Complex right);
	friend Complex operator-(Complex left, Complex right);

private:
	float m_real;
	float m_imag;
};

#endif