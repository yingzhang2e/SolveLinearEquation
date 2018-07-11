//============================================================================
// Name        : solveEquation.cpp
// Author      : Ying Zhang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include<stdio.h>
//#include<conio.h>
//#include <math.h>
#include "SolveLinearEquation.h"

int main()
{
	SolveLinearEquation solveLinearEquation;
    int  var;
    ifstream inputfile;
    inputfile.open("input.txt");
    if (!inputfile.is_open()) {
        std::cerr << "There was a problem opening the input file" << std::endl;
        exit(EXIT_FAILURE);
    }
    while(!inputfile.eof())
    {
    	inputfile>>var;
    	cout << "\n var = " << var << endl;
    	double **array=new double *[var];
    	for(int i=0;i<var;i++)
    	{
    		array[i]=new double [var+1];
    		for(int j=0;j<=var;j++){
    			inputfile>> array[i][j];
    		}

    	}
    	cout<<"*****The Equation coefficients ****************"<<endl;
    	solveLinearEquation.print(var,array);
    	solveLinearEquation.solution(var,array);

    	solveLinearEquation.release(var,array);
    }
    //cout << "\ndone"<<endl;
    return 0;
}
