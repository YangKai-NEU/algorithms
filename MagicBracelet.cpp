/*
[�����] ħ���ֻ�
ʱ�����ƣ�1��
�ռ����ƣ�32768K
С��ӵ��һ��ӵ��ħ�����ֻ�������n������(����һ����),�����ħ���ֻ�ÿ��ʹ��ħ����ʱ��ͻᷢ��һ�����صı仯��ÿ�����ֻ����Լ�������һ�����ֵĺ�(���һ�����ֵĺ���һ�������ǵ�һ��),һ��ĳ��λ�õ����ִ��ڵ���100�����϶�100ȡģ(����ĳ��λ�ñ�Ϊ103,�ͻ��Զ���Ϊ3).���ڸ������ħ���ֻ��Ĺ��ɣ���������ʹ��k��ħ��֮��ħ���ֻ���״̬�� 
��������:
�������ݰ������У�
��һ��Ϊ��������n(2 �� n �� 50)��k(1 �� k �� 2000000000),�Կո�ָ�
�ڶ���Ϊħ���ֻ���ʼ��n�������Կո�ָ�����Χ����0��99.


�������:
���ħ���ֻ�ʹ��k��֮���״̬���Կո�ָ�����ĩ�޿ո�

��������1:
3 2
1 2 3

�������1:
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
