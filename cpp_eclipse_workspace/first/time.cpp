/*
 * time1.cpp
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

//#include "time1.h"

#include <iostream>
#include "time.h"

time1 :: time1(){
	this->hours = 0;
	this->minutes = 0;
}

time1 :: time1(int m, int h){
	this->hours = h;
	this->minutes = m;
}

time1 :: ~time1(){
	std::cout<<"\ndestructor\n";
}

void time1 :: sum(time1 t1, time1 t2){
	minutes = t1.hours + t2.hours;
	hours = minutes / 60;
	minutes = minutes % 60;
	hours = hours + t1.hours + t2.hours;
}

void time1 :: puttime(){
	std::cout << hours << " hours | ";
	std::cout << minutes << " minutes";
}

void time1 :: gettime(int h, int m){
	hours = h;
	minutes = m;
}

int main2 (){
	time1 T1, T2, T3;

	T1.gettime(2, 45);
	T2.gettime(3, 30);

	T3.sum(T1, T2);

	std::cout<<"T1 = "; T1.puttime(); std::cout << "\n";
	std::cout<<"T1 = "; T2.puttime(); std::cout << "\n";
	std::cout<<"T1 = "; T3.puttime(); std::cout << "\n";


	return 0;
}
