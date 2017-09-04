/*
[�����] ��ȥ��˾
ʱ�����ƣ�1��
�ռ����ƣ�32768K
���ڵ���ĩ����С�����������Ľֵ���׼�������ѾۻᣬͻȻ��������������,С����Ҫ�����ع�˾�޸��������bug������������һ�����޴������ÿ���ֵ�����������(X��Y)��С�׵�ǰ��(0��0)�ֵ����칫����(gx,gy)�ֵ��ϡ�С����Χ�ж�����⳵�򳵵㣬С�׸�ȥ�칫��������ѡ��һ�־�����·ȥ��˾������һ�־����ߵ�һ�����⳵�򳵵㣬Ȼ��Ӵ򳵵��λ�������⳵ȥ��˾��ÿ���ƶ������ڵĽֵ�(�����������)��·���Ứ��walkTimeʱ�䣬�򳵽�����taxiTimeʱ�䡣С����Ҫ����ϵ���˾ȥ������С����֪���������Ҫ���Ѷ���ʱ��ȥ��˾�� 
��������:
�������ݰ�������:

��һ��Ϊ��Χ���⳵�򳵵�ĸ���n(1 �� n �� 50)

�ڶ���Ϊÿ�����⳵�򳵵�ĺ�����tX[i] (-10000 �� tX[i] �� 10000)

������Ϊÿ�����⳵�򳵵��������tY[i] (-10000 �� tY[i] �� 10000)

������Ϊ�칫������gx,gy(-10000 �� gx,gy �� 10000),�Կո�ָ�

������Ϊ��·ʱ��walkTime(1 �� walkTime �� 1000)��taxiTime(1 �� taxiTime �� 1000),�Կո�ָ�


�������:
���һ��������ʾ��С������ܸϵ��칫�ҵ�ʱ��

��������1:
2
-2 -2
0 -2
-4 -2
15 3

�������1:
42
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int process(vector<int> &x,vector<int> &y,int ax,int ay,int wt,int tt){
	int result=1000000;
	int w=abs(ax)*wt+abs(ay)*wt;
	result=result<w?result:w;
	for(int i=0;i<x.size();i++){
		int tmp=abs(x[i])*wt+abs(y[i])*wt+abs(x[i]-ax)*tt+abs(y[i]-ay)*tt;
		result=result<tmp?result:tmp;
	}
	return result;
}

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	vector<int> x,y;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		x.push_back(t);
	}
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		y.push_back(t);
	}
	int ax,ay;
	cin>>ax>>ay;
	int wt,tt;
	cin>>wt>>tt;

	cout<<process(x,y,ax,ay,wt,tt)<<endl;
	
	return 0;
}
