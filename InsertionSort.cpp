#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int> &s){
	int n=s.size();
	int i,j;
	for(i=1;i<n;i++){
		int tmp=s[i];
		for(j=i-1;j>=0&&tmp<s[j];j--){
			s[j+1]=s[j];
		}
		s[j+1]=tmp;
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
	InsertSort(s);
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}