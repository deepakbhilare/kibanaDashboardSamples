/*
 * sample.h
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

#ifndef SAMPLE_H_
#define SAMPLE_H_

class sample {
private:
	int a;
	int b;
public:
	sample();
	virtual ~sample();

	void setvalue(int a, int b);
	friend float mean(sample s);
};

#endif /* SAMPLE_H_ */
