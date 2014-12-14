#include <math.h>
#include <sstream>

#include "complex.h"

Complex::Complex(float real, float imag)
{
	m_real = real;
	m_imag = imag;
}

float Complex::getReal()
{
	return m_real;
}

float Complex::getImaginary()
{
	return m_imag;
}

float Complex::modulus()
{
	return std::pow((std::pow((double)m_real,2.0)+std::pow((double)m_imag,2.0)),(0.5));
}

float Complex::argument()
{
	return std::atan2(m_imag, m_real);	
}

Complex Complex::conjugate()
{
	return Complex(m_real, m_imag*(-1));
}

std::string Complex::to_string()
{
	std::stringstream buffer;
	std::string result;

	if( m_imag >= 0 )
	{
		buffer << m_real << "+" << m_imag << "i";
	}
	else
	{
		buffer << m_real << m_imag << "i";
	}

	buffer >> result;

	return result;
}

Complex operator*(Complex left, Complex right)
{
	float new_real = left.m_real * right.m_real + left.m_imag * right.m_imag * -1;
	float new_imag = left.m_real * right.m_imag + left.m_imag * right.m_real;

	return Complex(new_real, new_imag);
}

Complex operator/(Complex left, Complex right)
{
	Complex numerator = left * right.conjugate();
	Complex denominator = right * right.conjugate();

	return Complex(numerator.m_real / denominator.m_real, numerator.m_imag / denominator.m_real);
}

Complex operator+(Complex left, Complex right)
{
	return Complex(left.m_real + right.m_real, left.m_imag + right.m_imag);
}

Complex operator-(Complex left, Complex right)
{
	return Complex(left.m_real - right.m_real, left.m_imag - right.m_imag);
}