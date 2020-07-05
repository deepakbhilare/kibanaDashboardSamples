/*
 * hello1.h
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

#ifndef HELLO_H_
#define HELLO_H_

#include<iostream>

class hello {
    private:
        int i;
        int j;

    public:
        hello();
        hello(int i, int j);
        ~hello();

        int getI();
        int getJ();

        void setI(int i);
        void setJ(int j);
};

#endif /* A_HXX_ */
