/*
 * ccplus.cpp
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

#include <iostream>
#include "ccplus.h"

ccplus::ccplus() {
	// TODO Auto-generated constructor stub
	i = 0;
	j = 0;

}

ccplus::ccplus(int ii, float jj) {
	i = ii;
	j = jj;
}

ccplus::~ccplus() {
	// TODO Auto-generated destructor stub
}

int ccplus::getI() {
	return i;
}

float ccplus::getJ() {
	return j;
}

void ccplus::setI(int ii) {
	i = ii;
}

void ccplus::setJ(float jj) {
	j = jj;
}

void ccplus::display() {
	std::cout << this->i;
	std::cout << " ";
	std::cout << this->j;
	std::cout << "\n";

}

ccplus ccplus::operator +(ccplus &a) {
	ccplus A;

	A.i = a.i + this->i;
	A.j = a.j + this->j;

	return A;
}

ccplus ccplus::operator -(ccplus &a) {
	ccplus A;

	A.i = a.i - this->i;
	A.j = a.j - this->j;

	return A;
}

ccplus ccplus::operator *(ccplus &a) {
	ccplus A;

	A.i = a.i * this->i;
	A.j = a.j * this->j;

	return A;
}

ccplus ccplus::operator /(ccplus &a) {
	ccplus A;

	A.i = a.i * this->i;
	A.j = a.j * this->j;

	return A;
}

bool ccplus::operator <(ccplus &a) {
	if (this->i < a.i && this->j < a.j)
		return true;

	return false;
}

bool ccplus::operator >(ccplus &a) {
	if (this->i > a.i && this->j > a.j)
		return true;

	return false;
}

bool ccplus::operator <=(ccplus &a) {
	if (this->i <= a.i && this->j <= a.j)
		return true;

	return false;
}

bool ccplus::operator >=(ccplus &a) {
	if (this->i >= a.i && this->j >= a.j)
		return true;

	return false;
}

bool ccplus::operator ==(ccplus &a) {
	if (this->i == a.i && this->j == a.j)
		return true;

	return false;
}

void ccplus::operator ++(){
	++this->i;
	++this->j;
}

void ccplus::operator --(){
	--this->i;
	--this->j;
}

ccplus ccplus::operator ++(int a){
	ccplus c;

	this->i ++;
	this->j ++;

	return c;
}

ccplus ccplus::operator --(int a){
	ccplus c;

	this->i --;
	this->j --;

	return c;
}

ostream& operator << (ostream &out, const ccplus& a){
	out << a.i;
	out << " ";
	out << a.j;

	return out;
}

/*istream& ccplus::operator >> (istream &in, const ccplus &a){
	cout << "enter values : ";
	in >> atoi(a.i) >> atof(a.j);

	return in;
}*/

int main() {
	ccplus a(10, 10.5);
	ccplus b(5, 5.7);

	ccplus c;

	c = a + b;

	c.display();

	printf("[ %d] ", a < b);

	ccplus d(0, 0);
	ccplus e(0, 0);

	printf("[ %d] ", a == b);

	std::cout << "\n";

	++a;
	a.display();

	printf("\nhere : ");

	b.display();
	--b;
	b.display();

	printf("\nhere 2 : ");

	b.display();
	b++;
	b.display();
	b--;
	b.display();

	printf("\nhere 3 : ");

	cout<< a;

	return 0;
}
