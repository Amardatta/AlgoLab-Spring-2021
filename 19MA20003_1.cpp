/*Name: Amara Datta Dola
**Roll: 19MA20003
**Assignment 1
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;


typedef struct matrix //for method 4- matrix multiplication
{
	double a,b,c,d;   //[a,b]
				      //[c,d]
} Matrix;


double compute_iterative(int n)
{
	if(n==0)
		return 0;

	//if n>0
	double current= 1, previous= 0, next;

	for(int i=1; i<n; i++)
	{
		next= 2*current + previous;
		previous= current;
		current= next;
	}

	return current;
}

double compute_recursive(int n)
{
	if (n==0)
		return 0;

	else if(n==1)
		return 1.0;

	else 
		return 2*compute_recursive(n-1)+compute_recursive(n-2);
}

double power(double x, int n) //x^n
{
	if(n==0)
		return 1.0;

	else if(n==1)
		return x;

	else
	{
		double temp= power(x,n/2);

		if(n%2==0)
			return temp*temp;
		else
			return temp*temp*x;
	}
}

double compute_formula(int n)
{
	return ( power(1+sqrt(2),n)-power(1-sqrt(2),n) )/( 2.0*sqrt(2) );
}

Matrix matrix_multiply(Matrix x, Matrix y) //Multiply matrices x and y
{
	Matrix t;
	t.a= x.a * y.a + x.b * y.c;
	t.b= x.a * y.b + x.b * y.d;
	t.c= x.c * y.a + x.d * y.c;
	t.d= x.c * y.b + x.d * y.d;

	return t;
}


Matrix matrix_power(Matrix x, int n)
{
	if(n==1)
		return x;

	else
	{
		Matrix temp= matrix_power(x,n/2);

		Matrix Y= matrix_multiply(temp,temp);

		if(n%2==0) 			//n is even
			return Y;
		else				//n is odd
			return matrix_multiply(Y,x);
	}
}

double compute_matrix(int n)
{
	if(n==0)
		return 0;

	Matrix x;
	x.a= 2.0, x.b= 1.0, x.c= 1.0, x.d= 0.0;

	Matrix ans= matrix_power(x,n);
	return ans.b;
}


int main()
{
	int n;
	cout<<"Enter n :";
	cin>>n;

	cout.setf(ios::fixed );
	cout.setf(ios::showpoint);
	cout.precision(6); 

	double T1,T2,T3,T4, ans;

//1.Iterative
	clock_t begin = clock();
	ans= compute_iterative(n);
	clock_t end = clock();
	T1 = (double)(end - begin) / CLOCKS_PER_SEC;
	cout<< "1. J_"<< n <<" (Computed using iterative method) = "<< ans <<"\n";
	cout<<"Time taken in iterative method = "<< T1 <<" seconds\n\n";

//2.Recursive
	begin = clock();
	ans= compute_recursive(n);
	end = clock();
	T2 = (double)(end - begin) / CLOCKS_PER_SEC;
	cout<< "2. J_"<< n <<" (Computed using recursive method) = "<< ans <<"\n";
	cout<<"Time taken in recursive method = "<< T2 <<" seconds\n\n";


//3.Formula
	begin = clock();
	ans= compute_formula(n);
	end = clock();
	T3 = (double)(end - begin) / CLOCKS_PER_SEC;
	cout<< "3. J_"<< n <<" (Computed using Formula) = "<< ans <<"\n";
	cout<<"Time taken in formula = "<< T3 <<" seconds\n\n";

//4.Matrix
	begin = clock();
	ans= compute_matrix(n);
	end = clock();
	T4 = (double)(end - begin) / CLOCKS_PER_SEC;
	cout<< "4. J_"<< n <<" (Computed using Matrix multiplication) = "<< ans <<"\n";
	cout<<"Time taken in Matrix multiplication = "<< T4 <<" seconds\n\n";

	return 0;
}