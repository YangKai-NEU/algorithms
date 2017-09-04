#include <iostream>
using namespace std;

struct A1
{
	int a;
	short b;
	char c;
};

struct A2
{
	short b;
	int a;
	char c;
};

struct A3
{
	int a;
	char c;
	short b;
};

struct A4
{
	short b;
	char c;
	int a;	
};

struct A5
{
	char c;
	short b;
	int a;
};

struct A6
{
	char c;
	int a;
	short b;
};

struct A7
{
	char c[31];
	int a;
};

struct A8
{
	short a;
};

int main(int argc, char *argv[])
{
	cout<<"int\tshort\tchar\t:\t"<<sizeof(A1)<<endl;
	cout<<"short\tint\tchar\t:\t"<<sizeof(A2)<<endl;
	cout<<"int\tchar\tshort\t:\t"<<sizeof(A3)<<endl;
	cout<<"short\tchar\tint\t:\t"<<sizeof(A4)<<endl;
	cout<<"char\tshort\tint\t:\t"<<sizeof(A5)<<endl;
	cout<<"char\tint\tshort\t:\t"<<sizeof(A6)<<endl;

	cout<<"31char\tint\t:\t"<<sizeof(A7)<<endl;
	cout<<"short\t:\t"<<sizeof(A8)<<endl;
	
	return 0;
}
