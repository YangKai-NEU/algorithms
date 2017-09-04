#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	char a[10000];
	string b;
	while(gets(a)){
		b=a;
		vector<string> s;
		string pre="";
		for(int i=0;i<b.length();i++){
			if(b[i]==' '){
				if(pre!=""){
					s.push_back(pre);
					pre="";
				}
			}else{
				pre+=b[i];
			}
		}
		if(pre!=""){
			s.push_back(pre);
		}
		reverse(s.begin(),s.end());
		for(int i=0;i<s.size();i++){
			cout<<s[i];
			if(i!=s.size()-1){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}
