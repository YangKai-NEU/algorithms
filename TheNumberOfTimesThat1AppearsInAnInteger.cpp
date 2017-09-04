#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
		int t=1;
		while(n/t>=10){
			t*=10;	
		}
		int h=n/t;
		int l=n-h*t;
		if(t==1){
			return h>=1;
		}
		if(h==1){
			return NumberOf1Between1AndN_Solution(t-1)+NumberOf1Between1AndN_Solution(l)+l+1;
		}else{
			return NumberOf1Between1AndN_Solution(t-1)*h+t+NumberOf1Between1AndN_Solution(l);
		}
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.NumberOf1Between1AndN_Solution(13)<<endl;
	
	return 0;
}
