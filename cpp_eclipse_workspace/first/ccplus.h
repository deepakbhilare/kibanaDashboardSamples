/*
 * ccplus.h
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

#ifndef CCPLUS_H_
#define CCPLUS_H_

#include <iostream>

using namespace std;

class ccplus {
private:
	int i;
	float j;
public:
	ccplus();
	ccplus(int i, float j);
	virtual ~ccplus();

	int getI();
	float getJ();

	void setI(int i);
	void setJ(float j);

	void display();

	ccplus operator +(ccplus& a);
	ccplus operator -(ccplus& a);
	ccplus operator *(ccplus& a);
	ccplus operator /(ccplus& a);

	bool operator <(ccplus& a);
	bool operator >(ccplus& a);
	bool operator <=(ccplus& a);
	bool operator >=(ccplus& a);
	bool operator ==(ccplus& a);
	void operator ++();
	void operator --();

	ccplus operator ++(int);
	ccplus operator --(int);

    friend ostream & operator << (ostream &out, const ccplus& a);
    //istream & operator >> (istream &in, const ccplus &a);
};

#endif /* CCPLUS_H_ */
