#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string s;
	while(cin>>s){
		vector<int> a;
		vector<int> b;
		int pre=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='+'){
				b.push_back(1);
				a.push_back(pre);
				pre=0;
			}else if(s[i]=='-'){
				b.push_back(2);
				a.push_back(pre);
				pre=0;
			}else if(s[i]=='*'){
				b.push_back(3);
				a.push_back(pre);
				pre=0;
			}else if(s[i]=='/'){
				b.push_back(4);
				a.push_back(pre);
				pre=0;
			}else {
				pre*=10;
				pre+=(s[i]-'0');
			}
		}
		a.push_back(pre);
		for(int i=0;i<b.size();i++){
			switch(b[i]){
				case 1:
					a[0]=a[0]+a[1];
					break;
				case 2:
					a[0]=a[0]-a[1];
					break;
				case 3:
					a[0]=a[0]*a[1];
					break;
				case 4:
					a[0]=a[0]/a[1];
					break;
			}
			a.erase(a.begin()+1);
		}
		cout<<a[0]<<endl;
	}
	
	return 0;
}
