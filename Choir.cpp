/*
��Ŀ����
�� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻���
��������:
ÿ��������� 1 ������������ÿ���������ݵĵ�һ�а���һ������ n (1 <= n <= 50)����ʾѧ���ĸ�������������һ�У����� n ����������˳���ʾÿ��ѧ��������ֵ ai��-50 <= ai <= 50������������һ�а�������������k �� d (1 <= k <= 10, 1 <= d <= 50)��
�������:
���һ�б�ʾ���ĳ˻���
ʾ��1
����

3
7 4 7
2 50
���

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
