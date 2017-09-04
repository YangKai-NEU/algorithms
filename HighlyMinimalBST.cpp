/*
题目描述
对于一个元素各不相同且按升序排列的有序序列，请编写一个算法，创建一棵高度最小的二叉查找树。
给定一个有序序列int[] vals,请返回创建的二叉查找树的高度。
*/

#include <iostream>
#include <vector>
using namespace std;

class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        // write code here
		int n=vals.size();
		int r=0;
		int t=1;
		while(n>0){
			n-=t;
			t*=2;
			r++;
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	MinimalBST m;
	vector<int> s;
	int a[]={1,2,3,5,3,2,0,1};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	cout<<m.buildMinimalBST(s)<<endl;
	
	return 0;
}
