#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

int sum(int n,int k){
	int s=0;
	while(n){
		s+=n%k;
		n/=k;
	}
	return s;
}

string f(int n){
	int s=0;
	for(int i=2;i<n;i++){
		s+=sum(n,i);
	}
	int a=s;
	int b=n-2;
	int c=min(a,b);
	//找最大公约数
	while(a%c!=0||b%c!=0){
		c--;
	}
	a/=c;
	b/=c;
	char r[1000];
	sprintf(r,"%d/%d",a,b);
	return r;
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		cout<<f(n)<<endl;
	}
	
	return 0;
}
