#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
	int n,m;
	while(cin>>n>>m){
		vector<string> a,b;
		for(int i=0;i<n;i++){
			string t;
			cin>>t;
			a.push_back(t);
		}
		for(int i=0;i<m;i++){
			string t;
			cin>>t;
			b.push_back(t);
		}
		map<string,int> mmap;
		for(int i=b.size()-1;i>=0;i--){
			mmap[b[i]]++;
		}
		int r=0;
		for(int i=0;i<a.size();i++){
			if(mmap[a[i]]){
				r+=(a[i].length()*a[i].length());
				mmap[a[i]]=0;
			}
		}
		cout<<r<<endl;
	}
	
	return 0;
}
