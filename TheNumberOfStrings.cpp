/*
��Ŀ����
����n�������������������ӳ�һ�ţ����һ�����Ķ�λ������
��:n=3ʱ��3������13,312,343,���ɵ��������Ϊ34331213��
��:n=4ʱ,4������7,13,4,246���ӳɵ��������Ϊ7424613��
��������:
�ж������������ÿ����������������У���һ��Ϊһ������N��N<=100�����ڶ��а���N����(ÿ����������1000���ո�ֿ�)��
�������:
ÿ���������һ����ʾ����������
ʾ��1
����

2
12 123
4
7 13 4 246
���

12312
7424613
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;

string f(vector<int> &s){
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			char a1[100];
			char a2[100];
			sprintf(a1,"%d%d",s[i],s[j]);
			sprintf(a2,"%d%d",s[j],s[i]);
			if(strcmp(a2,a1)>0){
				int t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
	}
	char a[10000]={'\0'};
	for(int i=0;i<s.size();i++){
		sprintf(a,"%s%d",a,s[i]);
	}
	string b=a;
	return b;
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		vector<int> s;
		for(int i=0;i<n;i++){
			int t;
			cin>>t;
			s.push_back(t);
		}
		cout<<f(s)<<endl;
	}
	
	return 0;
}
