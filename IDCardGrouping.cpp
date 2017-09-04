#include <string.h>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	char a[10000];
	while(gets(a)){
		string b=a;
		for(int i=0;i<b.length();i++){
			if(i==6||i==14){
				cout<<" ";
			}
			cout<<b[i];
		}
		cout<<endl;
	}
	
	return 0;
}
