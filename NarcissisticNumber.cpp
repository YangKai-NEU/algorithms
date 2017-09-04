#include <iostream>
#include <vector>
using namespace std;

bool f(int x){
	int r=0;
	int tmp=x;
	while(x){
		r+=(x%10)*(x%10)*(x%10);
		x/=10;
	}
	return r==tmp;
}

int main(int argc, char *argv[])
{
	int a,b;
	while(cin>>a>>b){
		vector<int> s;
		for(int i=a;i<=b;i++){
			if(f(i)){
				s.push_back(i);
			}
		}
        if(s.size()==0){
            cout<<"no"<<endl;
        }else{
            for(int i=0;i<s.size();i++){
                cout<<s[i];
                if(i!=s.size()-1){
                    cout<<" ";
                }
            }
            cout<<endl;
        }
		
	}
	
	return 0;
}
