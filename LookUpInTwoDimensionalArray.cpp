#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
		int n=array.size();
        if(n==0){
            return false;
        }
		int m=array[0].size();
        if(m==0){
            return false;
        }
		for(int i=0;i<n;i++){
            
			if(array[i][0]>target||array[i][m-1]<target){
				continue;
			}
			int low=0;
			int high=m-1;
			while(low<=high){
				int mid=(low+high)/2;
				if(array[i][mid]==target){
					return true;
				}
				if(array[i][mid]>target){
					high=mid-1;
				}else{
					low=mid+1;
				}
			}
		}
		return false;
    }
};

int main(int argc, char *argv[])
{
	vector<vector<int>/**/> s;
	int a[]={
		1,2,4,
		3,5,7,
		6,8,10
	};
	int n=3,m=3;
	for(int i=0;i<n;i++){
		vector<int> tmp;
		for(int j=0;j<m;j++){
			tmp.push_back(a[i*m+j]);
		}
		s.push_back(tmp);
	}
	Solution solution;
	cout<<solution.Find(12,s)<<endl;
	return 0;
}
