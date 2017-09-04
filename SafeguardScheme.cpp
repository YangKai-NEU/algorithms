/*
��Ŀ����
ս����Ϸ��������Ҫ���ھ�Ҫ�����ˣ���εĽ������������������������СB�����׶��ķ����������׶�λ��һ�����滷ɽ������У���Χ��n��Сɽ����һ��������ΪԤ����ʩ��СB�ƻ���ÿ��Сɽ������һ���۲��ڣ���ҹ��ͣ�Ĳt����Χ����������� һ��������������¼���ɽ���ϵĸ��ڽ���ȼ���̣��������������ڵ�ɽ��֮��û�и��ߵ�ɽ���ڵ�������֮��������ͨ·������ڿ��Թ۲쵽��һ��ɽ���ϵķ����Ƿ��ȼ������Сɽ���ڻ��ϣ���������Сɽ֮�����������ͬ������ͨ·�������������ڵ��������£�һ��ɽ���ϸ��ڵ�ȼ�ķ������ٿ���ͨ��һ��ͨ·����һ�˹۲쵽�������������ڵĸ��ڣ�һ�˵ĸ���һ�����Է���һ�˵�ȼ�ķ��̡� СB��Ƶ����ֱ���������һ����Ҫ�������ܹ��۲⵽�Է����̵ĸ��ڶԵ���������ϣ�����ܹ��������������⡣
��������:
�������ж���������ݣ�ÿһ��������ݵĵ�һ��Ϊһ������n(3<=n<=10^6),Ϊ�׶���Χ��Сɽ�������ڶ���Ϊn�����������α�ʾΪСɽ�ĸ߶�h��1<=h<=10^9��.
�������:
��ÿ��������ݣ��ڵ�����һ����������໥�۲쵽�ĸ��ڵĶ�����
ʾ��1
����

5
1 2 4 5 3
���

7
*/

#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	vector<int> s(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int c=0;
	map<pair<int,int>,int> mmap;
	for(int i=0;i<n;i++){
		int cur=s[i];
		int pre=s[(i+1)%n];
		mmap[make_pair(min(cur,pre),max(cur,pre))]=1;
		if(cur>=pre){
			for(int j=i+2;j!=i;j++){
				j=j%n;
				if(s[j]<pre){
					continue;
				}
				mmap[make_pair(min(cur,s[j]),max(cur,s[j]))]=1;
				pre=pre>s[j]?pre:s[j];
				if(pre>cur){
					break;
				}
			}
		}
		
	}
	for(int i=n-1;i>=0;i--){
		int cur=s[i];
		int pre=s[(i-1+n)%n];
		mmap[make_pair(min(cur,pre),max(cur,pre))]=1;
		if(cur>=pre){
			for(int j=i-2;j!=i;j--){
				j+=n;
				j%=n;
				if(s[j]<pre){
					continue;
				}
				mmap[make_pair(min(cur,s[j]),max(cur,s[j]))]=1;
				pre=pre>s[j]?pre:s[j];
				if(pre>cur){
					break;
				}
			}
		}
		
	}

	cout<<mmap.size()<<endl;
	
	return 0;
}
