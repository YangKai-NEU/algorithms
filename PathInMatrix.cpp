#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
		if(strlen(str)==0){
			return true;
		}
    	vector<vector<char> > s;
		vector<vector<bool> > v(rows,vector<bool>(cols,true));
		for(int i=0;i<rows;i++){
			vector<char> tmp;
			for(int j=0;j<cols;j++){
				tmp.push_back(matrix[cols*i+j]);
			}
			s.push_back(tmp);
		}
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(s[i][j]==str[0]){
					cout<<i<<","<<j<<endl;
					v[i][j]=false;
					if(check(s,v,str+1,i,j)){
						return true;
					}
					v[i][j]=true;
				}
			}
		}
		return false;
    }
	bool check(vector<vector<char> > &s,vector<vector<bool> > &v, char *str,int i,int j){
		if(strlen(str)==0){
			return true;
		}
		if(i-1>=0&&v[i-1][j]&&s[i-1][j]==str[0]){
			v[i-1][j]=false;
			if(check(s,v,str+1,i-1,j)){
				return true;
			}
			v[i-1][j]=true;
		}
		if(i+1<s.size()&&v[i+1][j]&&s[i+1][j]==str[0]){
			v[i+1][j]=false;
			if(check(s,v,str+1,i+1,j)){
				return true;
			}
			v[i+1][j]=true;
		}
		if(j-1>=0&&v[i][j-1]&&s[i][j-1]==str[0]){
			v[i][j-1]=false;
			if(check(s,v,str+1,i,j-1)){
				return true;
			}
			v[i][j-1]=true;
		}
		if(j+1<s[i].size()&&v[i][j+1]&&s[i][j+1]==str[0]){
			v[i][j+1]=false;
			if(check(s,v,str+1,i,j+1)){
				return true;
			}
			v[i][j+1]=true;
		}
		return false;
	}

};

int main(int argc, char *argv[])
{
	char a[]="abcesfcsadee";
	char b[]="fcce";

	Solution solution;
	cout<<solution.hasPath(a,3,4,b)<<endl;
	
	return 0;
}
