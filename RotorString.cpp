/*
��Ŀ����
�ٶ����Ƕ�֪���ǳ���Ч���㷨�����һ�������Ƿ�Ϊ�����ַ������Ӵ����뽫����㷨��д��һ�����������������ַ���s1��s2�����д������s2�Ƿ�Ϊs1��ת���ɣ�Ҫ��ֻ�ܵ���һ�μ���Ӵ��ĺ�����
���������ַ���s1,s2,�뷵��boolֵ����s2�Ƿ���s1��ת���ɡ��ַ������ַ�ΪӢ����ĸ�Ϳո����ִ�Сд���ַ�������С�ڵ���1000��
����������
"Hello world","worldhello "
���أ�false
"waterbottle","erbottlewat"
���أ�true
*/

#include <string>
#include <iostream>
using namespace std;

class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        // write code here
		int n=s2.length();
		for(int i=0;i<n;i++){
			s2+=s2[0];
			s2.erase(s2.begin());
			if(s1==s2){
				return true;
			}
		}
		return false;
    }
};

int main(int argc, char *argv[])
{
	ReverseEqual r;
	string a="abcdef";
	string b="efabcd";
	cout<<r.checkReverseEqual(a,b)<<endl;
	
	return 0;
}
