#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        map<int,int> mmap;
		for(int i=0;i<length;i++){
			mmap[numbers[i]]++;
		}
		for(int i=0;i<length;i++){
			if(mmap[numbers[i]]>=2){
				*duplication=numbers[i];
				return true;
			}
		}
		return false;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	int a[]={1,2,5,3,2,1,5,23,12,3};
	int b;
	cout<<solution.duplicate(a,10,&b)<<endl;
	
	return 0;
}
