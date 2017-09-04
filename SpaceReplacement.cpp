#include <string>
#include <iostream>
using namespace std;

class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        // write code here
		string s="";
		for(int i=0;i<length;i++){
			if(iniString[i]==' '){
				s+="%20";
			}else{
				s+=iniString[i];
			}
		}
		return s;
    }
};

int main(int argc, char *argv[])
{
	Replacement r;
	string s="I love you";
	cout<<r.replaceSpace(s,s.length())<<endl;
	
	return 0;
}
