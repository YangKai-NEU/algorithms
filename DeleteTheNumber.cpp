#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n){
		vector<int> s;
		for(int i=0;i<n;i++){
			if(s.size()<1000){
				s.push_back(i);
			}
		}
		int pos=2;
		while(s.size()!=1){
			s.erase(s.begin()+pos);
			pos+=2;
			pos%=s.size();
		}
		cout<<s[0]<<endl;
	}
	
	return 0;
}
