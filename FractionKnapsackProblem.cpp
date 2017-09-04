#include <iostream>
#include <vector>
using namespace std;

double KnapsackProblemFraction(vector<int> &c, vector<int> &value,int maxv){
	int n=c.size();
	double result=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(value[j+1]/c[j+1]>value[j]/c[j]){
				int tmp=c[j];
				c[j]=c[j+1];
				c[j+1]=tmp;
				tmp=value[j];
				value[j]=value[j+1];
				value[j+1]=tmp;
			}
		}
	}
	int pos=0;
	while(maxv>0){
		if(maxv>=c[pos]){
			maxv-=c[pos];
			result+=value[pos];
		}else{
			result+=maxv*(value[pos]*1.0/c[pos]);
			maxv=0;
		}
		pos++;
	}
	return result;
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
	cout<<KnapsackProblemFraction(a,b,maxv)<<endl;
	return 0;
}
