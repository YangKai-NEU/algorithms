/*
小易有一个长度为n的整数序列,a_1,...,a_n。然后考虑在一个空序列b上进行n次以下操作:
1、将a_i放入b序列的末尾
2、逆置b序列
小易需要你计算输出操作n次之后的b序列。 
输入描述:
输入包括两行,第一行包括一个整数n(2 ≤ n ≤ 2*10^5),即序列的长度。
第二行包括n个整数a_i(1 ≤ a_i ≤ 10^9),即序列a中的每个整数,以空格分割。


输出描述:
在一行中输出操作n次之后的b序列,以空格分割,行末无空格。

输入例子1:
4
1 2 3 4

输出例子1:
4 2 1 3
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void operation(vector<int> &s,vector<int> &result){
	int n=s.size();
	if(n%2==0){
		for(int i=n-1;i>=0;i-=2){
			result.push_back(s[i]);
		}
		for(int i=0;i<n;i+=2){
			result.push_back(s[i]);
		}
	}else{
		for(int i=n-2;i>=0;i-=2){
			result.push_back(s[i]);
		}
		for(int i=0;i<n;i+=2){
			result.push_back(s[i]);
		}
		reverse(result.begin(),result.end());
	}
}

int main(int argc, char *argv[])
{
	int n;
	vector<int> s,result;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}
	operation(s,result);
	for(int i=0;i<result.size();i++){
		cout<<result[i];
		if(i!=result.size()-1){
			cout<<" ";
		}
	}
	cout<<endl;
	
	return 0;
}
