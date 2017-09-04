#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> a,vector<int> b) {
        if(a.size()!=b.size()){
			return false;
		}
		int pos1=0;
		int pos2=0;
		stack<int> mstack;
		for(pos2=0;pos2<b.size();pos2++){
			if(mstack.empty()||mstack.top()!=b[pos2]){
				for(;pos1<a.size()&&a[pos1]!=b[pos2];pos1++){
					mstack.push(a[pos1]);
				}
				if(pos1==a.size()){
					return false;
				}
				pos1++;
			}else{
				mstack.pop();
			}
		}
		return pos1==a.size()&&pos2==b.size();
    }
};

int main(int argc, char *argv[])
{
	vector<int> a,b;
	int s1[]={1,2,3,4,5};
	int s2[]={4,5,3,2,1};
	int n=5;
	for(int i=0;i<n;i++){
		a.push_back(s1[i]);
		b.push_back(s2[i]);
	}
	Solution solution;
	cout<<solution.IsPopOrder(a,b)<<endl;
	
	return 0;
}
