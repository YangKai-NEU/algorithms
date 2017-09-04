/*
��Ŀ����
����һ�� n �� m �еĵ��Σ����� '.' ��ʾ����ͨ�е�λ�ã�'X' ��ʾ����ͨ�е��ϰ���ţţ�� (x0 , y0 ) λ�ó���������������Σ���һ�����Ϸ����ͬ���ǣ���ÿһ��ֻ�ܰ���һЩָ���Ĳ����������Σ�Ҫ��ÿһ���������Գ������εı߽磬Ҳ���ܵ����ϰ��ϡ����εĳ��ڿ���������ĳ������ͨ�е�λ���ϡ�ţţ��֪�������£�����Ҫ���ٲ��ſ����뿪������Ρ�
��������:
ÿ��������� 1 ������������ÿ�����������ĵ�һ�а����������� n �� m��1 <= n, m <= 50������ʾ���εĳ��Ϳ��������� n �У�ÿ�� m ���ַ����������Σ����ν����ٰ������� '.'����������һ�У������������� x0, y0����ʾţţ�ĳ���λ�ã�0 <= x0 < n, 0 <= y0 < m�����Ͻǵ�����Ϊ ��0, 0��������λ��һ���� '.'����֮���һ�а���һ������ k��0 < k <= 50����ʾţţ�Ϸ��Ĳ��������������� k �У�ÿ���������� dx, dy ��ʾÿ�ο�ѡ���ƶ����к��в�����-50 <= dx, dy <= 50��
�������:
���һ��һ�����ֱ�ʾ��������Ҫ���ٴ��ƶ������뿪���Σ������Զ�޷��뿪����� -1�����²��������У�ţţ�������������ƶ��������п�ͨ�е�λ��.�ϣ����γ�����������������½ǣ�ţţ���뿪��Ҫ�ƶ��Ĵ�����࣬Ϊ3�Ρ�
ʾ��1
����

3 3
...
...
...
0 1
4
1 0
0 1
-1 0
0 -1
���

3
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int result=-1;

int process(vector<string> &s,int x,int y,vector<pair<int,int> > &ss){
    int n=s.size();
    int m=s[0].length();
    vector<vector<bool> > v(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j]=false;
        }
    }
    int r=0;
    v[x][y]=true;
    r++;
	int c=0;
	queue<pair<pair<int,int>,int> > mqueue;
	mqueue.push(make_pair(make_pair(x,y),0));
	while(!mqueue.empty()){
		pair<pair<int,int>,int> top=mqueue.front();
        mqueue.pop();
		result=result<top.second?top.second:result;
		for(int i=0;i<ss.size();i++){
			int px=top.first.first+ss[i].first;
			int py=top.first.second+ss[i].second;
			if(px>=0&&px<s.size()&&py>=0&&py<s[0].size()&&s[px][py]=='.'&&!v[px][py]){
				v[px][py]=true;
                r++;
				mqueue.push(make_pair(make_pair(px,py),top.second+1));
			}
		}
	}
    return r;
}

int main(int argc, char *argv[])
{
	int n,m;
	cin>>n>>m;
	vector<string> s;
	int p=0;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		s.push_back(t);
        for(int j=0;j<t.length();j++){
            if(t[j]=='.'){
                p++;
            }
        }
	}
	int sx,sy;
	cin>>sx>>sy;
	int sc;
	cin>>sc;
	vector<pair<int,int> > ss;
	for(int i=0;i<sc;i++){
		int x,y;
		cin>>x>>y;
		ss.push_back(make_pair(x,y));
	}
	int t=process(s,sx,sy,ss);
    if(t!=p){
        result=-1;
    }
    cout<<result<<endl;
	return 0;
}
