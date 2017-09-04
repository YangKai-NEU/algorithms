/*
题目描述
继MIUI8推出手机分身功能之后，MIUI9计划推出一个电话号码分身的功能：首先将电话号码中的每个数字加上8取个位，然后使用对应的大写字母代替 （"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"）， 然后随机打乱这些字母，所生成的字符串即为电话号码对应的分身。
输入描述:
第一行是一个整数T（1 ≤ T ≤ 100)表示测试样例数；接下来T行，每行给定一个分身后的电话号码的分身（长度在3到10000之间）。
输出描述:
输出T行，分别对应输入中每行字符串对应的分身前的最小电话号码（允许前导0）。
示例1
输入

4
EIGHT
ZEROTWOONE
OHWETENRTEO
OHEWTIEGTHENRTEO
输出

0
234
345
0345
*/

#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int cor(int x){
    if(x>=8){
        return x-8;
    }else{
        return x+10-8;
    }
}

void spl(string s,vector<int> &result){
	string a[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	int c[26]={0};
	for(int i=0;i<s.length();i++){
		c[s[i]-'A']++;
	}
	int b[10]={0};
	b[0]=c['Z'-'A'];
	b[6]=c['X'-'A'];
	b[2]=c['W'-'A'];
	b[4]=c['U'-'A'];
	b[5]=c['F'-'A']-b[4];
	b[7]=c['V'-'A']-b[5];
	b[8]=c['G'-'A'];
	b[3]=c['T'-'A']-b[2]-b[8];
	b[9]=c['I'-'A']-b[5]-b[6]-b[8];
	b[1]=c['N'-'A']-b[7]-2*b[9];
    int r[10]={0};
    for(int i=0;i<10;i++){
        r[cor(i)]=b[i];
    }
	for(int i=0;i<10;i++){
		for(int j=0;j<r[i];j++){
			result.push_back(i);
		}	
	}
}

string f(string s){
	vector<int> t;
    spl(s,t);
	//cout<<t.size()<<endl;
	sort(t.begin(),t.end());
	char a[10000]={'\0'};
	for(int i=0;i<t.size();i++){
		sprintf(a,"%s%d",a,t[i]);
	}
	string b=a;
	return b;
}

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
    vector<string> s;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
        s.push_back(t);
	}
    for(int i=0;i<s.size();i++){
        cout<<f(s[i])<<endl;
    }
	
	return 0;
}
