#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > r;

    vector<vector<int> > combine(int n, int k) {
		vector<int> s;
		process(s,1,n,k);
		return r;
    }

	void process(vector<int> &s,int pos,int n,int k){
		if(s.size()==k){
			r.push_back(s);
			return;
		}else{
			for(int i=pos;i<=n;i++){
				s.push_back(i);
				process(s,i+1,n,k);
				s.pop_back();
			}
		}
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<vector<int> > r=s.combine(4,2);
	for(int i=0;i<r.size();i++){
		for(int j=0;j<r[i].size();j++){
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
