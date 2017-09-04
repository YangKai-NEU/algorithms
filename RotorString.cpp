/*
题目描述
假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。请将这个算法编写成一个函数，给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
给定两个字符串s1,s2,请返回bool值代表s2是否由s1旋转而成。字符串中字符为英文字母和空格，区分大小写，字符串长度小于等于1000。
测试样例：
"Hello world","worldhello "
返回：false
"waterbottle","erbottlewat"
返回：true
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
