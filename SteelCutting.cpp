#include <iostream>
#include <vector>
using namespace std;

int CutRod(vector<int> &p,int n){
	if(n==0){
		return 0;
	}
	int result=-1;
	for(int i=0;i<n;i++){
		int tmp=p[i]+CutRod(p,n-i-1);
		result=result<tmp?tmp:result;
	}
	return result;
}

int main(int argc, char *argv[])
{
	vector<int> p;
	int n=10;
	int a[]={1,5,8,9,10,17,17,20,24,30};
	for(int i=0;i<n;i++){
		p.push_back(a[i]);
	}
	cout<<CutRod(p,n)<<endl;
	return 0;
}
