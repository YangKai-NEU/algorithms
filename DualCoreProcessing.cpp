/*
[�����] ˫�˴���
ʱ�����ƣ�1��
�ռ����ƣ�32768K
һ��˫��CPU���������ܹ�ͬʱ�Ĵ�������������n����֪��������������Ҫ����CPU����������֪CPU��ÿ����1����Դ���1kb��ÿ����ͬʱֻ�ܴ���һ������n��������԰�������˳�����CPU���д���������Ҫ���һ��������CPU�������������������ʱ�����٣��������С��ʱ�䡣 
��������:
����������У�
��һ��Ϊ����n(1 �� n �� 50)
�ڶ���Ϊn������length[i](1024 �� length[i] �� 4194304)����ʾÿ������ĳ���Ϊlength[i]kb��ÿ������Ϊ1024�ı�����


�������:
���һ����������ʾ������Ҫ�����ʱ��

��������1:
5
3072 3072 7168 3072 1024

�������1:
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
