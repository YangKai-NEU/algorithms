/*
[编程题] 火眼金睛
时间限制：1秒
空间限制：32768K
现在我们需要查出一些作弊的问答社区中的ID，作弊有两种：1.A回答了B的问题，同时B回答了A的问题。那么A和B都是作弊。2.作弊ID用户A和作弊ID用户B同时回答了C的问题，那么C也是作弊。已知每个用户的ID是一串数字，一个问题可能有多个人回答。

输入描述:
每组数据第一行为总问题数N(N小于等于200000)，第二行开始每行一个问题，第一个数字为提问人ID，第二个数字为回答人数，后面则为所有回答人的ID。(ID均为0-1000000的整数)


输出描述:
第一行为作弊ID数量，第二行开始为从小到大的每行一个作弊ID。

输入例子1:
3
1 1 2
2 1 1
3 2 1 2

输出例子1:
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
