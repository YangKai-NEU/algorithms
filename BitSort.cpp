#include <iostream>
#include <vector>
using namespace std;

void BitSort(vector<int> &s){
	int n=s.size();
	int max=0;
	for(int i=0;i<n;i++){
		max=max<s[i]?s[i]:max;
	}
	max++;
	vector<bool> a(max,0);
	for(int i=0;i<n;i++){
		a[s[i]]=1;
	}
	s.clear();
	for(int i=0;i<max;i++){
		if(a[i]){
			s.push_back(i);
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
	BitSort(s);
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}