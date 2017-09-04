#include <iostream>
using namespace std;

int count1(int n){
	int r=0;
	while(n){
		n=n&(n-1);
		r++;
	}
	return r;
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		cout<<count1(n)<<endl;
	}
	
	return 0;
}
