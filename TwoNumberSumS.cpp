#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        map<int,int> mmap;
		vector<int> r;
		for(int i=0;i<array.size();i++){
			mmap[array[i]]=1;
		}
		for(int i=0;i<array.size();i++){
			if(mmap[sum-array[i]]){
				r.push_back(array[i]);
				r.push_back(sum-array[i]);
				break;
			}
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	vector<int> array;
	int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		array.push_back(a[i]);
	}

	vector<int> r=solution.FindNumbersWithSum(array,20);
	cout<<r[0]<<","<<r[1]<<endl;

	return 0;
}
