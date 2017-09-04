#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string a;
	char b[10000];
	while(gets(b)){
		a=b;
		map<char,int> mmap;
		for(int i=0;i<a.length();i++){
			if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
				mmap[a[i]]++;
				if(mmap[a[i]]==3){
					cout<<a[i]<<endl;
					break;
				}
			}
			
		}
	}
	
	return 0;
}
