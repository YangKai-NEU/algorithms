/*
С����ʦ�Ƿǳ�������,����Ҫ������ѧ���ڽ������ǰ���ų�һ��,������Ҫ��ѧ��������߲��ݼ���˳�����С���һ��,n��ѧ�����жӵ�ʱ��,С����ʦ����ȥ�������ˡ�ѧ���������л��ᷴ����,����ѧ���Ǿ�����һ�η��Ķ���,���Ƕ���һ�����еķ��ֵΪÿ����������ѧ����߲�ľ���ֵ�ܺ͡����ڰ������˳�����еĶ��еķ��ֵ����С��,���ǵ�Ȼ�������շ��ֵ����˳���������жӡ����ڸ���n��ѧ�������,��������Щѧ���жӵ������ܵķ��ֵ��С����ʦ����һ�������ð����� 
��������:
�����������,��һ��һ������n(1 �� n �� 50),��ʾѧ��������
�ڶ���Ϊn������h[i](1 �� h[i] �� 1000),��ʾÿ��ѧ�������


�������:
���һ������,��ʾn��ѧ���жӿ��Ի�õ����ķ��ֵ��

��������ʾ: 
����������˳����: 25-10-40-5-25, ��߲����ֵ���ܺ�Ϊ15+30+35+20=100��
�������ķ��ֵ�ˡ�

��������1:
5
5 10 25 40 25

�������1:
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
