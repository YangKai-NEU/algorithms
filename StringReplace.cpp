/*
请你实现一个简单的字符串替换函数。原串中需要替换的占位符为"%s",请按照参数列表的顺序一一替换占位符。若参数列表的字符数大于占位符个数。则将剩下的参数字符添加到字符串的结尾。
给定一个字符串A，同时给定它的长度n及参数字符数组arg，请返回替换后的字符串。保证参数个数大于等于占位符个数。保证原串由大小写英文字母组成，同时长度小于等于500。
测试样例：
"A%sC%sE",7,['B','D','F']
返回："ABCDEF"
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
