#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int r;

	int count(int x,int y){
		int r=0;
		while(x){
			r+=x%10;
			x/=10;
		}
		while(y){
			r+=y%10;
			y/=10;
		}
		return r;
	}
    int movingCount(int threshold, int rows, int cols)
    {
		vector<vector<bool> > v(rows,vector<bool>(cols,true));
		if(threshold<0){
			return 0;
		}
		v[0][0]=false;
		r=1;
		check(v,threshold,0,0);
		return r;
    }
	void check(vector<vector<bool> > &v,int threshold,int i,int j){
		if(i-1>=0&&v[i-1][j]&&count(i-1,j)<=threshold){
			v[i-1][j]=false;
			r++;
			check(v,threshold,i-1,j);
		}
		if(i+1<v.size()&&v[i+1][j]&&count(i+1,j)<=threshold){
			v[i+1][j]=false;
			r++;
			check(v,threshold,i+1,j);
		}
		if(j-1>=0&&v[i][j-1]&&count(i,j-1)<=threshold){
			v[i][j-1]=false;
			r++;
			check(v,threshold,i,j-1);
		}
		if(j+1<v[i].size()&&v[i][j+1]&&count(i,j+1)<=threshold){
			v[i][j+1]=false;
			r++;
			check(v,threshold,i,j+1);
		}
	}

};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.movingCount(10,1,100)<<endl;
	
	return 0;
}
