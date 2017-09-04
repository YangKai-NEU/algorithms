#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern)
    {
		int n=strlen(str);
		int m=strlen(pattern);
		if(n==0){
			if(m%2==1){
				return false;
			}
			for(int i=1;i<m;i+=2){
				if(pattern[i]!='*'){
					return false;
				}
			}
			return true;
		}
		if(m==0){
			return false;
		}
		if(m==1){
			if(str[0]!=pattern[0]&&pattern[0]!='.'){
				return false;
			}else{
				return n==1;
			}
		}
		if(pattern[1]!='*'){
			if(str[0]!=pattern[0]&&pattern[0]!='.'){
				return false;
			}
			char t1[100];
			char s1[100];
			int p=0;
			for(int i=1;i<n;i++){
				s1[p++]=str[i];
			}
			s1[p]='\0';
			p=0;
			for(int i=1;i<m;i++){
				t1[p++]=pattern[i];
			}
			t1[p]='\0';
			return match(s1,t1);
		}else{
			char t2[100];
			char s1[100];
			int p=0;
			for(int i=1;i<n;i++){
				s1[p++]=str[i];
			}
			s1[p]='\0';
			p=0;
			for(int i=2;i<m;i++){
				t2[p++]=pattern[i];
			}
			t2[p]='\0';
			if(str[0]!=pattern[0]&&pattern[0]!='.'){
				return match(str,t2);
			}else{
				return match(s1,pattern)||match(s1,t2)||match(str,t2);
			}
		}
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	char a[]="bbbba";
	char b[]=".*a*a";
	cout<<solution.match(a,b)<<endl;
	
	return 0;
}
