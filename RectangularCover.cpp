#include <iostream>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
		if(number<=2){
			return number;
		}
		return rectCover(number-1)+rectCover(number-2);
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.rectCover(13)<<endl;
	return 0;
}
