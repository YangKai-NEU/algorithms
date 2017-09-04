#include <iostream>
#include <vector>
using namespace std;

int ActivitySelect(vector<int> &a,vector<int> &b){
	int n=a.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(b[j+1]<b[j]){
				int tmp=b[j];
				b[j]=b[j+1];
				b[j+1]=tmp;
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	int res=0;
	int t=0;
	for(int i=0;i<n;i++){
		if(a[i]>=t){
			res++;
			t=b[i];
		}
	}
	return res;
}

int main(int argc, char *argv[])
{
	vector<int> a,b;
	int t1[]={1,3,0,5,3,5,6,8,8,2,12};
	int t2[]={4,5,6,7,9,9,10,11,12,14,16};
	int n=11;
	for(int i=0;i<n;i++){
		a.push_back(t1[i]);
		b.push_back(t2[i]);
	}
	cout<<ActivitySelect(a,b)<<endl;
	
	return 0;
}
