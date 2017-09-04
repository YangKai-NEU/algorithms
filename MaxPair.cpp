#include <iostream>
#include <vector>
using namespace std;

int process(vector<int> &s){
	vector<int> dp(s.size());
	vector<int> maxv(s.size());
	dp[0]=0;
	maxv[0]=s[0];
	for(int i=1;i<s.size();i++){
		maxv[i]=max(maxv[i-1],s[i]);
		dp[i]=max(dp[i-1],maxv[i-1]-s[i]);
	}
	return dp[s.size()-1];
}

int main(int argc, char *argv[])
{
	int n;
	vector<int > s;
	cin>>n;
	for(int i =0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}
	cout<<process(s)<<endl;
	
	return 0;
}
