#include <string>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	char a[1000];
	while(gets(a)){
		string b=a;
		string r="";
        bool state=false;
		for(int i=b.length()-1;i>=0;i--){
			if(b[i]=='.'){
                state=true;
				break;
			}else{
				r+=b[i];
			}
		}
        if(state){
            reverse(r.begin(),r.end());
			cout<<r<<endl;
        }else{
            cout<<"null"<<endl;
        }
		
	}
	
	return 0;
}
