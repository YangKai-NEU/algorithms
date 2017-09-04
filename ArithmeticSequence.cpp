/*
如果一个数列S满足对于所有的合法的i,都有S[i + 1] = S[i] + d, 这里的d也可以是负数和零,我们就称数列S为等差数列。
小易现在有一个长度为n的数列x,小易想把x变为一个等差数列。小易允许在数列上做交换任意两个位置的数值的操作,并且交换操作允许交换多次。但是有些数列通过交换还是不能变成等差数列,小易需要判别一个数列是否能通过交换操作变成等差数列 
输入描述:
输入包括两行,第一行包含整数n(2 ≤ n ≤ 50),即数列的长度。
第二行n个元素x[i](0 ≤ x[i] ≤ 1000),即数列中的每个整数。


输出描述:
如果可以变成等差数列输出"Possible",否则输出"Impossible"。

输入例子1:
3
3 1 2

输出例子1:
Possible
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	vector<int> s;
	int i;
	for(i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}
	sort(s.begin(),s.end());
	int pre=-1;
	for(i=1;i<n;i++){
		if(pre==-1){
			pre=s[i]-s[i-1];
		}else{
			if(s[i]-s[i-1]==pre){
				continue;
			}else{
				break;
			}
		}
	}
	if(i==n){
		cout<<"Possible"<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
	
	return 0;
}
