#include <iostream>
#include <vector>
using namespace std;

int MaximumSubarray(vector<int> &s){
	int result=0;
	int tmp=0;
	for(int i=0;i<s.size();i++){
		tmp+=s[i];
		if(tmp<0){
			tmp=0;
		}else if(tmp>result){
			result=tmp;
		}
	}
	return result;
}

int main(){
	
	vector<int> s;
	int a[]={1, -2, 3, 10, -4, 7, 2, -5};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	cout<<MaximumSubarray(s)<<endl;
	return 0;
}