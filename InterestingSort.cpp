#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int minOperation(vector<int> &s){
	int n=s.size();
	int r=1;
	vector<int> a(s);
	sort(a.begin(),a.end());
	map<int,int> mmap;
	for(int i=0;i<n;i++){
		mmap[s[i]]=i;
	}
	for(int i=1;i<n;i++){
		if(mmap[a[i]]>=mmap[a[i-1]]){
			r++;
		}else{
			break;
		}
	}
	return n-r;
}

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	vector<int> s;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}
	cout<<minOperation(s)<<endl;
		
	return 0;
}
