/*
题目描述
现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度
输入描述:
输入的第一行表示节点的个数n（1 ≤ n ≤ 1000，节点的编号为0到n-1）组成，
下面是n-1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号
输出描述:
输出树的高度，为一个整数
示例1
输入

5
0 1
0 2
1 3
1 4
输出

3
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	vector<int> s(n,-1);
    map<int,int> mmap2;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
        if(s[a]==-2){
            s[b]=-2;
            continue;
        }
        if(mmap2[a]<2){
            s[b]=a;
            mmap2[a]++;
        }else{
            s[b]=-2;
        }
	}
	int r=0;
	map<int,int> mmap;
	for(int i=n-2;i>=0;i--){
		if(mmap[i]||s[i]==-2){
			continue;
		}
		int c=1;
		int tmp=i;
		mmap[i]=1;
		while(s[tmp]!=-1){
			tmp=s[tmp];
			mmap[tmp]=1;
			c++;
		}
		if(c>r){
			r=c;
		}
	}
	cout<<r<<endl;
	
	return 0;
}
