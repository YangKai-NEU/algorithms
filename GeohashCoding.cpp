#include <iostream>
#include <string>
using namespace std;

string geohash(int n){
	string result="";
	int left=-90;
	int right=90;
	while(right-left>=6){
		int mid=(left+right)/2;
		if(n<mid){
			result+='0';
			right=mid;
		}else{
			result+='1';
			left=mid;
		}
	}
	return result;
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		cout<<geohash(n)<<endl;
	}
	
	return 0;
}
