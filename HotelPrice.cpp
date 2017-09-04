/*
题目描述
酒店房间的价格录入是通过时间段来录入的，比如10月1日至10月7日800元，10月8日至10月20日500元，请实现以下函数int[][] merge(int[][] dateRangePrices)，输入是某个酒店多个日期段的价格，每个日期段（终止日期大于等于起始日期）和对应的价格使用长度为3的数组来表示，比如[0, 19, 300], [10, 40, 250]分别表示从某天开始第1天到第20天价格都是300，第11天到第41天价格都是250，这些日期端有可能重复，重复的日期的价格以后面的为准， 请以以下规则合并并输出合并结果：
1.相邻两天的价格如果相同，那么这两个日期段应该合并
2.合并的结果应该以起始日期从小到大排序
输入描述:
输入数据包括多行，如样例输入所示。
输出描述:
输出数据为一行，如样例输出所示
示例1
输入

1 1 100
2 3 100
4 5 110
输出

[1, 3, 100],[4, 5, 110]
*/

#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
	int a,b,c;
	map<int,int> mmap;
	while(cin>>a>>b>>c){
		for(int i=a;i<=b;i++){
			mmap[i]=c;
		}
	}
	vector<pair<int,int> >  s;
	for(map<int,int>::iterator it=mmap.begin();it!=mmap.end();it++){
		s.push_back(make_pair(it->first,it->second));
	}
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size()-1-i;j++){
			if(s[j+1].first<s[j].first){
				pair<int,int> t=s[j+1];
				s[j+1]=s[j];
				s[j]=t;
			}
		}
	}

	int pre=s[0].second;
	int prepos=s[0].first;
	int cc=0;
	for(int i=1;i<s.size();i++){
		if(pre==s[i].second){
			continue;
		}
		if(cc++==0){
			cout<<"["<<prepos<<", "<<s[i-1].first<<", "<<pre<<"]";
			pre=s[i].second;
			prepos=s[i].first;
		}else{
            cout<<",["<<prepos<<", "<<s[i-1].first<<", "<<pre<<"]";
			pre=s[i].second;
			prepos=s[i].first;
        }
	}
	if(cc++==0){
		cout<<"["<<prepos<<", "<<s[s.size()-1].first<<", "<<pre<<"]";
	}else{
        cout<<",["<<prepos<<", "<<s[s.size()-1].first<<", "<<pre<<"]";
    }
	cout<<endl;
	
	return 0;
}
