/*
题目描述
牛牛想尝试一些新的料理，每个料理需要一些不同的材料，问完成所有的料理需要准备多少种不同的材料。
输入描述:
每个输入包含 1 个测试用例。每个测试用例的第 i 行，表示完成第 i 件料理需要哪些材料，各个材料用空格隔开，输入只包含大写英文字母和空格，输入文件不超过 50 行，每一行不超过 50 个字符。
输出描述:
输出一行一个数字表示完成所有料理需要多少种不同的材料。
示例1
输入

BUTTER FLOUR
HONEY FLOUR EGG
输出

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
