#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	bool s[1000][1000];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			int a=i%4;
			int b=j%4;
			if(a<2&&b<2){
				s[i][j]=true;
			}else if(a<2&&b>=2){
				s[i][j]=false;
			}else if(a>=2&&b<2){
				s[i][j]=false;
			}else{
				s[i][j]=true;
			}
		}
	}
	int c=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c+=s[i][j];
		}
	}
	cout<<c<<endl;
	
	return 0;
}
