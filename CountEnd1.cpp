#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int f(int n){
	int r=0;
	while(n){
		n>>=1;
		r+=n;
	}
	return r;
}

int f1(int n){
	int r=0;
	int t=n;
	while(t){
		r+=t%2;
		t>>=1;
	}
	return n-r;
}

string c(int n){
	int r=1;
	string s="";
	while(n){
		r*=n--;
	}
	while(r){
		s+=('0'+r%2);
		r/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		cout<<c(n)<<"\t"<<f(n)<<"\t"<<f1(n)<<endl;
	}
	
	return 0;
}
