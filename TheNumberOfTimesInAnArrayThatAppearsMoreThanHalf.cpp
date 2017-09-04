#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
		map<int,int> mmap;
		for(int i=0;i<numbers.size();i++){
			mmap[numbers[i]]++;
			if(mmap[numbers[i]]>numbers.size()/2){
				return 
			}
		}
		return 0;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	int a[]={2,3,4,5,4,4,23,4,4};
	vector<int> s;
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	cout<<solution.MoreThanHalfNum_Solution(s)<<endl;
	
	return 0;
}
