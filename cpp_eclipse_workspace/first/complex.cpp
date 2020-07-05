/*
 * complex.cpp
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

#include "complex.h"

complex::complex() {
	x = 0;
	y = 0;
}

complex::~complex() {
	// TODO Auto-generated destructor stub
}

void complex::input(float r, float i){
	x = r;
	y = i;
}

complex sum(complex X, complex Y){
	complex C;

	C.x = X.x + Y.x;
	C.y = X.y + Y.y;

	return C;
}

void complex::show()
{
	std::cout<<this->x;
	std::cout<<" ";
	std::cout<<this->y;
}

int main10(){
	complex A, B, C;

	A.input(10, 20);
	B.input(100, 20);

	C = sum(A, B);

	C.show();

	return 0;
}

