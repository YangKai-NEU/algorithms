#include <iostream>
#include <string>
#include <vector>
using namespace std;

void process(vector<string> &r,string s,string pre){
	if(s==""){
		if(pre!=""){
			r.push_back(pre);
		}
		return;
	}
	string q1(pre);
	q1+=s[0];
	string tmp1="";
	for(int j=1;j<s.length();j++){
		tmp1+=s[j];
	}
	process(r,tmp1,q1);
	process(r,tmp1,pre);
}

int main(int argc, char *argv[])
{
	string s;
	vector<string> r;
	while(cin>>s){
		process(r,s,"");
		for(int i=0;i<r.size();i++){
			cout<<r[i]<<endl;
		}
	}
	
	
	return 0;
}
