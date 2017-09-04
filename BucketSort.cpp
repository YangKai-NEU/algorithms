#include <iostream>
#include <vector>
using namespace std;

void BucketSort(vector<int> &s){
	int n=s.size();
	int deviation=100;
	int max=0;
	for(int i=0;i<n;i++){
		max=max<s[i]?s[i]:max;
	}
	max+=1;
	vector<vector<int>/**/> a(max%deviation==0?max/deviation:max/deviation+1);
	int i,j;
	for(i=0;i<n;i++){
		int b=s[i]/deviation;
		a[b].push_back(s[i]);
		for(j=a[b].size()-2;j>=0&&a[b][j]>s[i];j--){
			a[b][j+1]=a[b][j];
		}
		a[b][j+1]=s[i];
	}
	s.clear();
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			s.push_back(a[i][j]);
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
	BucketSort(s);
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}