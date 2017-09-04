#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &r) {
		for(int i=0;i<r.size();i++){
			r[i]++;
		}
        vector<int> s(r.size(),1);
		vector<int> tr(r);
		for(int i=0;i<r.size();i++){
			if(i==0&&r[i]<=r[i+1]){
				tr[i]=1;
			}else if(i==r.size()-1&&r[i]<=r[i-1]){
				tr[i]=1;
			}else if(r[i]<=r[i-1]&&r[i]<=r[i+1]){
				tr[i]=1;
			}
		}
		if(tr[0]>tr[1]){
			s[0]=2;
		}
		for(int i=1;i<tr.size()-1;i++){
			int maxv=max(tr[i-1],tr[i+1]);
			if(tr[i]>maxv){
				s[i]=max(s[i-1],s[i+1])+1;
			}else if(tr[i]>tr[i-1]&&tr[i]<=tr[i+1]){
				s[i]=s[i-1]+1;
			}else if(tr[i]<=tr[i-1]&&tr[i]>tr[i+1]){
				s[i]=s[i+1]+1;
			}
		}
		if(tr[tr.size()-1]>tr[tr.size()-2]){
			s[tr.size()-1]=s[tr.size()-2]+1;
		}
		for(int i=tr.size()-2;i>=1;i--){
			int maxv=max(tr[i-1],tr[i+1]);
			if(tr[i]>maxv){
				s[i]=max(s[i-1],s[i+1])+1;
			}else if(tr[i]>tr[i-1]&&tr[i]<=tr[i+1]){
				s[i]=s[i-1]+1;
			}else if(tr[i]<=tr[i-1]&&tr[i]>tr[i+1]){
				s[i]=s[i+1]+1;
			}
		}
		if(tr[0]>tr[1]){
			s[0]=s[1]+1;
		}
		int re=0;
		for(int i=0;i<s.size();i++){
			re+=s[i];
		}
		return re;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> a;
	int b[]={1,2,4,4,3};
	for(int i=0;i<sizeof(b)/sizeof(int);i++){
		a.push_back(b[i]);
	}
	cout<<s.candy(a)<<endl;
	
	return 0;
}
