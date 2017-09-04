/*
最长公共子序列
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

int lcs(string a,string b){
	vector<vector<int>/**/> s(a.length()+1,vector<int>(b.length()+1,0));
	for(int i=0;i<a.length();i++){
		for(int j=0;j<b.length();j++){
			if(a[i]==b[j]){
				s[i+1][j+1]=1+s[i][j];
			}else{
				s[i+1][j+1]=s[i+1][j]<s[i][j+1]?s[i][j+1]:s[i+1][j];
			}
		}
	}
	return s[a.length()][b.length()];
}

int main(int argc, char *argv[])
{
	string a="ABCBD";
	string b="BACBC";
	cout<<lcs(a,b)<<endl;
	
	return 0;
}
