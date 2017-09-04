#include <iostream>
#include <string>
using namespace std;

int f(string s){
	int r=0;
	for(int i=2;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			r*=16;
			r+=(s[i]-'0');
		}else{
			r*=16;
			r+=(s[i]-'A'+10);
		}
	}
	return r;
}

int main(int argc, char *argv[])
{
	string s;
	while(cin>>s){
		cout<<f(s)<<endl;
	}
	
	return 0;
}
