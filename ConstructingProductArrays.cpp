#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int> s;
		for(int i=0;i<A.size();i++){
			int tmp=1;
			for(int j=0;j<A.size();j++){
				if(i!=j){
					tmp*=A[j];
				}
			}
			s.push_back(tmp);
		}
		return s;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	vector<int> s;
	int a[]={1,2,3,4,5};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	vector<int> r=solution.multiply(s);
	for(int i=0;i<r.size();i++){
		cout<<r[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
