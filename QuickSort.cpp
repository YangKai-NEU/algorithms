#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int> &s,int l,int h){
	int i=l;
	int j=h;
	if(l>=h){
		return;
	}
	int tmp=s[i];
	while(i<j){
		while(i<j&&s[j]>tmp){
			j--;
		}
		s[i]=s[j];
		while(i<j&&s[i]<tmp){
			i++;
		}
		s[j]=s[i];
	}
	s[i]=tmp;
	QuickSort(s,l,i-1);
	QuickSort(s,i+1,h);
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
	QuickSort(s,0,s.size()-1);
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}