#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> s) {
		int m=-10000;
		int result=-10000;
		int tmp=0;
		int state=false;
		for(int i=0;i<s.size();i++){
			tmp+=s[i];
			if(tmp<0){
				tmp=0;
			}else{
				result=result<tmp?tmp:result;
			}
			m=m<s[i]?s[i]:m;
			if(s[i]>=0){
				state=true;
			}
		}
		return state?result:m;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	vector<int> s;
	int a[]={23,-12,3,10,-23,-1,40,23,-100};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	cout<<solution.FindGreatestSumOfSubArray(s)<<endl;
		
	return 0;
}
