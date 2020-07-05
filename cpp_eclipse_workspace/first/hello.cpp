/*
 * hello1.cpp
 *
 *  Created on: 05-Jul-2020
 *      Author: deepakbhilare
 */

#include<iostream>
#include "hello.h"

hello::hello () {
    printf("\nConstructor 1");
    this->i = 10;
    this->j = 20;
}

hello::hello(int i, int j){
    printf("\nConstructor 2");
    this->i = i;
    this->j = j;
}

hello::~hello(){
    printf("\nDestructor");
}

int hello::getI(){
    return i;
}

void hello::setI(int i){
    this->i = i;
}

int hello::getJ(){
    return j;
}

void hello::setJ(int j){
    this->j = j;
}
