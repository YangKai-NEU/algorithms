#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		map<int,int> mmap;
		for(int i=0;i<data.size();i++){
			mmap[data[i]]++;
		}
		bool state=false;
		for(int i=0;i<data.size();i++){
			if(mmap[data[i]]==1){
				if(!state){
					state=true;
					*num1=data[i];
				}else{
					*num2=data[i];
				}
			}
		}
    }
};

int main(int argc, char *argv[])
{
	vector<int> s;
	int a[]={2,4,1,2,1,4,5,3,9,5};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	int aa,b;
	Solution solution;
	solution.FindNumsAppearOnce(s,&aa,&b);
	cout<<aa<<","<<b<<endl;
	
	return 0;
}
