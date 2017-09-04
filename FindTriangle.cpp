#include <vector>
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

struct Loc{
public:
	int x,y,z;
	Loc(int a,int b,int c){
		x=a;
		y=b;
		z=c;
	}
};

double dis(Loc *a,Loc *b){
	return sqrt((a->x-b->x)*1.0*(a->x-b->x)+(a->y-b->y)*1.0*(a->y-b->y)+(a->z-b->z)*1.0*(a->z-b->z));
}

double area(Loc *a,Loc *b,Loc *c){
	double l1=dis(a,b);
	double l2=dis(a,c);
	double l3=dis(b,c);
	double h=(l1+l2+l3)/2; 
	return sqrt(h*(h-l1)*(h-l2)*(h-l3));
}

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	vector<pair<char,Loc*> > s;
	for(int i=0;i<n;i++){
		char c;
		int x,y,z;
		cin>>c>>x>>y>>z;
		s.push_back(make_pair(c,new Loc(x,y,z)));
	}
	double r=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;j<n;j++){
				if((s[i].first==s[j].first&&s[j].first==s[k].first)||(s[i].first!=s[j].first&&s[i].first!=s[k].first&&s[j].first!=s[k].first)){
					double t=area(s[i].second,s[j].second,s[k].second);
					r=r<t?t:r;
				}
			}
		}
	}
	printf("%.5lf\n",r);
	
	return 0;
}
