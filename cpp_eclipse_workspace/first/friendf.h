/*
 * friendf.h
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

#ifndef FRIENDF_H_
#define FRIENDF_H_

#include <iostream>

class friend2;

class friendf {
public:
	int x;
	friendf();
	virtual ~friendf();

	void setvalue(int i){
		x = i;
	}

	friend void max(friendf, friend2);
};

class friend2 {
public:
	int y;
	void setvalue(int i){
		y = i;
	}

	friend void max(friendf, friend2);
};

#endif /* FRIENDF_H_ */
