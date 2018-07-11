/*
 * SolveLinearEquation.h
 *
 *  Created on: May 28, 2018
 *      Author: Edward
 */


#ifndef SOLVELINEAREQUATION_H_
#define SOLVELINEAREQUATION_H_

#include <iostream>
#include <fstream>

using namespace std;


class SolveLinearEquation {
public:
	SolveLinearEquation();
	virtual ~SolveLinearEquation();

	void print(int n, double **a);
	void release(int m,double **temp);
	double** solution(int n,double **a);
	void releaseArr(int var, double** arr);

};

#endif /* SOLVELINEAREQUATION_H_ */
