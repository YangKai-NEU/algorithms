#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
		string a="";
		for(int i=0;i<length;i++){
			if(str[i]==' '){
				a+="%20";
			}else{
				a+=str[i];
			}
		}
		strcpy(str,a.c_str());
	}
};

int main(int argc, char *argv[])
{
	char a[]="Hello World!";
	Solution solution;
	solution.replaceSpace(a,strlen(a));
	cout<<a<<endl;
	
	return 0;
}
