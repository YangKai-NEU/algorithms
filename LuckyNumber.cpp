#include <iostream>
using namespace std;

int sum(int n,int s){
	int r=0;
	while(n){
		r+=n%s;
		n/=s;
	}
	return r;
}

int f(int n){
	int s=0;
	for(int i=1;i<=n;i++){
		if(sum(i,2)==sum(i,10)){
			s++;
		}
	}
	return s;
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		cout<<f(n)<<endl;
	}
	
	return 0;
}
