/*
��Ŀ����
ţţ�볢��һЩ�µ�����ÿ��������ҪһЩ��ͬ�Ĳ��ϣ���������е�������Ҫ׼�������ֲ�ͬ�Ĳ��ϡ�
��������:
ÿ��������� 1 ������������ÿ�����������ĵ� i �У���ʾ��ɵ� i ��������Ҫ��Щ���ϣ����������ÿո����������ֻ������дӢ����ĸ�Ϳո������ļ������� 50 �У�ÿһ�в����� 50 ���ַ���
�������:
���һ��һ�����ֱ�ʾ�������������Ҫ�����ֲ�ͬ�Ĳ��ϡ�
ʾ��1
����

BUTTER FLOUR
HONEY FLOUR EGG
���

4
*/

#include <map>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string s;
	map<string,int> mmap;
	while(cin>>s){
		mmap[s]=1;
	}
	cout<<mmap.size()<<endl;
	return 0;
}
