#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		vector<bool> s(n,true);
		for(int i=2;i<n;i++){
			for(int j=2*i;j<n;j+=i){
				s[j]=false;
			}
		}
		int c=0;
		for(int i=2;i<=n/2;i++){
			if(s[i]&&s[n-i]){
				c++;
			}
		}
		cout<<c<<endl;
	}
	
	return 0;
}
