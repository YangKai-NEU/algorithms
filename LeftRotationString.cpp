#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
		string s=str;
        for(int i=0;i<n;i++){
			s+=s[0];
			s.erase(s.begin());
		}
		return s;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.LeftRotateString("abcdefg",3)<<endl;
	
	return 0;
}
