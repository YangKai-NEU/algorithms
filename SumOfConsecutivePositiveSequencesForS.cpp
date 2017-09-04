#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > r;

		for(int i=1;i<=sum/2+1;i++){
			if(sum%i==0&&(sum/i)%2==1&&sum/i>=3&&i-(sum/i-1)/2>=1&&i+(sum/i-1)/2<=sum/2+1){
				vector<int> tmp;
				for(int j=i-(sum/i-1)/2;j<=i+(sum/i-1)/2;j++){
					tmp.push_back(j);
				}
				r.push_back(tmp);
			}
			if(sum%(i+i+1)==0&&i-(sum/(i+i+1))+1>=1&&i+1+(sum/(i+i+1))-1<=sum/2+1){
				vector<int> tmp;
				for(int j=i-(sum/(i+i+1))+1;j<=i+1+(sum/(i+i+1))-1;j++){
					tmp.push_back(j);
				}
				r.push_back(tmp);
			}
		}

		return r;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;

	vector<vector<int> > r=solution.FindContinuousSequence(100);
	
	for(int i=0;i<r.size();i++){
		for(int j=0;j<r[i].size();j++){
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
