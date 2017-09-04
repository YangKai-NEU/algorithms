#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> s) {
        int low=0;
		int high=s.size()-1;
		while(low<high){
			int mid=(low+high)/2;
			if(s[low]<=s[mid]&&s[mid]<=s[high]){
				return s[low];
			}else if(s[low]<=s[mid]&&s[low]>=s[high]){
				low=mid+1;
			}else if(s[low]>=s[high]&&s[mid]<=s[high]){
				high=mid;
			}
		}
		return s[low];
    }
};

int main(int argc, char *argv[])
{
	vector<int> s;
	int a[]={7,10,11,4,6};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	Solution solution;
	cout<<solution.minNumberInRotateArray(s)<<endl;
	
	return 0;
}
