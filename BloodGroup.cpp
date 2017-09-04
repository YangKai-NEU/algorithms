/*
Ѫ���Ŵ����ձ����£�
��ĸѪ��	��Ů����ֵ�Ѫ��	��Ů������ֵ�Ѫ��
O��O		O					A,B,AB
A��O		A,O					B,AB
A��A		A,O					B,AB
A��B		A,B,AB,O			����
A��AB		A,B,AB				O
B��O		B,O					A,AB
B��B		B,O					A,AB
B��AB		A,B,AB				O
AB��O		A,B					O,AB
AB��AB		A,B,AB				O
��ʵ��һ���������븸ĸѪ�ͣ��жϺ��ӿ��ܵ�Ѫ�͡�
���������ַ���father��mother������ĸ��Ѫ��,�뷵��һ���ַ������飬�����ӵĿ���Ѫ��(�����ֵ�������)��
����������
��A��,��A��
���أ�[��A��,��O��]
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class ChkBloodType {
public:
    vector<string> chkBlood(string father, string mother) {
        // write code here
		map<pair<string,string>,vector<string> > mmap;
		mmap[make_pair("O","O")].push_back("O");

		mmap[make_pair("A","O")].push_back("O");
		mmap[make_pair("A","O")].push_back("A");

		mmap[make_pair("B","O")].push_back("O");
		mmap[make_pair("B","O")].push_back("B");

		mmap[make_pair("A","A")].push_back("O");
		mmap[make_pair("A","A")].push_back("A");

		mmap[make_pair("A","B")].push_back("A");
		mmap[make_pair("A","B")].push_back("B");
		mmap[make_pair("A","B")].push_back("AB");
		mmap[make_pair("A","B")].push_back("O");

		mmap[make_pair("A","AB")].push_back("A");
		mmap[make_pair("A","AB")].push_back("B");
		mmap[make_pair("A","AB")].push_back("AB");

		mmap[make_pair("B","B")].push_back("B");
		mmap[make_pair("B","B")].push_back("O");

		mmap[make_pair("B","AB")].push_back("A");
		mmap[make_pair("B","AB")].push_back("B");
		mmap[make_pair("B","AB")].push_back("AB");
		
		mmap[make_pair("O","AB")].push_back("A");
		mmap[make_pair("O","AB")].push_back("B");

		mmap[make_pair("AB","AB")].push_back("A");
		mmap[make_pair("AB","AB")].push_back("B");
		mmap[make_pair("AB","AB")].push_back("AB");
	
		vector<string> r;
		vector<string> s1=mmap[make_pair(father,mother)];
		vector<string> s2=mmap[make_pair(mother,father)];
        if(s1.size()!=0){
            for(int i=0;i<s1.size();i++){
                r.push_back(s1[i]);
            }
        }else{
            for(int i=0;i<s2.size();i++){
                r.push_back(s2[i]);
            }
        }
		sort(r.begin(),r.end());
		return r;
    }	
};

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
