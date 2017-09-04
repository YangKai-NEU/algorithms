#include <iostream>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
    	double t=1.0;
		bool state=true;
		if(exponent<0){
			state=false;
			exponent=-exponent;
		}
		for(int i=0;i<exponent;i++){
			t*=base;
		}
		return state?t:1.0/t;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.Power(2.0,-3)<<endl;
	
	return 0;
}
