#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
		while(num2){
			//��λ
			int t=num1^num2;
			//�ǽ�λ
			num2=(num1&num2)<<1;
			num1=t;
		}
		return num1;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	cout<<solution.Add(23,12)<<endl;
	
	return 0;
}
