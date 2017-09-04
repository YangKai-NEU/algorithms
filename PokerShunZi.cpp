#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        map<int,int> mmap;
		int maxv=-10000,minv=10000;
		if(numbers.size()==0){
			return false;
		}
		for(int i=0;i<numbers.size();i++){
			if(numbers[i]==0){
				continue;
			}
			if(mmap[numbers[i]]==1){
				return false;
			}
			mmap[numbers[i]]=1;
			maxv=maxv>numbers[i]?maxv:numbers[i];
			minv=minv<numbers[i]?minv:numbers[i];
		}
		if(maxv-minv>=5){
			return false;
		}
		return true;
    }
};

int main(int argc, char *argv[])
{
	vector<int> s;
	int a[]={2,3,6,0,9};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	Solution solution;
	cout<<solution.IsContinuous(s)<<endl;
	
	return 0;
}
