/*
题目描述
设有n个正整数，将他们连接成一排，组成一个最大的多位整数。
如:n=3时，3个整数13,312,343,连成的最大整数为34331213。
如:n=4时,4个整数7,13,4,246连接成的最大整数为7424613。
输入描述:
有多组测试样例，每组测试样例包含两行，第一行为一个整数N（N<=100），第二行包含N个数(每个数不超过1000，空格分开)。
输出描述:
每组数据输出一个表示最大的整数。
示例1
输入

2
12 123
4
7 13 4 246
输出

12312
7424613
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;

string f(vector<int> &s){
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			char a1[100];
			char a2[100];
			sprintf(a1,"%d%d",s[i],s[j]);
			sprintf(a2,"%d%d",s[j],s[i]);
			if(strcmp(a2,a1)>0){
				int t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
	}
	char a[10000]={'\0'};
	for(int i=0;i<s.size();i++){
		sprintf(a,"%s%d",a,s[i]);
	}
	string b=a;
	return b;
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		vector<int> s;
		for(int i=0;i<n;i++){
			int t;
			cin>>t;
			s.push_back(t);
		}
		cout<<f(s)<<endl;
	}
	
	return 0;
}
