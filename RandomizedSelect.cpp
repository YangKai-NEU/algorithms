#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

int RandomPartition(vector<int> &s,int l,int r){
	int t=rand()%(r-l+1);
	int tem=s[l];
	s[l]=s[l+t];
	s[l+t]=tem;
	int low=l;
	int high=r;
	int tmp=s[low];
	
	while(low<high){
		while(low<high&&s[high]>tmp){
			high--;
		}
		s[low]=s[high];
		while(low<high&&s[low]<tmp){
			low++;
		}
		s[high]=s[low];
	}
	s[low]=tmp;
	return low;
}

int RandomizedSelect(vector<int> &s,int l,int r,int k){
	if(l==r){
		return s[l];
	}
	int c=RandomPartition(s,l,r);
	
	if(c-l+1==k){
		return s[c];
	}
	if(c-l+1<k){
		return RandomizedSelect(s,c+1,r,k-c+l-1);
	}else{
		return RandomizedSelect(s,l,c-1,k);
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
	srand(1);
	int aim=RandomizedSelect(s,0,s.size()-1,4);
	cout<<aim<<endl;
	return 0;
}
