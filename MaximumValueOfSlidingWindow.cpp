#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> r;
		int maxv=0;
		if(num.size()<size||size==0){
			return r;
		}
		for(int i=0;i<=num.size()-size;i++){
			int tmp=0;
			for(int j=i;j<i+size;j++){
				tmp=num[j]>tmp?num[j]:tmp;
			}
            r.push_back(tmp);
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	vector<int> s;
	int a[]={1,4,5,2,2,17,8,9,1,4,3,2};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	Solution solution;
	vector<int> r=solution.maxInWindows(s,40);
	for(int i=0;i<r.size();i++){
		cout<<r[i]<<" ";
	}
	cout<<endl;

	return 0;
}
