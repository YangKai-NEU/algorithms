/*
��Ŀ����
������һ�úϷ��Ķ����������Ľڵ㶼�������ֱ�ʾ�����ڸ�������������еĸ��ӹ�ϵ����������ĸ߶�
��������:
����ĵ�һ�б�ʾ�ڵ�ĸ���n��1 �� n �� 1000���ڵ�ı��Ϊ0��n-1����ɣ�
������n-1�У�ÿ����������������һ������ʾ���ڵ�ı�ţ��ڶ�������ʾ�ӽڵ�ı��
�������:
������ĸ߶ȣ�Ϊһ������
ʾ��1
����

5
0 1
0 2
1 3
1 4
���

3
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	vector<int> s(n,-1);
    map<int,int> mmap2;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
        if(s[a]==-2){
            s[b]=-2;
            continue;
        }
        if(mmap2[a]<2){
            s[b]=a;
            mmap2[a]++;
        }else{
            s[b]=-2;
        }
	}
	int r=0;
	map<int,int> mmap;
	for(int i=n-2;i>=0;i--){
		if(mmap[i]||s[i]==-2){
			continue;
		}
		int c=1;
		int tmp=i;
		mmap[i]=1;
		while(s[tmp]!=-1){
			tmp=s[tmp];
			mmap[tmp]=1;
			c++;
		}
		if(c>r){
			r=c;
		}
	}
	cout<<r<<endl;
	
	return 0;
}
