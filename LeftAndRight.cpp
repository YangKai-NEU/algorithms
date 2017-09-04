#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> re;
        if(n==0||A[0]>target||A[n-1]<target){
            re.push_back(-1);
            re.push_back(-1);
        }else{
            re.push_back(l(A,0,n-1,target));
            re.push_back(r(A,0,n-1,target));
        }
        return re;
    }
    
    int l(int A[], int ll,int hh, int target){
        int low=ll;
        int high=hh;
        
        if(target<A[low]||target>A[high]){
            return -1;
        }
        
        int mid =(low+high)/2;
        if(A[low]==target){
            return low;
        }
        if(low==high){
            return -1;
        }
		if(low+1==high&&A[high]==target){
			return high;
		}
        if(A[mid]==target){
            return l(A,low,mid,target);
        }else if(A[mid]>target){
            return l(A,low,mid-1,target);
        }else{
            return l(A,mid+1,high,target);
        }
    }
    
    int r(int A[], int ll,int hh, int target){
        int low=ll;
        int high=hh;
        
        if(target<A[low]||target>A[high]){
            return -1;
        }
        
        int mid =(low+high)/2;
        if(A[high]==target){
            return high;
        }
        if(low==high){
            return -1;
        }
		if(low+1==high&&A[low]==target){
			return low;
		}
        if(A[mid]==target){
            return r(A,mid,high,target);
        }else if(A[mid]>target){
            return r(A,low,mid-1,target);
        }else{
            return r(A,mid+1,high,target);
        }
    }
};

int main(){
	Solution s;
	int a[]={5,7,7,8,8,10,11,12,13,14,16,18,20,21,24,25,26,27};

	vector<int> t=s.searchRange(a,sizeof(a)/sizeof(int),16);
	cout<<t[0]<<","<<t[1]<<endl;


	return 0;
}