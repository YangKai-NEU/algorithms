#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &s, string w) {
		int n=s.size();
		int m=s[0].size();
        vector<vector<bool> > v(n,vector<bool>(m,false));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]==w[0]){
					v[i][j]=true;
					string t=w;
					t.erase(t.begin());
					if(check(s,v,i,j,t)){
						return true;
					}
					v[i][j]=false;
				}
			}
		}
		return false;
    }

	bool check(vector<vector<char> > &s,vector<vector<bool> > &v,int x,int y,string w){
		int n=s.size();
		int m=s[0].size();
		if(w.length()==0){
			return true;
		}
		if(x-1>=0&&!v[x-1][y]&&s[x-1][y]==w[0]){
			v[x-1][y]=true;
			string t=w;
			t.erase(t.begin());
			if(check(s,v,x-1,y,t)){
				return true;
			}
			v[x-1][y]=false;
		}
		if(x+1<n&&!v[x+1][y]&&s[x+1][y]==w[0]){
			v[x+1][y]=true;
			string t=w;
			t.erase(t.begin());
			if(check(s,v,x+1,y,t)){
				return true;
			}
			v[x+1][y]=false;
		}
		if(y-1>=0&&!v[x][y-1]&&s[x][y-1]==w[0]){
			v[x][y-1]=true;
			string t=w;
			t.erase(t.begin());
			if(check(s,v,x,y-1,t)){
				return true;
			}
			v[x][y-1]=false;
		}
		if(y+1<m&&!v[x][y+1]&&s[x][y+1]==w[0]){
			v[x][y+1]=true;
			string t=w;
			t.erase(t.begin());
			if(check(s,v,x,y+1,t)){
				return true;
			}
			v[x][y+1]=false;
		}
		return false;
	}
};

int main(int argc, char *argv[])
{
	vector<vector<char> > a(3,vector<char>(4));
	char b[][5]={"ABCE","SFCS","ADEE"};

	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			a[i][j]=b[i][j];
		}
	}
	Solution s;
	cout<<s.exist(a,"SEE")<<endl;

	
	return 0;
}
