#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        vector<int> s;
        if(n==0){
            return -1;
        }
		for(int i=0;i<n;i++){
			s.push_back(i);
		}
		int pos=0;
		while(s.size()!=1){
			pos+=(m-1);
			pos%=s.size();
			s.erase(s.begin()+pos);
		}
		return s[0];
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.LastRemaining_Solution(5,3)<<endl;
	
	return 0;
}
