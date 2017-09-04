/*
С�׽�n�����Ӱڷ���һ�����޴�������ϡ���i�����ӷ��ڵ�x[i]��y[i]�С�ͬһ������������ö�����ӡ�ÿһ�β���С�׿��԰�һ���������𲢽����ƶ���ԭ���ӵ��ϡ��¡����ҵ�����һ�������С�С����֪��Ҫ�������ϳ�����һ��������������i(1 �� i �� n)����������Ҫ�����ٲ�������.

��������:
�����������,��һ��һ������n(1 �� n �� 50),��ʾ���ӵĸ���
�ڶ���Ϊn�����ӵĺ�����x[i](1 �� x[i] �� 10^9)
������Ϊn�����ӵ�������y[i](1 �� y[i] �� 10^9)


�������:
���n������,��i����ʾ��������һ������������i����������Ҫ�Ĳ�����,�Կո�ָ��ĩ�޿ո�

��������ʾ:
����1������: ����Ҫ����
����2������: ��ǰ�������ӷ���(1, 1)��
����3������: ��ǰ�������ӷ���(2, 1)��
����4������: ���������Ӷ�����(3, 1)��

��������1:
4
1 2 4 9
1 1 1 1

�������1:
0 1 3 10
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void process(vector<int> &x,vector<int> &y,vector<int> &result){
	int n=x.size();
	for(int i=0;i<n;i++){
		for(int k=0;k<n;k++){
			vector<int> t(n);
			for(int j=0;j<n;j++){
				//���ŵ�xһ��������n�����x�У�yһ��������n�����y��
				t[j]=abs(x[i]-x[j])+abs(y[k]-y[j]);
			}
			sort(t.begin(),t.end());
			int c=0;
			for(int j=0;j<n;j++){
				c+=t[j];
				result[j]=result[j]<c?result[j]:c;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int n;
	vector<int> x,y;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		x.push_back(a);
	}
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		y.push_back(a);
	}
	
	vector<int> r(n,1e10);
	process(x,y,r);
	for(int i=0;i<r.size();i++){
		cout<<r[i];
		if(i!=r.size()-1){
			cout<<" ";
		}
	}
	cout<<endl;

	return 0;
}