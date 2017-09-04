/*
如果一个01串任意两个相邻位置的字符都是不一样的,我们就叫这个01串为交错01串。例如: "1","10101","0101010"都是交错01串。
小易现在有一个01串s,小易想找出一个最长的连续子串,并且这个子串是一个交错01串。小易需要你帮帮忙求出最长的这样的子串的长度是多少。 
输入描述:
输入包括字符串s,s的长度length(1 ≤ length ≤ 50),字符串中只包含'0'和'1'


输出描述:
输出一个整数,表示最长的满足要求的子串长度。

输入例子1:
111101111

输出例子1:
3
*/

#include <string>
#include <iostream>
using namespace std;

int maxLength(string s){
	int r=1;
	for(int i=0;i<s.length();i++){
		int tmp=1;
		for(int j=i+1;j<s.length();j++){
			if(s[j]==s[j-1]){
				break;
			}else{
				tmp++;
			}
		}
		r=r<tmp?tmp:r;
	}
	return r;
}

int main(int argc, char *argv[])
{
	string s;
	cin>>s;
	cout<<maxLength(s)<<endl;
	
	return 0;
}
