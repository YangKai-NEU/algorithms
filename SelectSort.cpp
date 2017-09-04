#include <iostream>
#include <vector>
using namespace std;

void SelectSort(vector<int> &s){
	int n=s.size();
	for(int i=0;i<n;i++){
		int pos=i;
		for(int j=i+1;j<n;j++){
			if(s[j]<s[pos]){
				pos=j;
			}
		}
		if(pos!=i){
			s[pos]=s[pos]+s[i];
			s[i]=s[pos]-s[i];
			s[pos]=s[pos]-s[i];
		}
	}
}

int main(){

	vector<int> s;
	int a[]={23,12,35,56,78,89,45,25,232,456};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	SelectSort(s);
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}