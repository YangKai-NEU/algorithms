/*
��Ŀ����
��һ����ɫ��ʯ���������ɺܶ��ֲ�ͬ�ı�ʯ��ɵģ������챦ʯ������ʯ����ʯ����䣬����ȡ���һ������������ʹ͸���һ��ѧ�ߣ�������˵������Դ����������������������ϲ���챦ʯ������ʯ����ˮ����������ʯ�����֣���Ҫ��������н�ȡ������һС�λ����ң���һ���б���������е������ֱ�ʯ��ʣ�µĲ�������Դ��ߡ�����޷��ҵ���һ��Ҳ�޷����ߡ������ѧ���ҳ�����з��������ܹ��õ����ı�ʯ��
��������:
������ÿ���ַ�����һ�ֱ�ʯ��A��ʾ�챦ʯ��B��ʾ����ʯ��C������ˮ����D������䣬E������ʯ��F������ʯ��G�������ȵȣ�������һ��ȫ��Ϊ��д��ĸ���ַ����б�ʾ�����ı�ʯ���У�ע����������β��ӵġ�ÿ�д���һ�������
�������:
���ѧ���ܹ��õ������ı�ʯ������ÿ��һ��
ʾ��1
����

ABCYDYE
ATTMBQECPD
���

1
3
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int f(string s){
	string a="ABCDE";
	int r=100000;
	int n=s.length();
	string p=s;
	for(int i=0;i<s.length();i++){
		p+=s[i];
	}
	for(int i=0;i<p.length();i++){
		map<char,int> mmap;
		int j;
		for(j=i;j<p.length();j++){
			int k;
			for(k=0;k<5;k++){
				if(!mmap[a[k]]){
					break;
				}
			}
			if(k==5){
				break;
			}
			mmap[p[j]]=1;
		}
		if(j==p.length()){
			break;
		}else{
			r=r<j-i?r:j-i;
		}
	}
	return r==100000?-1:n-r;
}

int main(int argc, char *argv[])
{
	string s;
	while(cin>>s){
		cout<<f(s)<<endl;
	}
	
	return 0;
}
