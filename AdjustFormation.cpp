/*
[�����] ��������
ʱ�����ƣ�1��
�ռ����ƣ�32768K
���׶�԰��n��С��������Ϊһ�����飬������һ������һ�����Ϊ(0~n-1)��������һЩ����������һЩ��Ů����������'B'��ʾ��Ů����'G'��ʾ��С�����Ƕ�����Ƥ����һ���������ŵ���Ů����ʱ��ͻᷢ��ì�ܡ���Ϊ�׶�԰����ʦ������Ҫ����������Ů������Ů������������������١���ֻ����ԭ�����Ͻ��е�����ÿ�ε���ֻ�������ڵ�����С���ѽ���λ�ã�������Ҫ������ɶ������������Ҫ�����������Ҫ�������ٴο���������������١����磺
GGBBG -> GGBGB -> GGGBB
������ʹ֮ǰ��������Ů���ڱ�Ϊһ�����ڣ���Ҫ��������2�� 
��������:
�������ݰ���һ������Ϊn��ֻ����G��B���ַ���.n������50.


�������:
���һ����������ʾ������Ҫ�ĵ�������Ĵ���

��������1:
GGBBG

�������1:
2
*/

#include <iostream>
#include <string>
using namespace std;

int process(string s,bool a){
	if(a){
		int c=0;
		string s1=s;
		for(int i=0;i<s1.length();i++){
			for(int j=0;j<s1.length()-1-i;j++){
				if(s1[j+1]<s1[j]){
					char t=s1[j];
					s1[j]=s1[j+1];
					s1[j+1]=t;
					c++;
				}
			}
		}
		return c;
	}else{
		int c=0;
		string s1=s;
		for(int i=0;i<s1.length();i++){
			for(int j=0;j<s1.length()-1-i;j++){
				if(s1[j+1]>s1[j]){
					char t=s1[j];
					s1[j]=s1[j+1];
					s1[j+1]=t;
					c++;
				}
			}
		}
		return c;
	}
}


int main(int argc, char *argv[])
{
	string s;
	cin>>s;
	cout<<min(process(s,false),process(s,true))<<endl;
	
	return 0;
}
