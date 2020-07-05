/*
 * time.h
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

#ifndef TIME_H_
#define TIME_H_

class time1 {
	int hours;
	int minutes;

public:

	time1();
	time1(int i, int j);
	~time1();

	void gettime(int h, int m);
	void puttime();
	void sum(time1, time1);
};

#endif /* TIME_H_ */
