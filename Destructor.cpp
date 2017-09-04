#include <iostream>
using namespace std;

class A
{
public:
	virtual ~A(){
		cout<<"A has been destructed"<<endl;	
	}
};

class B: public A
{
public:
	~B(){
		cout<<"B has been destructed"<<endl;	
	}
};

int main(int argc, char *argv[])
{
	A *a=new B();
	delete a;

	/*
		B has been destructed
		A has been destructed

		�������virtual�Ļ�������ǣ�
		A has been destructed

	*/

	cout<<endl;

	B *b=new B();
	delete b;
	
	return 0;
}
