#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	set<int> s;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.insert(t);
	}
	if(s.size()>=3){
		set<int>::iterator it=s.begin();
		for(int c=1;it!=s.end();it++,c++){
			if(c==3){
				cout<<*it<<endl;
				break;
			}
		}
	}else{
		cout<<-1<<endl;
	}
	
	return 0;
}
