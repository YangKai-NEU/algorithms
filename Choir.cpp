/*
题目描述
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
示例1
输入

3
7 4 7
2 50
输出

49
*/

#include <iostream>
#include <vector>
using namespace std;

long f(vector<long> &s,int k,int d){
	int n=s.size();
	vector<vector<long> > tmax(n+1,vector<long>(k+1));
	vector<vector<long> > tmin(n+1,vector<long>(k+1));
	long result=0;
	for(int i=1;i<=n;i++){
		tmax[i][1]=tmin[i][1]=s[i-1];
		for(int j=2;j<=k;j++){
            for(int q=i-1;q>=i-d&&q>=1;q--){
                tmax[i][j]=max(tmax[i][j],max(tmax[q][j-1]*s[i-1],tmin[q][j-1]*s[i-1]));
				tmin[i][j]=min(tmin[i][j],min(tmin[q][j-1]*s[i-1],tmax[q][j-1]*s[i-1]));
            }
		}
        result=max(result,max(tmin[i][k],tmax[i][k]));
	}
	return result;
}

int main(int argc, char *argv[])
{
	vector<long> s;
	int n,k,d;
	cin>>n;
	for(int i=0;i<n;i++){
		long t;
		cin>>t;
		s.push_back(t);
	}
	cin>>k>>d;
	
	cout<<f(s,k,d)<<endl;

	
	return 0;
}
