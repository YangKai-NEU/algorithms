#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
		int n=data.size();
		if(n==0){
			return 0;
		}
        return count(data,0,n-1,k);
    }
	int count(vector<int> &s,int low,int high,int k){
		if(s[low]==k&&s[high]==k){
			return high-low+1;
		}
		if(low==high){
			return 0;
		}
		if(s[low]>k||s[high]<k){
			return 0;
		}
		int mid=(low+high)/2;
		if(s[mid]>k){
			return count(s,low,mid-1,k);
		}else if(s[mid]<k){
			return count(s,mid+1,high,k);
		}else {
			return 1+count(s,low,mid-1,k)+count(s,mid+1,high,k);
		}
	}
};

int main(int argc, char *argv[])
{
	Solution solution;
	vector<int> s;
	int a[]={1,2,2,2,3,4,5,5,6};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	cout<<solution.GetNumberOfK(s,2)<<endl;
	
	return 0;
}
