/*
��Ŀ����
��MIUI8�Ƴ��ֻ�������֮��MIUI9�ƻ��Ƴ�һ���绰�������Ĺ��ܣ����Ƚ��绰�����е�ÿ�����ּ���8ȡ��λ��Ȼ��ʹ�ö�Ӧ�Ĵ�д��ĸ���� ��"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"���� Ȼ�����������Щ��ĸ�������ɵ��ַ�����Ϊ�绰�����Ӧ�ķ���
��������:
��һ����һ������T��1 �� T �� 100)��ʾ������������������T�У�ÿ�и���һ�������ĵ绰����ķ���������3��10000֮�䣩��
�������:
���T�У��ֱ��Ӧ������ÿ���ַ�����Ӧ�ķ���ǰ����С�绰���루����ǰ��0����
ʾ��1
����

4
EIGHT
ZEROTWOONE
OHWETENRTEO
OHEWTIEGTHENRTEO
���

0
234
345
0345
*/

#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int cor(int x){
    if(x>=8){
        return x-8;
    }else{
        return x+10-8;
    }
}

void spl(string s,vector<int> &result){
	string a[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	int c[26]={0};
	for(int i=0;i<s.length();i++){
		c[s[i]-'A']++;
	}
	int b[10]={0};
	b[0]=c['Z'-'A'];
	b[6]=c['X'-'A'];
	b[2]=c['W'-'A'];
	b[4]=c['U'-'A'];
	b[5]=c['F'-'A']-b[4];
	b[7]=c['V'-'A']-b[5];
	b[8]=c['G'-'A'];
	b[3]=c['T'-'A']-b[2]-b[8];
	b[9]=c['I'-'A']-b[5]-b[6]-b[8];
	b[1]=c['N'-'A']-b[7]-2*b[9];
    int r[10]={0};
    for(int i=0;i<10;i++){
        r[cor(i)]=b[i];
    }
	for(int i=0;i<10;i++){
		for(int j=0;j<r[i];j++){
			result.push_back(i);
		}	
	}
}

string f(string s){
	vector<int> t;
    spl(s,t);
	//cout<<t.size()<<endl;
	sort(t.begin(),t.end());
	char a[10000]={'\0'};
	for(int i=0;i<t.size();i++){
		sprintf(a,"%s%d",a,t[i]);
	}
	string b=a;
	return b;
}

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
    vector<string> s;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
        s.push_back(t);
	}
    for(int i=0;i<s.size();i++){
        cout<<f(s[i])<<endl;
    }
	
	return 0;
}
