#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int> mmap;
		for(int i=0;i<str.length();i++){
			mmap[str[i]]++;
		}
		for(int i=0;i<str.length();i++){
			if(mmap[str[i]]==1){
				return i;
			}
		}
		return -1;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	string s="hwuiqhdinsjakhdksahf";
	cout<<solution.FirstNotRepeatingChar(s)<<endl;;

	
	return 0;
}
