#include <iostream>
#include <vector>
using namespace std;

void CountingSort(vector<int> &s){
	int k=0;
	for(int i=0;i<s.size();i++){
		k=k>s[i]?k:s[i];
	}
	vector<int> C(k+1,0);
	for(int i=0;i<s.size();i++){
		C[s[i]]++;
	}
	for(int i=1;i<=k;i++){
		C[i]=C[i]+C[i-1];
	}
	vector<int> B(s.size(),0);
	for(int i=s.size()-1;i>=0;i--){
		B[C[s[i]]-1]=s[i];
		C[s[i]]--;
	}
	for(int i=0;i<s.size();i++){
		s[i]=B[i];
	}
} 

int main(int argc, char *argv[])
{
	vector<int> s;
	int a[]={2,5,3,0,2,3,0,3};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	CountingSort(s);
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}
