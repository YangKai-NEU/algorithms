#include <string>
#include <iostream>
using namespace std;

class Reverse {
public:
    string reverseString(string iniString) {
        // write code here
		string r=iniString;
		for(int i=0;i<r.length()/2;i++){
			char t=r[i];
			r[i]=r[r.length()-1-i];
			r[r.length()-1-i]=t;
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	Reverse r;
	string s="hdkwqkewqe";
	cout<<r.reverseString(s)<<endl;
	
	return 0;
}
