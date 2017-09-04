#include <vector>
#include <iostream>
using namespace std;

class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        // write code here
		int w=n/2;
		for(int i=0;i<w;i++){
			for(int j=i;j<n-i-1;j++){
				
				int tmp=mat[i][j];
				mat[i][j]=mat[n-j-1][i];
				mat[n-j-1][i]=mat[n-i-1][n-j-1];
				mat[n-i-1][n-j-1]=mat[j][n-i-1];
				mat[j][n-i-1]=tmp;
			}
		}
		
		return mat;
    }
};

int main(int argc, char *argv[])
{
	Transform t;
	vector<vector<int> > mat;
	int n=4;
	int a[]={
		1,2,3,4,
		5,6,7,8,
		9,10,11,12,
		13,14,15,16
	};

	for(int i=0;i<n;i++){
		vector<int> tmp;
		for(int j=0;j<n;j++){
			tmp.push_back(a[n*i+j]);
		}
		mat.push_back(tmp);
	}
	
	vector<vector<int> > r=t.transformImage(mat,n);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}

	
	return 0;
}
