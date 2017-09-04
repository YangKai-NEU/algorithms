/*
[编程题] 魔力手环
时间限制：1秒
空间限制：32768K
小易拥有一个拥有魔力的手环上面有n个数字(构成一个环),当这个魔力手环每次使用魔力的时候就会发生一种奇特的变化：每个数字会变成自己跟后面一个数字的和(最后一个数字的后面一个数字是第一个),一旦某个位置的数字大于等于100就马上对100取模(比如某个位置变为103,就会自动变为3).现在给出这个魔力手环的构成，请你计算出使用k次魔力之后魔力手环的状态。 
输入描述:
输入数据包括两行：
第一行为两个整数n(2 ≤ n ≤ 50)和k(1 ≤ k ≤ 2000000000),以空格分隔
第二行为魔力手环初始的n个数，以空格分隔。范围都在0至99.


输出描述:
输出魔力手环使用k次之后的状态，以空格分隔，行末无空格。

输入例子1:
3 2
1 2 3

输出例子1:
8 9 7
*/

#include <iostream>
#include <vector>
using namespace std;

void process(vector<int> &s,int k){
	vector<int> p(s);
	for(int i=1;i<=k;i++){
		vector<int> tmp(s);
		tmp[0]=s[0]+s[1];
		for(int j=1;j<s.size()-1;j++){
			tmp[j]=s[j]+s[j+1];
		}
		tmp[tmp.size()-1]=s[tmp.size()-1]+s[0];
		bool t=true;
		for(int j=0;j<tmp.size();j++){
			s[j]=tmp[j]%100;
			if(s[j]!=p[j]){
				t=false;
			}
		}
		if(t){
			i=k-k%i;
		}
	}
}

int main(int argc, char *argv[])
{
	int n,k;
	cin>>n>>k;
	vector<int> s;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}
	process(s,k);

	for(int i=0;i<n;i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
