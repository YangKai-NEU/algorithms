#include <iostream>
using namespace std;

class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        while(a!=b){
			if(a<b){
				b/=2;
			}else{
				a/=2;
			}
		}
		return a;
    }
};

int main(int argc, char *argv[])
{
	LCA l;
	cout<<l.getLCA(24,35)<<endl;
	
	return 0;
}
