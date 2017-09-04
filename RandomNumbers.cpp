#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	
	int n;
	while(cin>>n){
        vector<int> s;
        for(int i=0;i<n;i++){
            int t;
            cin>>t;
            s.push_back(t);
        }
        sort(s.begin(),s.end());
        for(int i=s.size()-1;i>=1;i--){
            if(s[i]==s[i-1]){
                s.erase(s.begin()+i);
            }
        }
        for(int i=0;i<s.size();i++){
            cout<<s[i]<<endl;
        }
    }
	
	return 0;
}
