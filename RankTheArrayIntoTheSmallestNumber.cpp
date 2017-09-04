#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> s;
		for(int i=0;i<numbers.size();i++){
			char tp[100];
			sprintf(tp,"%d",numbers[i]);
			s.push_back(tp);
		}
		for(int i=0;i<s.size();i++){
			for(int j=i+1;j<s.size();j++){
				string a=s[i]+s[j];
				string b=s[j]+s[i];
				if(a>b){
					string t=s[i];
					s[i]=s[j];
					s[j]=t;
				}
			}
		}
		string result="";
		for(int i=0;i<s.size();i++){
			result+=s[i];
		}
		return result;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	int a[]={2,3,4,5,4,4,23,4,4};
	vector<int> s;
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	cout<<solution.PrintMinNumber(s)<<endl;

	return 0;
}
