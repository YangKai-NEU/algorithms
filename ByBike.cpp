#include <iostream>
#include <string>
#include <vector>
using namespace std;

string bike_plan(double distance,double speed){
	double price[3];
	int t=(int)(distance/1.5);
	if(t*1.5<distance){
		t++;
	}
	price[0]=t;
	t=(int)(distance/speed);
	if(t*speed<distance){
		t++;
	}
	price[1]=0.2*t;
	if(distance<=2){
		price[2]=1;
	}else if(distance<=4){
		price[2]=3;
	}else if(distance<=8){
		price[2]=5;
	}else {
		price[2]=8;
	}
	double r=max(price[0],max(price[1],price[2]));
	if(r==price[0]){
		return "OFO小黄车";
	}else if(r==price[1]){
		return "永安行";
	}else {
		return "hellobike";
	}
}

int main(int argc, char *argv[])
{
	double distance,speed;
	while(cin>>distance>>speed){
		cout<<bike_plan(distance,speed)<<endl;
	}
	
	return 0;
}
