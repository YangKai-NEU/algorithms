#include <vector>
#include <iostream>
using namespace std;

void RadixSort(vector<int> &s){
	int tmp=1;
	int n=s.size();
	bool state=false;
	while(true){
		vector<vector<int>/**/> a(10);
		for(int i=0;i<n;i++){
			a[(s[i]/tmp)%10].push_back(s[i]);
		}
		s.clear();
		for(int i=0;i<10;i++){
			if(a[i].size()==n){
				state=true;
			}
			for(int j=0;j<a[i].size();j++){
				s.push_back(a[i][j]);
			}
		}
		tmp*=10;
		a.clear();
		if(state){
			break;
		}
	}
}

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
	RadixSort(s);
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}
