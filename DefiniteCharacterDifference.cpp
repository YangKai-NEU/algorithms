#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Different {
public:
    bool checkDifferent(string s) {
        // write code here
		sort(s.begin(),s.end());
		for(int i=1;i<=s.length();i++){
			if(s[i]==s[i-1]){
				return false;
			}
		}
		return true;
    }
};

int main(int argc, char *argv[])
{
	Different d;
	string s="qweuhuehqwue";
	cout<<d.checkDifferent(s)<<endl;

	return 0;
}
