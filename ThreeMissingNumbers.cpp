#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

int f(vector<int> &s){
	long r=0;
	map<int,int> mmap;
	for(int i=0;i<s.size();i++){
		mmap[s[i]]=1;
	}
    vector<int> t;
	for(int i=1;i<=10000;i++){
		if(!mmap[i]){
			t.push_back(i);
		}
	}
    sort(t.begin(),t.end());
    char a[100];
    sprintf(a,"%d%d%d",t[0],t[1],t[2]);
    for(int i=0;i<strlen(a);i++){
        r*=10;
        r+=(a[i]-'0');
    }
	return r%7;
}

int main(int argc, char *argv[])
{
	int n=9997;
	vector<int> s;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}
	cout<<f(s)<<endl;
	
	return 0;
}
