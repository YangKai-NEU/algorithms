#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		vector<string> s;
		for(int i=0;i<n;i++){
			string a;
			cin>>a;
			s.push_back(a);
		}
		int r=0;
		for(int j=0;j<n;j++){
			int t=1;
			for(int i=1;i<n;i++){
				if(s[i][j]==s[i-1][j]){
					t++;
				}else{
                    r=r>t?r:t;
					t=1;
				}
			}
			r=r>t?r:t;
		}
		cout<<r<<endl;
	}
	
	return 0;
}
