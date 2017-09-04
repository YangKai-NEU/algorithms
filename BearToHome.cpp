#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int sumOfRoute(vector<int> &s){
	int r=0;
	for(int i=1;i<s.size();i++){
		r+=abs(s[i]-s[i-1]);
	}
	return r;
}

int minRoute(vector<int> &s){
	int r=100000;
	int total=sumOfRoute(s);
	for(int i=1;i<s.size()-1;i++){
		int t=total;
		t-=abs(s[i]-s[i-1]);
		t-=abs(s[i]-s[i+1]);
		t+=abs(s[i+1]-s[i-1]);
		r=r<t?r:t;
	}
	return r;
}

int main(int argc, char *argv[])
{
	int n;
	vector<int> s;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}

	cout<<minRoute(s)<<endl;
	return 0;
}
