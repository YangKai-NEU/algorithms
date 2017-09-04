#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> r;
		if(k>input.size()){
			return r;
		}
		sort(input.begin(),input.end());
		for(int i=0;i<k;i++){
			r.push_back(input[i]);
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	vector<int> s;
	int a[]={2,5,1,3,8,56,34};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	vector<int> r=solution.GetLeastNumbers_Solution(s,4);
	for(int i=0;i<r.size();i++){
		cout<<r[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
