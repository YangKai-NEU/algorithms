#include <iostream>
using namespace std;

int f(int n,int m){
	if(n==1||m==1){
		return 1;
	}
	return f(n-1,m)+f(n,m-1);
}

int main(int argc, char *argv[])
{
	int n,m;
	cin>>n>>m;
	cout<<f(n+1,m+1)<<endl;
	
	return 0;
}
