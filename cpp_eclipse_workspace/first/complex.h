/*
 * complex.h
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

class complex {
private:
	float x;
	float y;
public:
	complex();
	virtual ~complex();

	void input(float real, float imag);
	friend complex sum(complex, complex);
	void show();
};

#endif /* COMPLEX_H_ */
