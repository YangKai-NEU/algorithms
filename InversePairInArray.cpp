#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	int count;
    int InversePairs(vector<int> data) {
        count=0;
		MergeSort(data,0,data.size()-1);
		return count;
    }
	void Merge(vector<int> &s,int l,int m,int h){
		int i=l;
		int j=m+1;
		vector<int> ts;
		while(i<=m&&j<=h){
			if(s[i]<s[j]){
				ts.push_back(s[i]);
                count+=(j-m-1);
                count%=1000000007;
				i++;
			}else {
				ts.push_back(s[j]);
				j++;
			}
		}
		while(i<=m){
			ts.push_back(s[i]);
            count+=(h-m);
            count%=1000000007;
			i++;
		}
		while(j<=h){
			ts.push_back(s[j]);
			j++;
		}
		for(int i=l;i<=h;i++){
			s[i]=ts[i-l];
		}
	}

	void MergeSort(vector<int> &s,int l,int h){
		if(l<h){
			MergeSort(s,l,(l+h)/2);
			MergeSort(s,(l+h)/2+1,h);
			Merge(s,l,(l+h)/2,h);
		}
	}

};

int main(int argc, char *argv[])
{
	Solution solution;
	vector<int> s;
	int a[]={1,11,3,23,5,16,7,0};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	cout<<solution.InversePairs(s)<<endl;
	
	return 0;
}
