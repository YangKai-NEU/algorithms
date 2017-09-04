/*
题目描述
给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。
输入描述:
输入为两行内容，第一行是正整数number，1 ≤ length(number) ≤ 1000。第二行是希望去掉的数字数量cnt 1 ≤ cnt < length(number)。
输出描述:
输出保留下来的结果。
示例1
输入

325
1
输出

35
*/

#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string n;
	int m;
	while(cin>>n>>m){
		for(int i=0;i<m;i++){
			int j;
            int tl=n.length();
			for(j=0;j<tl-1;j++){
				if(n[j]<n[j+1]){
					n.erase(n.begin()+j);
					break;
				}
			}
			if(j==tl-1){
				n.erase(n.begin()+j);
			}
		}
		cout<<n<<endl;
	}
	
	return 0;
}
