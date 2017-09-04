#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int n,m;
	vector<int> s;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}

	sort(s.begin(),s.end());

	int result=0;
	int maxv=0;
	for(int i=0;i<m;i++){
		//有可能剩下的货物已不足以供用户购买
		int tmp=s[i]*min(n,m-i);
		if(tmp>maxv){
			maxv=tmp;
			result=s[i];
		}
	}
	cout<<result<<endl;
	
	return 0;
}
