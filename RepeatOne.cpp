#include <iostream>
#include <vector>
using namespace std;

int f(vector<int> &s ){
	for(int i=1;i<s.size();i++){
		if(s[i]>0){
			s[s[i]]=-s[s[i]];
		}else{
			s[-s[i]]=-s[-s[i]];
		}
	}
	for(int i=1;i<s.size();i++){
		if(s[i]>0){
			return i;
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int n;
	vector<int> s;
	cin>>n;
	s.push_back(-1);
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}
	cout<<f(s)<<endl;
	
	return 0;
}
