/*
����һ������������д��������ж��ٶ������ĺ͵���������������������������������ֵС��1000. �磬����Ϊ10������Ӧ��������Ϊ2�����������������ĺ�Ϊ10���ֱ�Ϊ��5,5��,��3,7����
*/

#include <iostream>
#include <vector>
using namespace std;

int primeNum(int n){
	vector<bool> prime(1000,true);
	prime[0]=prime[1]=false;
	for(int i=2;i<1000;i++){
		for(int j=i*2;j<1000;j+=i){
			prime[j]=false;
		}
	}
	int c=0;
	for(int i=2;i<=n/2;i++){
		if(prime[i]&&prime[n-i]){
			c++;
		}
	}
	return c;
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		cout<<primeNum(n)<<endl;
	}
	
	return 0;
}
