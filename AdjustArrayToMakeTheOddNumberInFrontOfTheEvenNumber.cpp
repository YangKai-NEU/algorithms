#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> tmp1,tmp2;
		for(int i=0;i<array.size();i++){
			if(array[i]%2==1){
				tmp1.push_back(array[i]);
			}else{
				tmp2.push_back(array[i]);
			}
		}
		array.clear();
		for(int i=0;i<tmp1.size();i++){
			array.push_back(tmp1[i]);
		}
		for(int i=0;i<tmp2.size();i++){
			array.push_back(tmp2[i]);
		}
    }
};

int main(int argc, char *argv[])
{
	vector<int> s;
	int a[]={23,12,35,56,78,89,45,25,232,456};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	Solution solution;
	solution.reOrderArray(s);
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}
