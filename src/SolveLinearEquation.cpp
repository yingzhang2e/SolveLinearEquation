/*
 * SolveLinearEquation.cpp
 *
 *  Created on: May 28, 2018
 *      Author: Edward
 */

#include "SolveLinearEquation.h"
#include <iostream>
#include <fstream>

using namespace std;


SolveLinearEquation::SolveLinearEquation() {

}

SolveLinearEquation::~SolveLinearEquation() {
	// TODO Auto-generated destructor stub
}
/**
 *
 */
void SolveLinearEquation::print(int n, double **a){
	for ( int i = 0;i < n;i++ ){
		for ( int j = 0;j <= n;j++ ){
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"**********************************************"<<endl;
}

void SolveLinearEquation::release(int m,double **temp)
{
    for(int i=0;i<m;i++)
        delete[] temp[i];
    delete[] temp;
}

double** SolveLinearEquation::solution(int n,double **a)
{
	double temp;
	    //print(n,a);
	    for(int i=0;i<n;i++)
	    {
	        temp=a[i][i];
	        for(int j=n;j>=i;j--)
	        {
	        	if((float)temp == 0.0)
	            {
	                  continue;

	            }
	            a[i][j]=a[i][j]/temp;

	            for(int k=i+1;k<n;k++)
	            {
	                a[k][j]-=(a[k][i]*a[i][j]);
	            }


	        }

	    }
	    //cout << "Triangle matrix"<< endl;
	    //print(n,a);

    for(int i=n-1;i>=0;i--)
    {

        for(int j=0;j<i;j++)
        {
        	if(a[i][i] == 0 && a[i][n] == 0)
        		continue;
        	else
        	{
        		a[j][n]-=(a[j][i]*a[i][n]);
        		a[j][i]=0;
        	}
        }
    }
    //cout << " diagonal matrix"<< endl;
    cout<<"*****The Diagonal Matrixs *******************"<<endl;
    print(n,a);
    cout<<"*****The Solutions are **********************";
    for ( int i = 0;i < n;i++ )
    {
    	if((float)a[i][i]==0.0 && (float)a[i][n]==0.0){
    		printf( "\nTHE VALUE OF x%d IS unlimited.", i + 1);
    		//continue;
    	} else {
    		bool hasno0 = false;
    		for(int j=i+1;j<n;j++){
    			if ((float)a[i][j] != 0.0){
    				hasno0 = true;
    				//break;
    			}
    		}
    		if(hasno0)
    			printf( "\nTHE VALUE OF x%d IS unlimited.", i + 1);
    		else
    			printf( "\nTHE VALUE OF x%d IS %f", i + 1, ( float ) a[ i ][ n ] );/// ( float ) a[ i ][ i ] )
    	}
    }
    return a;
}
