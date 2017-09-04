/*
写一段代码，判断一个包括'{','[','(',')',']','}'的表达式是否合法(注意看样例的合法规则。)
给定一个表达式A,请返回一个bool值，代表它是否合法。
测试样例：
"[a+b*(5-4)]*{x+b+b*(({1+2)}}"
返回：true
*/

#include <string>
#include <iostream>
#include <stack>
using namespace std;

class ChkExpression {
public:
    bool chkLegal(string A) {
        // write code here
		stack<char> mstack;
		for(int i=0;i<A.length();i++){
			if(A[i]=='('||A[i]=='['||A[i]=='{'){
				mstack.push(A[i]);
			}else if(A[i]==')'||A[i]=='}'||A[i]==']'){
				if(mstack.empty()){
					return false;
				}else{
                    mstack.pop();
                }
			}
		}

		return mstack.empty();
    }
};


int main(int argc, char *argv[])
{
	ChkExpression c;
	string s="[a+b*(5-4)]*{x+b+b*(({1+2)}}";
	cout<<c.chkLegal(s)<<endl;
	
	return 0;
}
