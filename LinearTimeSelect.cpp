#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

int Partition(vector<int> &s,int l,int r,int x){
	int t=0;
	for(int i=l;i<=r;i++){
		if(s[i]==x){
			t=i;
			break;
		}
	}
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

int LinearTimeSelect(vector<int> &s,int l,int r,int k){
	int n=r-l+1;
	int i,j,q;
	if(n<5){
		for(i=l;i<=r;i++){
			int tmp=s[i];
			for(j=i-1;j>=l&&s[j]>tmp;j--){
				s[j+1]=s[j];
			}
			s[j+1]=tmp;
		}
		return s[l+k-1];
	}
	for(i=0;i<n/5;i++){
		for(j=l+5*i;j<l+5*i+5;j++){
			int tmp=s[j];
			for(q=j-1;q>=l+5*i&&s[q]>tmp;q--){
				s[q+1]=s[q];
			}
			s[q+1]=tmp;
		}
		int t=s[l+i];
		s[l+i]=s[l+i*5+2];
		s[l+i*5+2]=t;
	}
	int x=LinearTimeSelect(s,l,l+n/5-1,n/10+1);
	int c=Partition(s,l,r,x);
	if(c-l+1==k){
		return s[c];
	}
	if(c-l+1<k){
		return LinearTimeSelect(s,c+1,r,k-c+l-1);
	}else{
		return LinearTimeSelect(s,l,c-1,k);
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
	int aim=LinearTimeSelect(s,0,s.size()-1,10);
	cout<<aim<<endl;
	return 0;
}
