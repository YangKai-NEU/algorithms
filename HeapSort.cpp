#include <iostream>
#include <vector>
using namespace std;

void HeapAdjust(vector<int> &a,int i,int size)
{
    int lchild=2*i;			//i�����ӽڵ���� 
    int rchild=2*i+1;		//i���Һ��ӽڵ���� 
    int max=i;				//��ʱ���� 
    if(i<=size/2)			//���i����Ҷ�ڵ�Ͳ��ý��е��� 
    {
        if(lchild<=size&&a[lchild]>a[max])
        {
            max=lchild;
        }    
        if(rchild<=size&&a[rchild]>a[max])
        {
            max=rchild;
        }
        if(max!=i)
        {
            swap(a[i],a[max]);
            HeapAdjust(a,max,size);	
        }
    }        
}

void BuildHeap(vector<int> &a,int size)
{
    int i;
    for(i=size/2;i>=0;i--)
    {
        HeapAdjust(a,i,size);    
    }    
} 

void HeapSort(vector<int> &a,int size)
{
    int i;
    BuildHeap(a,size);
    for(i=size;i>=0;i--)
    {
        swap(a[0],a[i]);
		HeapAdjust(a,0,i-1);
    }
} 

int main(int argc, char *argv[])
{
    vector<int> s;
	int a[]={23,12,35,56,78,89,45,25,232,456};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		s.push_back(a[i]);
	}
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	HeapSort(s,s.size()-1);
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}