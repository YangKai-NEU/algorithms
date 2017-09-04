/*
дһ�δ��룬�ж�һ������'{','[','(',')',']','}'�ı��ʽ�Ƿ�Ϸ�(ע�⿴�����ĺϷ�����)
����һ�����ʽA,�뷵��һ��boolֵ���������Ƿ�Ϸ���
����������
"[a+b*(5-4)]*{x+b+b*(({1+2)}}"
���أ�true
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
