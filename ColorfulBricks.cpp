/*
С����һЩ��ɫ��ש�顣ÿ����ɫ��һ����д��ĸ��ʾ��������ɫש�鿴��������ȫһ����������һ���������ַ���s,s��ÿ���ַ�����С�׵�ĳ��ש�����ɫ��С����������е�ש���ų�һ�С����������һ�Բ�ͬ��ɫ������ש��,��ô����ש��ͺ�Ư���ġ��������С�׼����ж����ַ�ʽ��������ש���ų�Ư����һ�С�(������ַ�ʽ����Ӧ��ש����ɫ��������ͬ��,��ô��Ϊ�����ַ�ʽ��һ���ġ�)
����: s = "ABAB",��ôС�����������еĽ��:
"AABB","ABAB","ABBA","BAAB","BABA","BBAA"
����ֻ��"AABB"��"BBAA"�������ֻ��һ�Բ�ͬ��ɫ������ש�顣 
��������:
�������һ���ַ���s,�ַ���s�ĳ���length(1 �� length �� 50),s�е�ÿһ���ַ���Ϊһ����д��ĸ(A��Z)��


�������:
���һ������,��ʾС�׿����ж����ַ�ʽ��

��������1:
ABAB

�������1:
2
*/

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	string a;
	set<char> s;
	while(cin>>a){
		for(int i=0;i<a.length();i++){
			s.insert(a[i]);
		}
		if(s.size()==1){
			cout<<1<<endl;
		}else if(s.size()==2){
			cout<<2<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	
	return 0;
}