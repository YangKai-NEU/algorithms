/*
���һ��01��������������λ�õ��ַ����ǲ�һ����,���Ǿͽ����01��Ϊ����01��������: "1","10101","0101010"���ǽ���01����
С��������һ��01��s,С�����ҳ�һ����������Ӵ�,��������Ӵ���һ������01����С����Ҫ����æ�������������Ӵ��ĳ����Ƕ��١� 
��������:
��������ַ���s,s�ĳ���length(1 �� length �� 50),�ַ�����ֻ����'0'��'1'


�������:
���һ������,��ʾ�������Ҫ����Ӵ����ȡ�

��������1:
111101111

�������1:
3
*/

#include <string>
#include <iostream>
using namespace std;

int maxLength(string s){
	int r=1;
	for(int i=0;i<s.length();i++){
		int tmp=1;
		for(int j=i+1;j<s.length();j++){
			if(s[j]==s[j-1]){
				break;
			}else{
				tmp++;
			}
		}
		r=r<tmp?tmp:r;
	}
	return r;
}

int main(int argc, char *argv[])
{
	string s;
	cin>>s;
	cout<<maxLength(s)<<endl;
	
	return 0;
}
