#include <string>
#include <iostream>
using namespace std;

string XOR(string a,string b){
	int n=a.length();
	string c="";
	for(int i=0;i<n;i++){
		c+=('0'+(a[i]-'0')^(b[i]-'0'));
	}
	return c;
}

int f(string a){
	int b=0;
	for(int i=0;i<a.length();i++){
		b*=2;
		b+=(a[i]-'0');
	}
	return b;
}

int main(int argc, char *argv[])
{
	int n;
	string a,b;
	while(cin>>n){
		cin>>a>>b;
		string c=XOR(a,b);
		cout<<f(c)<<endl;
	}
	
	return 0;
}
