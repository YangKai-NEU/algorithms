#include <iostream>
using namespace std;

class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
		int r=n;
		m=m<<j;
		for(int t=j;t<=i;t++){
			int tmp=1<<t;
			r=r|(m&tmp);
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	BinInsert b;
	cout<<b.binInsert(1024,19,2,6)<<endl;
	
	return 0;
}
