#include <iostream>
#include <vector>
using namespace std;

int minValue(vector<vector<int> > &s,int n,int m){
	vector<vector<int> > dp(s);
	dp[n-1][m-1]=1;
	for(int i=m-2;i>=0;i--){
		dp[n-1][i]=max(1,dp[n-1][i+1]-s[n-1][i+1]);
	}
	for(int j=n-2;j>=0;j--){
		dp[j][m-1]=max(1,dp[j+1][m-1]-s[j+1][m-1]);
	}
	for(int i=n-2;i>=0;i--){
		for(int j=m-2;j>=0;j--){
			dp[i][j]=max(1,min(dp[i][j+1]-s[i][j+1],dp[i+1][j]-s[i+1][j]));
		}
	}

	return max(1,dp[0][0]-s[0][0]);
}

int main(int argc, char *argv[])
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > s(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>s[i][j];
		}
	}

	cout<<minValue(s,n,m)<<endl;
	
	return 0;
}
