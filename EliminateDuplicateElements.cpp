/*
[�����] �����ظ�Ԫ��
ʱ�����ƣ�1��
�ռ����ƣ�32768K
С����һ������Ϊn���У�С�����Ƴ���������ظ�Ԫ�أ�����С�����Ƕ���ÿ��Ԫ�ر��������ֵ��Ǹ���С������������,ϣ�������������� 
��������:
����������У�
��һ��Ϊ���г���n(1 �� n �� 50)
�ڶ���Ϊn����sequence[i](1 �� sequence[i] �� 1000)���Կո�ָ�


�������:
��������ظ�Ԫ��֮������У��Կո�ָ�����ĩ�޿ո�

��������1:
9
100 100 100 99 99 99 100 100 100

�������1:
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
