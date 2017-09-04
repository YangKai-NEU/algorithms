#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string a,b;
	while(cin>>a>>b){
		string c="";
		int pre=0;
		int i=a.length()-1;
		int j=b.length()-1;
		bool state=true;
		while(i>=0&&j>=0){
			if(a[i]<'0'||a[i]>'9'){
				state=false;
				break;
			}
			if(b[j]<'0'||b[j]>'9'){
				state=false;
				break;
			}
			int t=a[i]-'0'+b[j]-'0'+pre;
			pre=t/10;
			t=t%10;
			char tt='0'+t;
			c+=tt;
			i--;
			j--;
		}
		while(i>=0){
			if(a[i]<'0'||a[i]>'9'){
				state=false;
				break;
			}
			int t=a[i]-'0'+pre;
			pre=t/10;
			t=t%10;
			char tt='0'+t;
			c+=tt;
			i--;
		}
		while(j>=0){
			if(b[j]<'0'||b[j]>'9'){
				state=false;
				break;
			}
			int t=b[j]-'0'+pre;
			pre=t/10;
			t=t%10;
			char tt='0'+t;
			c+=tt;
			j--;
		}
		if(pre!=0){
			char tt='0'+pre;
			c+=tt;
		}
		if(!state){
			cout<<"error"<<endl;
		}else{
			reverse(c.begin(),c.end());
			cout<<c<<endl;
		}
	}
	
	return 0;
}
