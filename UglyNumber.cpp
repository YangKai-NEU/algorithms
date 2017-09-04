#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	vector<int> s;
		s.push_back(0);
		s.push_back(1);
		int pos2=1;
		int pos3=1;
		int pos5=1;
		for(int i=2;i<=index;i++){
			s.push_back(min(min(s[pos2]*2,s[pos3]*3),s[pos5]*5));
			if(s[i]==s[pos2]*2){
				pos2++;
			}
			if(s[i]==s[pos3]*3){
				pos3++;
			}
			if(s[i]==s[pos5]*5){
				pos5++;
			}
		}
		return s[index];
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.GetUglyNumber_Solution(5)<<endl;
	
	return 0;
}
