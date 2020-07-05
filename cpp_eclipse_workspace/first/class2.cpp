/*
 * swap.cpp
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

#include "class2.h"

class_2::class_2() {
	j = 0;
}

class_1::class_1() {
	i = 0;
}

class_1::~class_1() {
}

class_2::~class_2() {
}

int class_1 :: getdata(){
	return i;
}

int class_2 :: getdata(){
	return j;
}

void class_1 :: indata(int p){
	this->i = p;
}

void class_2 :: indata(int q){
	this->j = q;
}

void class_1 :: display(){
	std::cout << i; std::cout << " ";
}

void class_2 :: display(){
	std::cout << j; std::cout << " ";
}

void exchange(class_1 & X, class_2 & Y){
	int temp = X.getdata();
	X.i = Y.getdata();
	Y.j = temp;

}

int main5(){
	class_1 A;
	class_2 B;

	A.indata(100);
	B.indata(200);

	A.display();
	B.display();

	exchange(A, B);

	std::cout << "\n";

	A.display();
	B.display();
}
