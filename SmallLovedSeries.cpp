/*
С�׷ǳ�ϲ��ӵ���������ʵ�����:
1�����еĳ���Ϊn
2�������е�ÿ��������1��k֮��(����1��k)
3������λ�����ڵ�������A��B(A��Bǰ),������(A <= B)��(A mod B != 0)(������һ����)
����,��n = 4, k = 7
��ô{1,7,7,2},���ĳ�����4,��������Ҳ��1��7��Χ��,�����������������,����С����ϲ��������е�
����С�ײ�ϲ��{4,4,4,2}������С�С�׸���n��k,ϣ�����ܰ�������ж��ٸ�������ϲ�������С�
��������:
���������������n��k(1 �� n �� 10, 1 �� k �� 10^5)


�������:
���һ������,������Ҫ������и���,��Ϊ�𰸿��ܴܺ�,�����1,000,000,007ȡģ�Ľ����

��������1:
2 2

�������1:
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
