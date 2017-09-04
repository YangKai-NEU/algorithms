#include <iostream>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         int count=0;
		 while(n){
			if(n<0){
                count++;
            }
			n=n<<1;
		 }
		 return count;
     }
};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.NumberOf1(213213)<<endl;
	
	return 0;
}
