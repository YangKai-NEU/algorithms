#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<vector<int> > process(vector<pair<int,string> > &s){
	vector<vector<int> > r;
	map<string,vector<int> > mmap;
	for(int i=0;i<s.size();i++){
		mmap[s[i].second].push_back(s[i].first);
	}
	string type[4]={"前端工程师","java工程师","数据工程师","算法工程师"};
	int count[4]={0};
	for(int i=0;i<4;i++){
		count[i]=mmap[type[i]];
	}
	if(count[1]>=count[2]+count[3]){
		
		int i=0,j=0;
		while(i<count[1]&&j<count[2]){
			vector<int> tmp;
			tmp.push_back(mmap[s[1]][i++]);
			tmp.push_back(mmap[s[2]][j++]);
			r.push_back(tmp);
		}
		j=0;
		while(i<count[1]&&j<count[3]){
			vector<int> tmp;
			tmp.push_back(mmap[s[1]][i++]);
			tmp.push_back(mmap[s[3]][j++]);
			r.push_back(tmp);
		}
		

		
	}else{
		int i=0,j=0;
		while(i<count[1]&&j<count[2]){
			vector<int> tmp;
			tmp.push_back(mmap[s[1]][i++]);
			tmp.push_back(mmap[s[2]][j++]);
			r.push_back(tmp);
		}
		j=0;
		while(i<count[1]&&j<count[3]){
			vector<int> tmp;
			tmp.push_back(mmap[s[1]][i++]);
			tmp.push_back(mmap[s[3]][j++]);
			r.push_back(tmp);
		}



	}
	return r;
} 

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		vector<pair<int,string> > s;
		for(int i=0;i<n;i++){
			int t;
			string type;
			cin>>t>>type;
			s.push_back(make_pair(t,type));
		}
		vector<vector<int> > r=process(s);
		for(int i=0;i<r.size();i++){
			for(int j=0;j<r[i].size();j++){
				cout<<r[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}
