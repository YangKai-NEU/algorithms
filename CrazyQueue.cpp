/*
小易老师是非常严厉的,它会要求所有学生在进入教室前都排成一列,并且他要求学生按照身高不递减的顺序排列。有一次,n个学生在列队的时候,小易老师正好去卫生间了。学生们终于有机会反击了,于是学生们决定来一次疯狂的队列,他们定义一个队列的疯狂值为每对相邻排列学生身高差的绝对值总和。由于按照身高顺序排列的队列的疯狂值是最小的,他们当然决定按照疯狂值最大的顺序来进行列队。现在给出n个学生的身高,请计算出这些学生列队的最大可能的疯狂值。小易老师回来一定会气得半死。 
输入描述:
输入包括两行,第一行一个整数n(1 ≤ n ≤ 50),表示学生的人数
第二行为n个整数h[i](1 ≤ h[i] ≤ 1000),表示每个学生的身高


输出描述:
输出一个整数,表示n个学生列队可以获得的最大的疯狂值。

如样例所示: 
当队列排列顺序是: 25-10-40-5-25, 身高差绝对值的总和为15+30+35+20=100。
这是最大的疯狂值了。

输入例子1:
5
5 10 25 40 25

输出例子1:
100
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int maxv(vector<int> &s,int left){
	int c=0;
	for(int i=1;i<s.size();i++){
		c+=abs(s[i]-s[i-1]);
	}
	if(left==-1){
		return c;
	}
	int tmp=c+(abs(s[0]-left)<abs(s[s.size()-1]-left)?abs(s[s.size()-1]-left):abs(s[0]-left));
	for(int i=1;i<s.size();i++){
		int t=c-abs(s[i]-s[i-1])+abs(s[i]-left)+abs(s[i-1]-left);
		tmp=tmp>t?tmp:t;
	}
	return tmp;
}

int process(vector<int> &s){
	vector<int> t;
	sort(s.begin(),s.end());
	while(s.size()>1){
		if(s.size()>=2){
			if(t.size()==0){
				t.push_back(s[0]);
				t.push_back(s[s.size()-1]);
			}else{
				if(t[0]>t[t.size()-1]){
					t.push_back(s[s.size()-1]);
					t.insert(t.begin(),s[0]);
				}else{
					t.push_back(s[0]);
					t.insert(t.begin(),s[s.size()-1]);
				}
			}
			s.erase(s.begin());
			s.pop_back();
		}else{
			break;
		}
	}
	if(s.size()==1){
		return maxv(t,s[0]);
	}else{
		return maxv(t,-1);
	}
}

int main(int argc, char *argv[])
{
	int n;
	vector<int> s;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}
	cout<<process(s)<<endl;
	
	return 0;
}
