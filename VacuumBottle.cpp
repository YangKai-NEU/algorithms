#include <iostream>
using namespace std;

int f(int n){
	if(n<=1){
		return 0;
	}
	if(n==2){
		return 1;
	}
	return n/3+f(n+n/3-(n/3)*3);
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		cout<<f(n)<<endl;
	}
	return 0;
}
