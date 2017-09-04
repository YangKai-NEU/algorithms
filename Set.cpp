/*
[编程题] 集合
时间限制：1秒
空间限制：32768K
小易最近在数学课上学习到了集合的概念,集合有三个特征：1.确定性 2.互异性 3.无序性.
小易的老师给了小易这样一个集合：
S = { p/q | w ≤ p ≤ x, y ≤ q ≤ z }
需要根据给定的w，x，y，z,求出集合中一共有多少个元素。小易才学习了集合还解决不了这个复杂的问题,需要你来帮助他。 
输入描述:
输入包括一行：
一共4个整数分别是w(1 ≤ w ≤ x)，x(1 ≤ x ≤ 100)，y(1 ≤ y ≤ z)，z(1 ≤ z ≤ 100).以空格分隔


输出描述:
输出集合中元素的个数

输入例子1:
1 10 1 1

输出例子1:
10
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	int a,b,c,d;
	while(cin>>a>>b>>c>>d){
		vector<double> s;
		for(int i=a;i<=b;i++){
			for(int j=c;j<=d;j++){
				s.push_back(i*1.0/j);
			}
		}
		sort(s.begin(),s.end());
		for(int i=s.size()-1;i>0;i--){
			if(s[i]==s[i-1]){
				s.erase(s.begin()+i);
			}
		}
		cout<<s.size()<<endl;
	}
	
	return 0;
}
