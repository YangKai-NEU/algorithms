/*
小易非常喜欢拥有以下性质的数列:
1、数列的长度为n
2、数列中的每个数都在1到k之间(包括1和k)
3、对于位置相邻的两个数A和B(A在B前),都满足(A <= B)或(A mod B != 0)(满足其一即可)
例如,当n = 4, k = 7
那么{1,7,7,2},它的长度是4,所有数字也在1到7范围内,并且满足第三条性质,所以小易是喜欢这个数列的
但是小易不喜欢{4,4,4,2}这个数列。小易给出n和k,希望你能帮他求出有多少个是他会喜欢的数列。
输入描述:
输入包括两个整数n和k(1 ≤ n ≤ 10, 1 ≤ k ≤ 10^5)


输出描述:
输出一个整数,即满足要求的数列个数,因为答案可能很大,输出对1,000,000,007取模的结果。

输入例子1:
2 2

输出例子1:
3
*/

#include <iostream>
#include <vector>
using namespace std;

int process(int n,int k){
	vector<vector<int> > dp(n+1,vector<int>(k+1,0));
    for(int i=1;i<=k;i++){
        dp[1][i]=1;
    }
	for(int i=2;i<=n;i++){
        int sum=0;
        for(int j=1;j<=k;j++){
            sum+=dp[i-1][j];
            sum%=1000000007;
        }
		for(int j=1;j<=k;j++){
            dp[i][j]=sum;
			for(int kk=j+j;kk<=k;kk+=j){
                dp[i][j]-=dp[i-1][kk];
                if(dp[i][j]<0){
                    dp[i][j]+=1000000007;
                }
			}
		}
	}
    int s=0;
    for(int i=1;i<=k;i++){
        s+=dp[n][i];
        s%=1000000007;
    }
	return s;
}

int main(int argc, char *argv[])
{
	int n,k;
	cin>>n>>k;
	cout<<process(n,k)<<endl;
	
	return 0;
}
