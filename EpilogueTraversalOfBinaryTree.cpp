#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> s) {
		if(s.size()==0){
			return false;
		}
		return check(s);
    }

	bool check(vector<int> s){
		if(s.size()==0){
			return true;
		}
		int mid=s[s.size()-1];
		vector<int> a,b;
		int i;
		for(i=0;i<s.size()-1;i++){
			if(s[i]>mid){
				break;
			}else{
				a.push_back(s[i]);
			}
		}
		for(;i<s.size()-1;i++){
			if(s[i]<mid){
				break;
			}else{
				b.push_back(s[i]);
			}
		}
		if(i!=s.size()-1){
			return false;
		}
		return check(a)&&check(b);
	}
};

int main(int argc, char *argv[])
{
	vector<int> s;
	int a[]={23,12,35,56,78,89,45,25,232,456};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	Solution solution;
	cout<<solution.VerifySquenceOfBST(s)<<endl;
	
	return 0;
}
