/*
[编程题] 双核处理
时间限制：1秒
空间限制：32768K
一种双核CPU的两个核能够同时的处理任务，现在有n个已知数据量的任务需要交给CPU处理，假设已知CPU的每个核1秒可以处理1kb，每个核同时只能处理一项任务。n个任务可以按照任意顺序放入CPU进行处理，现在需要设计一个方案让CPU处理完这批任务所需的时间最少，求这个最小的时间。 
输入描述:
输入包括两行：
第一行为整数n(1 ≤ n ≤ 50)
第二行为n个整数length[i](1024 ≤ length[i] ≤ 4194304)，表示每个任务的长度为length[i]kb，每个数均为1024的倍数。


输出描述:
输出一个整数，表示最少需要处理的时间

输入例子1:
5
3072 3072 7168 3072 1024

输出例子1:
9216
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int process(vector<int> &s,int n){
	int cap=0;
	int c=0;
	for(int i=0;i<n;i++){
		c+=s[i];
	}
	cap=c/2+1;
	vector<int> t(cap+1,0);
	for(int i=0;i<n;i++){
		for(int j=cap;j>=s[i];j--){
			t[j]=t[j]<t[j-s[i]]+s[i]?t[j-s[i]]+s[i]:t[j];
		}
	}
	return max(t[cap],c-t[cap]);
}

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	vector<int> s;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t/1024);
	}
	
	int r=process(s,n);
	cout<<r*1024<<endl;

	
	return 0;
}
