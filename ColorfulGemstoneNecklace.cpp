/*
题目描述
有一条彩色宝石项链，是由很多种不同的宝石组成的，包括红宝石，蓝宝石，钻石，翡翠，珍珠等。有一天国王把项链赏赐给了一个学者，并跟他说，你可以带走这条项链，但是王后很喜欢红宝石，蓝宝石，紫水晶，翡翠和钻石这五种，我要你从项链中截取连续的一小段还给我，这一段中必须包含所有的这五种宝石，剩下的部分你可以带走。如果无法找到则一个也无法带走。请帮助学者找出如何切分项链才能够拿到最多的宝石。
输入描述:
我们用每种字符代表一种宝石，A表示红宝石，B表示蓝宝石，C代表紫水晶，D代表翡翠，E代表钻石，F代表玉石，G代表玻璃等等，我们用一个全部为大写字母的字符序列表示项链的宝石序列，注意项链是首尾相接的。每行代表一种情况。
输出描述:
输出学者能够拿到的最多的宝石数量。每行一个
示例1
输入

ABCYDYE
ATTMBQECPD
输出

1
3
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int f(string s){
	string a="ABCDE";
	int r=100000;
	int n=s.length();
	string p=s;
	for(int i=0;i<s.length();i++){
		p+=s[i];
	}
	for(int i=0;i<p.length();i++){
		map<char,int> mmap;
		int j;
		for(j=i;j<p.length();j++){
			int k;
			for(k=0;k<5;k++){
				if(!mmap[a[k]]){
					break;
				}
			}
			if(k==5){
				break;
			}
			mmap[p[j]]=1;
		}
		if(j==p.length()){
			break;
		}else{
			r=r<j-i?r:j-i;
		}
	}
	return r==100000?-1:n-r;
}

int main(int argc, char *argv[])
{
	string s;
	while(cin>>s){
		cout<<f(s)<<endl;
	}
	
	return 0;
}
