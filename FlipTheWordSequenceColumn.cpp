#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        string result="";
		vector<string> s;
		string tmp="";
		for(int i=0;i<str.length();i++){
			if(str[i]==' '){
				if(tmp!=""){
					s.push_back(tmp);
					tmp="";
				}
			}else{
				tmp+=str[i];
			}
		}
		if(tmp!=""){
			s.push_back(tmp);
		}
		for(int i=s.size()-1;i>=0;i--){
			result+=s[i];
			if(i!=0){
				result+=" ";
			}
		}
        if(result==""){
            result=str;;
        }
		return result;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.ReverseSentence("I love world!")<<endl;
	
	return 0;
}
