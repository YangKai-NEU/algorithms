/*
[�����] ����
ʱ�����ƣ�1��
�ռ����ƣ�32768K
С���������ѧ����ѧϰ���˼��ϵĸ���,����������������1.ȷ���� 2.������ 3.������.
С�׵���ʦ����С������һ�����ϣ�
S = { p/q | w �� p �� x, y �� q �� z }
��Ҫ���ݸ�����w��x��y��z,���������һ���ж��ٸ�Ԫ�ء�С�ײ�ѧϰ�˼��ϻ��������������ӵ�����,��Ҫ������������ 
��������:
�������һ�У�
һ��4�������ֱ���w(1 �� w �� x)��x(1 �� x �� 100)��y(1 �� y �� z)��z(1 �� z �� 100).�Կո�ָ�


�������:
���������Ԫ�صĸ���

��������1:
1 10 1 1

�������1:
10
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	int a,b,c,d;
	while(cin>>a>>b>>c>>d){
		vector<double> s;
		for(int i=a;i<=b;i++){
			for(int j=c;j<=d;j++){
				s.push_back(i*1.0/j);
			}
		}
		sort(s.begin(),s.end());
		for(int i=s.size()-1;i>0;i--){
			if(s[i]==s[i-1]){
				s.erase(s.begin()+i);
			}
		}
		cout<<s.size()<<endl;
	}
	
	return 0;
}
