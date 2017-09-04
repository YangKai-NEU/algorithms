/*
[编程题] single-number
时间限制：1秒
空间限制：32768K

Given an array of integers, every element appears twice except for one. Find that single one.
Note: 
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int r=0;
		for(int i=0;i<n;i++){
			r^=A[i];
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	int A[]={2,1,4,3,2,1,4};

	Solution s;
	cout<<s.singleNumber(A,7)<<endl;
	
	return 0;
}
