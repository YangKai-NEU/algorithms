/*
���һ������S����������еĺϷ���i,����S[i + 1] = S[i] + d, �����dҲ�����Ǹ�������,���Ǿͳ�����SΪ�Ȳ����С�
С��������һ������Ϊn������x,С�����x��Ϊһ���Ȳ����С�С����������������������������λ�õ���ֵ�Ĳ���,���ҽ���������������Ρ�������Щ����ͨ���������ǲ��ܱ�ɵȲ�����,С����Ҫ�б�һ�������Ƿ���ͨ������������ɵȲ����� 
��������:
�����������,��һ�а�������n(2 �� n �� 50),�����еĳ��ȡ�
�ڶ���n��Ԫ��x[i](0 �� x[i] �� 1000),�������е�ÿ��������


�������:
������Ա�ɵȲ��������"Possible",�������"Impossible"��

��������1:
3
3 1 2

�������1:
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
