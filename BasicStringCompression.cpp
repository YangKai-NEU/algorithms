#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Zipper {
public:
    string zipString(string iniString) {
        // write code here
		vector<pair<char,int> > s;
		char pre='-';
		int prec=0;
		for(int i=0;i<iniString.length();i++){
			if(pre=='-'){
				pre=iniString[i];
				prec=1;
			}else{
				if(iniString[i]==pre){
					prec++;
				}else{
					s.push_back(make_pair(pre,prec));
					pre=iniString[i];
					prec=1;
				}
			}
		}
		if(prec!=0){
			s.push_back(make_pair(pre,prec));
		}
		string r;
		char tmp[10000]={'\0'};
		bool state=true;
		for(int i=0;i<s.size();i++){
			if(s[i].second!=1){
				state=false;
				break;
			}
		}
		for(int i=0;i<s.size();i++){
			if(state){
				sprintf(tmp,"%s%c",tmp,s[i].first);
			}else{
				sprintf(tmp,"%s%c%d",tmp,s[i].first,s[i].second);
			}
		}
		r=tmp;
		return r;
    }
};

int main(int argc, char *argv[])
{
	Zipper z;
	string a="aabcccccaaa";
	cout<<z.zipString(a)<<endl;
	
	return 0;
}
