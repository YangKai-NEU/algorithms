#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &s){
	int n=s.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(s[j+1]<s[j]){
				s[j]=s[j+1]+s[j];
				s[j+1]=s[j]-s[j+1];
				s[j]=s[j]-s[j+1];
			}
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
	BubbleSort(s);
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}