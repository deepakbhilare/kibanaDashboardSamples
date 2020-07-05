/*
 * friendf.cpp
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

#include "friendf.h"

using namespace std;

friendf::friendf() {
	// TODO Auto-generated constructor stub
	x = 100;

}

friendf::~friendf() {
	// TODO Auto-generated destructor stub
}

void max(friend2 a, friendf b){
	if(a.y > b.x)
		cout << a.y;
	else
		cout << b.x;
}

int main3(){
	friend2 X;
	friendf Y;

	X.setvalue(300);
	Y.setvalue(300);

	max(X, Y);

	return 0;
}

