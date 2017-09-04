#include <iostream>
using namespace std;

int countEnd0(int n){
	int r=0;
	while(n){
		int t=n;
		while(t){
			if(t%5==0){
				r++;
				t/=5;
			}else{
				break;
			}
		}
		n--;
	}
	return r;
}

int CountEnd1(int n){
	int r=0;
	while(n){
		r+=n/5;
		n/=5;
	}
	return r;
}

double f(int n){
	double a=1;
	while(n){
		a*=n--;
	}
	return a;
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		cout<<f(n)<<"\t"<<countEnd0(n)<<"\t"<<CountEnd1(n)<<endl;
	}
	
	return 0;
}
