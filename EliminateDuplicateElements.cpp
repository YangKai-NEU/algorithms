/*
[编程题] 消除重复元素
时间限制：1秒
空间限制：32768K
小易有一个长度为n序列，小易想移除掉里面的重复元素，但是小易想是对于每种元素保留最后出现的那个。小易遇到了困难,希望你来帮助他。 
输入描述:
输入包括两行：
第一行为序列长度n(1 ≤ n ≤ 50)
第二行为n个数sequence[i](1 ≤ sequence[i] ≤ 1000)，以空格分隔


输出描述:
输出消除重复元素之后的序列，以空格分隔，行末无空格

输入例子1:
9
100 100 100 99 99 99 100 100 100

输出例子1:
99 100
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void process(vector<int> &s){
	map<int,int> mmap;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(!mmap[s[i]]){
			mmap[s[i]]=1;
		}else{
			s.erase(s.begin()+i);
			i--;
		}
	}
	reverse(s.begin(),s.end());
}


int main(int argc, char *argv[])
{
	vector<int> s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}
	process(s);
	for(int i=0;i<s.size();i++){
		cout<<s[i];
        if(i!=s.size()-1){
            cout<<" ";
        }
	}
	cout<<endl;
	
	return 0;
}
