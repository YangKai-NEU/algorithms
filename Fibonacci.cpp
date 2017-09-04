#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
		vector<int> s(40,0);
		s[1]=s[2]=1;
		for(int i=3;i<40;i++){
			s[i]=s[i-1]+s[i-2];
		}
		return s[n];
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.Fibonacci(20)<<endl;
	
	return 0;
}
