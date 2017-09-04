#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	int n,m;
	while(cin>>n>>m){
		set<int> s;
		int t;
		for(int i=0;i<n+m;i++){
			cin>>t;
			s.insert(t);
		}
		vector<int> ss;
		for(set<int>::iterator it=s.begin();it!=s.end();it++){
			ss.push_back(*it);
		}
		sort(ss.begin(),ss.end());
		for(int i=0;i<ss.size();i++){
			cout<<ss[i];
			if(i!=ss.size()-1){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}
