#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> s(number+1,0);
		s[1]=1;
		for(int i=2;i<=number;i++){
			for(int j=1;j<i;j++){
				s[i]+=s[j];
			}
			s[i]++;
		}
		return s[number];
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.jumpFloor(12)<<endl;
	
	return 0;
}
