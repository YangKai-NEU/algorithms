/*
[�����] ���۽�
ʱ�����ƣ�1��
�ռ����ƣ�32768K
����������Ҫ���һЩ���׵��ʴ������е�ID�����������֣�1.A�ش���B�����⣬ͬʱB�ش���A�����⡣��ôA��B�������ס�2.����ID�û�A������ID�û�Bͬʱ�ش���C�����⣬��ôCҲ�����ס���֪ÿ���û���ID��һ�����֣�һ����������ж���˻ش�

��������:
ÿ�����ݵ�һ��Ϊ��������N(NС�ڵ���200000)���ڶ��п�ʼÿ��һ�����⣬��һ������Ϊ������ID���ڶ�������Ϊ�ش�������������Ϊ���лش��˵�ID��(ID��Ϊ0-1000000������)


�������:
��һ��Ϊ����ID�������ڶ��п�ʼΪ��С�����ÿ��һ������ID��

��������1:
3
1 1 2
2 1 1
3 2 1 2

�������1:
3
1 2 3
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	int n;
    while(cin>>n){
		map<pair<int,int>,int> mmap;
        map<int,vector<int> > mmap3;
        for(int i=0;i<n;i++){
            int t;
            int a;
            cin>>a>>t;
            for(int j=0;j<t;j++){
                int tt;
                cin>>tt;
                if(a!=tt){
                    mmap[make_pair(tt,a)]=1;
                    mmap3[a].push_back(tt);
                }
            }
        }
        map<int,int> mmap2;
        for(map<pair<int,int>,int>::iterator it=mmap.begin();it!=mmap.end();it++){
            if(mmap[make_pair(it->first.first,it->first.second)]==1&&mmap[make_pair(it->first.second,it->first.first)]==1){
                mmap2[it->first.first]=1;
                mmap2[it->first.second]=1;
				
            }
        }
        for(map<int,vector<int> >::iterator it=mmap3.begin();it!=mmap3.end();it++){
            if(!mmap2[it->first]){
                int c=0;
                for(int i=0;i<it->second.size();i++){
                    if(mmap2[it->second[i]]){
                        c++;
                    }
                }
                if(c>=2){
                    mmap2[it->first]=1;
                }
            }
        }
        vector<int> r;
        for(map<int,int>::iterator it=mmap2.begin();it!=mmap2.end();it++){
			if(it->second==1){
				r.push_back(it->first);
			}
        }
        sort(r.begin(),r.end());
		cout<<r.size()<<endl;
        for(int i=0;i<r.size();i++){
            cout<<r[i];
            if(i!=r.size()-1){
                cout<<" ";
            }
        }
		if(r.size()!=0){
			cout<<endl;
		}
	}
	return 0;
}
