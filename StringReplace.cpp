/*
����ʵ��һ���򵥵��ַ����滻������ԭ������Ҫ�滻��ռλ��Ϊ"%s",�밴�ղ����б��˳��һһ�滻ռλ�����������б���ַ�������ռλ����������ʣ�µĲ����ַ���ӵ��ַ����Ľ�β��
����һ���ַ���A��ͬʱ�������ĳ���n�������ַ�����arg���뷵���滻����ַ�������֤�����������ڵ���ռλ����������֤ԭ���ɴ�СдӢ����ĸ��ɣ�ͬʱ����С�ڵ���500��
����������
"A%sC%sE",7,['B','D','F']
���أ�"ABCDEF"
*/

#include <string>
#include <iostream>
using namespace std;

class StringFormat {
public:
    string formatString(string A, int n, vector<char> arg, int m) {
        // write code here
		int pos=0;
		int pre=0;
		string s="";
		int i;
		for(i=0;i<n-1;i++){
			if(A[i]=='%'&&A[i+1]=='s'){
				s+=arg[pos++];
				i++;
			}else{
				s+=A[i];
			}
		}
		if(i==n-1){
			s+=A[i];
		}
		while(pos<arg.size()){
			s+=arg[pos++];
		}
		return s;
    }
};

int main(int argc, char *argv[])
{
	StringFormat s;
	
	return 0;
}
