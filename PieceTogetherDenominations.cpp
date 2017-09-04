#include <iostream>
#include <vector>
using namespace std;

long f(int n){
	vector<long> s(n+1,1);
	int a[]={1,5,10,20,50,100};
	for(int i=1;i<6;i++){
		for(int j=a[i];j<=n;j++){
			s[j]+=s[j-a[i]];
		}
	}
	return s[n];
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		cout<<f(n)<<endl;
	}
	
	return 0;
}
