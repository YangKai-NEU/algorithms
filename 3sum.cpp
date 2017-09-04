#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &s) {
        vector<vector<int> > r;
		sort(s.begin(),s.end());
		int n=s.size();
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					if(s[i]+s[j]+s[k]==0){
						vector<int> t;
						t.push_back(s[i]);
						t.push_back(s[j]);
						t.push_back(s[k]);
						r.push_back(t);
					}
				}
			}
		}
        sort(r.begin(),r.end());
    	for(int i=r.size()-1;i>0;i--){
            if(r[i]==r[i-1]){
                r.erase(r.begin()+i);
            }
        }
		return r;
    }
};

int main(int argc, char *argv[])
{
	vector<int> a;
	int b[]={-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	for(int i=0;i<sizeof(b)/sizeof(int);i++){
		a.push_back(b[i]);
	}
	Solution s;
	vector<vector<int> > r=s.threeSum(a);
	for(int i=0;i<r.size();i++){
		for(int j=0;j<r[i].size();j++){
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
