/*

http://www.reddit.com/r/dailyprogrammer/comments/2nr6c4/20141129_challenge_190_practical_exercise_the/
---

The Complex Number

Specification:
You are to implement a class representing a complex number.
It is to be represented by floating-point number fields for the Real and Imaginary components.
It is to expose a method GetModulus which returns a floating point number representing the modulus of the complex number.
It is to expose a method GetConjugate which returns another Complex number representing the complex conjugate.
It is to have 3 static/shared/classifier methods, each taking 2 parameters, for the 3 operations Add, Subtract and 
	Multiply, each performing its respective operation and returning a Complex with the result of the operation.
It is to expose a method ToString which converts the complex number to its string representation correctly: eg. "3-2i", "1-i" or "13".

Extension:
If you are feeling up to it, implement these, too:
It is to expose a method GetArgument which returns a floating point angle, in radians, representing the argument of the complex number.
It is to have another static method taking 2 parameters for the operation Divide, which divides two complex numbers.

*/

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
	float argument();
	Complex conjugate();
	std::string to_string();
	friend Complex operator*(Complex left, Complex right);
	friend Complex operator/(Complex left, Complex right);
	friend Complex operator+(Complex left, Complex right);
	friend Complex operator-(Complex left, Complex right);

private:
	float m_real;
	float m_imag;
};

#endif