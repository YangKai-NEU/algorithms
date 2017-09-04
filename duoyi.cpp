#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class AA
{
};
class BB
{
	BB(){}
	virtual ~BB(){}
};

class CC
{
	virtual ~CC(){}
	short a;
	int b;w
	char c;
	unsigned char d;
};


int main(int argc, char *argv[])
{
	int a[20];
	char *p1=(char*)a;
	char *p2=(char*)(a+5);
	
	int n=p2-p1;
	cout<<n<<endl;
	return 0;
}
