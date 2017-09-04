#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

bool check(string s){
	map<char,int> mmap;
	for(int i=0;i<s.length();i++){
		mmap[s[i]]++;
	}
	for(int i=0;i<s.length();i++){
		if(mmap[s[i]]!=1){
			return false;
		}
	}
	return true;
}

int process(vector<string> &s){
	queue<pair<string,int> > mqueue;
	for(int i=0;i<s[0].length();i++){
		string t="";
		t+=s[0][i];
		mqueue.push(make_pair(t,0));
	}
	int count=0;
	while(!mqueue.empty()){
		pair<string,int> top=mqueue.front();
		mqueue.pop();
		if(top.second==s.size()-1){
			if(check(top.first)){
				count++;
				continue;
			}
		}
		if(top.second+1<s.size()){
			for(int i=0;i<s[top.second+1].length();i++){
				string t=top.first;
				t+=s[top.second+1][i];
				mqueue.push(make_pair(t,top.second+1));
			}
		}
	}
	return count;
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		vector<string> s;
		for(int i=0;i<n;i++){
			string t;
			cin>>t;
			s.push_back(t);
		}
		cout<<process(s)<<endl;
	}
	return 0;
}
