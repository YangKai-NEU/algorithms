#include <iostream>
#include <vector>
using namespace std;

/*
	1	2	3	4	5	
	6	7	8	9	10	
	11	12	13	14	15
	16	17	18	19	20
	21	22	23	24	25
*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > s) {
		vector<int> r;
		int n=s.size();
		if(n==0){
			return r;
		}
		int m=s[0].size();
		if(m==0){
			return r;
		}
		int w=n/2;
		int h=m/2;
		for(int i=0;i<(w<h?w:h);i++){
			for(int j=i;j<m-1-i;j++){
				r.push_back(s[i][j]);
			}
			for(int j=i;j<n-1-i;j++){
				r.push_back(s[j][m-1-i]);
			}
			for(int j=m-1-i;j>i;j--){
				r.push_back(s[n-1-i][j]);
			}
			for(int j=n-1-i;j>i;j--){
				r.push_back(s[j][i]);
			}
		}
		if(w<=h&&n%2==1){
			for(int i=w;i<=m-1-w;i++){
				r.push_back(s[n/2][i]);
			}
		}else if(h<=w&&m%2==1){
			for(int i=h;i<=n-1-h;i++){
				r.push_back(s[i][m/2]);
			}
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	vector<vector<int>/**/> s;
	int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	int n=3,m=5;
	for(int i=0;i<n;i++){
		vector<int> tmp;
		for(int j=0;j<m;j++){
			tmp.push_back(a[m*i+j]);
		}
		s.push_back(tmp);
	}
	vector<int> r=solution.printMatrix(s);
	for(int i=0;i<r.size();i++){
		cout<<r[i]<<" ";
	}
	cout<<endl;

	return 0;
}
