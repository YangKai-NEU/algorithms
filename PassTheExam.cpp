#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

double pro(vector<double> &s){
	int n=s.size();
	int suit=n*3/5;
	if(suit*5!=n*3){
		suit++;
	}
	vector<vector<double> > dp(n+1,vector<double>(n+1,0));
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		//到目前为止仍然没有答对题
		dp[i][0]=dp[i-1][0]*(1-s[i-1]);
		for(int j=1;j<=i;j++){
			dp[i][j]=dp[i-1][j]*(1-s[i-1])+dp[i-1][j-1]*s[i-1];
		}
	}
	double sum=0;
	for(int i=suit;i<=n;i++){
		sum+=dp[n][i];
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		vector<double> s;
		for(int i=0;i<n;i++){
			double t;
			cin>>t;
			s.push_back(t/100.0);
		}
		printf("%.5lf\n",pro(s));
	}
	
	return 0;
}
