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

void f(int n){
	int s=0;
	int i;
	for(i=2;i<n;i++){
		s+=sum(n,i);
	}
	int a=s;
	int b=n-2;
	while(1){
		int t=a<b?a:b;
		int i;
		for(i=2;i<=t;i++){
			if(a%i==0&&b%i==0){
				a/=i;
				b/=i;
				break;
			}
		}
		if(i==t+1){
			break;
		}
	}
	cout<<a<<"/"<<b<<endl;
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		f(n);
	}
	
	return 0;
}
