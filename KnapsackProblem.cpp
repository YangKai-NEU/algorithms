#include <iostream>
#include <vector>
using namespace std;

int KnapsackProblem(vector<int> &c, vector<int> &value,int maxv){
	int n=c.size();
	vector<int> s(maxv+1,0);
	for(int i=0;i<n;i++){
		for(int j=1;j<=maxv;j++){
			if(j>=c[i]){
				int tmp=s[j-c[i]]+value[i];
				s[j]=s[j]<tmp?tmp:s[j];
			}
		}
	}
	return s[maxv];
}

int main(int argc, char *argv[])
{
	vector<int> a,b;
	int s1[]={2,2,6,5,4};
	int s2[]={6,3,5,4,6};
	int n=5;
	for(int i=0;i<n;i++){
		a.push_back(s1[i]);
		b.push_back(s2[i]);
	}
	int maxv=10;
	cout<<KnapsackProblem(a,b,maxv)<<endl;
	return 0;
}
