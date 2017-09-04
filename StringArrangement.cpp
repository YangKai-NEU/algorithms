#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
		if(str.size()==0){
			return result;
		}
		if(str.size()==1){
			result.push_back(str);
			return result;
		}
		for(int i=0;i<str.length();i++){
			string tmp=str;
			tmp.erase(tmp.begin()+i);
			vector<string> t=Permutation(tmp);
			for(int j=0;j<t.size();j++){
				result.push_back(str[i]+t[j]);
			}
		}

		sort(result.begin(),result.end());
		for(int i=result.size()-1;i>0;i--){
			if(result[i]==result[i-1]){
				result.erase(result.begin()+i);
			}
		}
		return result;
    }
};

int main(int argc, char *argv[])
{
	string a="aaaaaaaaa";
	Solution solution;
	vector<string> r=solution.Permutation(a);
	for(int i=0;i<r.size();i++){
		cout<<r[i]<<endl;
	}
	
	return 0;
}
