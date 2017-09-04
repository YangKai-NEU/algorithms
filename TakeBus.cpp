#include <vector>
#include <iostream>
using namespace std;

class TakeBuses {
public:
    int chooseLine(vector<int> stops, vector<int> period, vector<int> interval, int n, int s) {
        // write code here
		int r=10000000;
		for(int i=0;i<n;i++){
			int t=0;
			while(t<s){
				t+=interval[i];
			}
			t+=stops[i]*period[i];
			t+=5*(stops[i]+1);
			r=r<t?r:t;
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	TakeBuses t;

	
	return 0;
}
