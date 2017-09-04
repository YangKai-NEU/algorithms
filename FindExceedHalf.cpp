#include <vector>
#include <iostream>
using namespace std;

int f(int a[],int n){
	int can;
	int ntime;
	for(int i=ntime=0;i<n;i++){
		if(ntime==0){
			can=a[i];
			ntime=1;
		}else{
			if(can==a[i]){
				ntime++;
			}else{
				ntime--;
			}
		}
	}
	return can;
}

int main(int argc, char *argv[])
{
	int a[]={1,2,5,2,2,5,5,5,5,5,5,5};

	cout<<f(a,sizeof(a)/sizeof(int))<<endl;
	
	return 0;
}
