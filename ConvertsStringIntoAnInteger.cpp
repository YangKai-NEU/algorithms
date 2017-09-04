#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
		string si="1234567890+-eE";
		map<char,int> mmap;
		for(int i=0;i<si.length();i++){
			mmap[si[i]]=1;
		}
        int a=0;
		bool state=true;
		int pos=0;
		if(str[pos]=='+'){
			pos++;
		}else if(str[pos]=='-'){
			state=false;
			pos++;
		}
		for(int i=pos;i<str.length();i++){
			if(!mmap[str[i]]){
				return 0;
			}else{
				a*=10;
				a+=(str[i]-'0');
			}
		}
		return state?a:-a;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.StrToInt("-123")<<endl;
	
	return 0;
}
