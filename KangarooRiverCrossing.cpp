/*
题目描述
一只袋鼠要从河这边跳到河对岸，河很宽，但是河中间打了很多桩子，每隔一米就有一个，每个桩子上都有一个弹簧，袋鼠跳到弹簧上就可以跳的更远。每个弹簧力量不同，用一个数字代表它的力量，如果弹簧力量为5，就代表袋鼠下一跳最多能够跳5米，如果为0，就会陷进去无法继续跳跃。河流一共N米宽，袋鼠初始位置就在第一个弹簧上面，要跳到最后一个弹簧之后就算过河了，给定每个弹簧的力量，求袋鼠最少需要多少跳能够到达对岸。如果无法到达输出-1
输入描述:
输入分两行，第一行是数组长度N (1 ≤ N ≤ 10000)，第二行是每一项的值，用空格分隔。
输出描述:
输出最少的跳数，无法到达输出-1
示例1
输入

5
2 0 1 1 1
输出

4
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int f(vector<int> &s){
	int n=s.size();
	vector<int> r(n,0);
    for(int i=1;i<n;i++){
		int tmp=10000;
		for(int j=i-1;j>=0;j--){
			if(s[j]>=i-j&&r[j]!=10000&&r[j]+1<tmp){
				tmp=r[j]+1;
			}
		}
		r[i]=tmp;
	}
	if(r[n-1]==10000){
		return -1;
	}else{
		for(int j=n-2;j>=0;j--){
			if(s[j]>n-1-j&&r[j]!=10000&&r[j]+1==r[n-1]){
				return r[n-1];
			}
		}
		return r[n-1]+1;
	}
}

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	vector<int> s;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}
	cout<<f(s)<<endl;
	
	return 0;
}
