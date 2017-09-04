#include <iostream>
using namespace std;

class O
{
};

class A
{
	virtual void f(){}
};

class B:public A
{
};

int main(int argc, char *argv[])
{
	cout<<sizeof(O)<<endl;
	cout<<sizeof(A)<<endl;
	cout<<sizeof(B)<<endl;

	int **a[3][4];
	cout<<sizeof(a)<<endl;
	cout<<sizeof(*a)<<endl;
	
	return 0;
}
