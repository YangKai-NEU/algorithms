#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int r=0;
		int i=strlen(s)-1;
		while(s[i]==' '){
			i--;
		}
		for(;i>=0;i--){
			if(s[i]==' '){
				break;
			}else{
				r++;
			}
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	char a[]="q ";
	cout<<s.lengthOfLastWord(a)<<endl;
	
	return 0;
}
