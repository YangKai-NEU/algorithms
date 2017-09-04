#include <map>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	string s;
	while(cin>>s){
		map<char,int> mmap;
		for(int i=0;i<s.length();i++){
			mmap[s[i]]++;
		}
		for(int i=0;i<s.length();i++){
			if(mmap[s[i]]){
				cout<<s[i];
				mmap[s[i]]=0;
			}
		}
		cout<<endl;
	}
	
	return 0;
}
