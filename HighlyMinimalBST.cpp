/*
��Ŀ����
����һ��Ԫ�ظ�����ͬ�Ұ��������е��������У����дһ���㷨������һ�ø߶���С�Ķ����������
����һ����������int[] vals,�뷵�ش����Ķ���������ĸ߶ȡ�
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
