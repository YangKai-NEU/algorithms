/*
给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000. 如，输入为10，程序应该输出结果为2。（共有两对质数的和为10，分别为（5,5）,（3,7））
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
