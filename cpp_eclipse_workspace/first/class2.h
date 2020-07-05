/*
 * swap.h
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

#ifndef CLASS2_H_
#define CLASS2_H_

#include <iostream>

class class_2;
class class_1;

class class_2{
	int j;

public:
	class_2();
	~class_2();
	void indata(int a);
	int getdata();
	void display(void);
	friend void exchange(class_1 &c1, class_2 &c2);
};

class class_1 {
	int i;

public:
	class_1();
	~class_1();
	void indata(int a);
	int getdata();
	void display(void);
	friend void exchange(class_1 &c1, class_2 &c2);
};

#endif /* CLASS2_H_ */
