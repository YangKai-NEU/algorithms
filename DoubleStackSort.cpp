/*
��Ŀ����
���дһ�����򣬰������ջ�������򣨼����Ԫ��λ��ջ������Ҫ�����ֻ��ʹ��һ�������ջ�����ʱ���ݣ������ý�Ԫ�ظ��Ƶ�������ݽṹ�С�
����һ��int[] numbers(C++��Ϊvector&ltint>)�����е�һ��Ԫ��Ϊջ�����뷵��������ջ����ע������һ��ջ����ζ�������������ֻ�ܷ��ʵ���һ��Ԫ�ء�
����������
[1,2,3,4,5]
���أ�[5,4,3,2,1]
*/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        // write code here
		vector<int> a(numbers);
		vector<int> b;
		int pre;
		while(true){
			pre=-10000;
			while(a.size()!=0){
				if(a[a.size()-1]>=pre){
					b.push_back(a[a.size()-1]);
					pre=a[a.size()-1];
					a.pop_back();
				}else{
					break;
				}
			}
			if(a.size()==0){
				while(b.size()!=0){
					a.push_back(b[b.size()-1]);
					b.pop_back();
				}
				break;
			}
			int tmp=a[a.size()-1];
			a.pop_back();
			while(b.size()!=0){
				if(b[b.size()-1]>tmp){
					a.push_back(b[b.size()-1]);
					b.pop_back();
				}else{
					break;
				}
			}
			a.push_back(tmp);
			while(b.size()!=0){
				a.push_back(b[b.size()-1]);
				b.pop_back();
			}
		}
		return a;
    }
};

int main(int argc, char *argv[])
{
	TwoStacks t;
	vector<int> s;
	int a[]={1,2,4,3,5};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	vector<int> r=t.twoStacksSort(s);
	for(int i=0;i<r.size();i++){
		cout<<r[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
