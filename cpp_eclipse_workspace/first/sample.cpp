/*
 * sample.cpp
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */
#include<iostream>
#include "sample.h"

using namespace std;

sample::sample() {
	a = 0;
	b = 0;
}

sample::~sample() {
	cout << "\ndestructor\n";
}

void sample::setvalue(int a = 25, int b = 30){
	this->a = a;
	this->b = b;
}

float mean(sample s){
	return float(s.a + s.b)/2.0;
}

int main4(){
	sample X;

	X.setvalue();

	cout << mean(X);

	return 0;
}
