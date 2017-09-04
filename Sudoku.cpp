/*
7 2 6 9 0 4 0 5 1
0 8 0 6 0 7 4 3 2
3 4 1 0 8 5 0 0 9
0 5 2 4 6 8 0 0 7
0 3 7 0 0 0 6 8 0
0 9 0 0 0 3 0 1 0
0 0 0 0 0 0 0 0 0
9 0 0 0 2 1 5 0 0
8 0 0 3 0 0 0 0 0
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;

vector<pair<int,int> > p;

bool f(vector<vector<int> > &s,int pos){
	int n=s.size();
	if(pos==p.size()){
		return true;
	}else{
		map<int,int> m;
		for(int i=0;i<n;i++){
			if(s[i][p[pos].second]!=0){
				m[s[i][p[pos].second]]=1;
			}
			if(s[p[pos].first][i]!=0){
				m[s[p[pos].first][i]]=1;
			}
		}
		int l=3*(p[pos].first/3);
		int r=3*(p[pos].second/3);
		for(int i=l;i<l+3;i++){
			for(int j=r;j<r+3;j++){
				if(s[i][j]!=0){
					m[s[i][j]]=1;
				}
			}
		}
		for(int i=1;i<=9;i++){
			if(!m[i]){
				s[p[pos].first][p[pos].second]=i;
				if(f(s,pos+1)){
					return true;
				}
				s[p[pos].first][p[pos].second]=0;
			}
		}
		return false;
	}
}

int main(int argc, char *argv[])
{
	int n=9;
	vector<vector<int> > s;
	for(int i=0;i<n;i++){
		vector<int> tmp;
		for(int j=0;j<n;j++){
			int t;
			cin>>t;
			tmp.push_back(t);
			if(t==0){
				p.push_back(make_pair(i,j));
			}
		}
		s.push_back(tmp);
	}
	f(s,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<s[i][j];
			if(j!=n-1){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}
