/*
血型遗传对照表如下：
父母血型	子女会出现的血型	子女不会出现的血型
O与O		O					A,B,AB
A与O		A,O					B,AB
A与A		A,O					B,AB
A与B		A,B,AB,O			——
A与AB		A,B,AB				O
B与O		B,O					A,AB
B与B		B,O					A,AB
B与AB		A,B,AB				O
AB与O		A,B					O,AB
AB与AB		A,B,AB				O
请实现一个程序，输入父母血型，判断孩子可能的血型。
给定两个字符串father和mother，代表父母的血型,请返回一个字符串数组，代表孩子的可能血型(按照字典序排列)。
测试样例：
”A”,”A”
返回：[”A”,“O”]
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
