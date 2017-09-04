/*
��Ŀ����
�Ƶ귿��ļ۸�¼����ͨ��ʱ�����¼��ģ�����10��1����10��7��800Ԫ��10��8����10��20��500Ԫ����ʵ�����º���int[][] merge(int[][] dateRangePrices)��������ĳ���Ƶ������ڶεļ۸�ÿ�����ڶΣ���ֹ���ڴ��ڵ�����ʼ���ڣ��Ͷ�Ӧ�ļ۸�ʹ�ó���Ϊ3����������ʾ������[0, 19, 300], [10, 40, 250]�ֱ��ʾ��ĳ�쿪ʼ��1�쵽��20��۸���300����11�쵽��41��۸���250����Щ���ڶ��п����ظ����ظ������ڵļ۸��Ժ����Ϊ׼�� �������¹���ϲ�������ϲ������
1.��������ļ۸������ͬ����ô���������ڶ�Ӧ�úϲ�
2.�ϲ��Ľ��Ӧ������ʼ���ڴ�С��������
��������:
�������ݰ������У�������������ʾ��
�������:
�������Ϊһ�У������������ʾ
ʾ��1
����

1 1 100
2 3 100
4 5 110
���

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
