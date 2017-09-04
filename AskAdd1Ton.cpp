#include <iostream>
using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
		int result=n;
		int a=n<=1||(result+=Sum_Solution(n-1));
        return result;
    }

};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.Sum_Solution(4)<<endl;
	
	return 0;
}
