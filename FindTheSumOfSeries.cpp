#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
	int a,b;
	while(cin>>a>>b){
		double t=a;
		double result=0;
		for(int i=0;i<b;i++){
			result+=t;
			t=sqrt(t);
		}
		printf("%.2lf\n",result);
	}
	
	return 0;
}
