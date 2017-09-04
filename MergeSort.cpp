#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &s,int l,int m,int h){
	int i=l;
	int j=m+1;
	vector<int> ts;
	while(i<=m&&j<=h){
		if(s[i]<s[j]){
			ts.push_back(s[i]);
			i++;
		}else {
			ts.push_back(s[j]);
			j++;
		}
	}
	while(i<=m){
		ts.push_back(s[i]);
		i++;
	}
	while(j<=h){
		ts.push_back(s[j]);
		j++;
	}
	for(int i=l;i<=h;i++){
		s[i]=ts[i-l];
	}
}

void MergeSort(vector<int> &s,int l,int h){
	if(l<h){
		MergeSort(s,l,(l+h)/2);
		MergeSort(s,(l+h)/2+1,h);
		Merge(s,l,(l+h)/2,h);
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
	MergeSort(s,0,s.size()-1);
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}