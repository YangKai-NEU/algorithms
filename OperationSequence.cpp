/*
С����һ������Ϊn����������,a_1,...,a_n��Ȼ������һ��������b�Ͻ���n�����²���:
1����a_i����b���е�ĩβ
2������b����
С����Ҫ������������n��֮���b���С� 
��������:
�����������,��һ�а���һ������n(2 �� n �� 2*10^5),�����еĳ��ȡ�
�ڶ��а���n������a_i(1 �� a_i �� 10^9),������a�е�ÿ������,�Կո�ָ


�������:
��һ�����������n��֮���b����,�Կո�ָ�,��ĩ�޿ո�

��������1:
4
1 2 3 4

�������1:
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
