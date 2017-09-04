#include <iostream>
#include <vector>
using namespace std;

pair<int,int> MaxMin(vector<int> &s){
	int n=s.size();
	pair<int,int> result;
	if(n%2==0){
		if(s[0]>s[1]){
			result.first=s[0];
			result.second=s[1];
		}else{
			result.first=s[1];
			result.second=s[0];
		}
		for(int i=2;i<n;i+=2){
			if(s[i]>s[i+1]){
				result.first=result.first>s[i]?result.first:s[i];
				result.second=result.second<s[i+1]?result.second:s[i+1];
			}else{
				result.first=result.first>s[i+1]?result.first:s[i+1];
				result.second=result.second<s[i]?result.second:s[i];
			}
		}
	}else{
		result.first=result.second=s[0];
		for(int i=1;i<n;i+=2){
			if(s[i]>s[i+1]){
				result.first=result.first>s[i]?result.first:s[i];
				result.second=result.second<s[i+1]?result.second:s[i+1];
			}else{
				result.first=result.first>s[i+1]?result.first:s[i+1];
				result.second=result.second<s[i]?result.second:s[i];
			}
		}
	}
	return result;
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
	pair<int,int> result=MaxMin(s);
	cout<<"Max="<<result.first<<", Min="<<result.second<<endl;
	return 0;
}
