/*
[�����] �˿��ƴ�С
ʱ�����ƣ�10��
�ռ����ƣ�131072K
�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������:) 
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER 
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո��磺4 4 4 4-joker JOKER
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR

��������
��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������

����ʾ��
��1������ը���Ͷ���֮�⣬��������ͬ���ͱȽϡ�
��2�������Ѿ���֤�Ϸ��ԣ����ü�������Ƿ��ǺϷ����ơ�
��3�������˳���Ѿ�������С����������˲�����������.

��������:
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո���4 4 4 4-joker JOKER��


�������:
����������нϴ�����֣��������ӷ����˿���˳�򲻱䣬���Կո��������������ڱȽϹ�ϵ�����ERROR��

��������1:
4 4 4 4-joker JOKER

�������1:
joker JOKER
*/

#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

string select(string s,int b){
	string a="";
	if(b){
		for(int i=0;i<s.length();i++){
			if(s[i]=='-'){
				break;
			}
			a+=s[i];
		}
	}else{
		for(int i=s.length()-1;i>=0;i--){
			if(s[i]=='-'){
				break;
			}
			a+=s[i];
		}
		reverse(a.begin(),a.end());
	}
	return a;
}

int c(vector<int> &a,vector<int> &b){
	if(a.size()==b.size()){
		return a[0]-b[0];
	}
	if(a[0]>15){
		return 1;
	}
	if(b[0]>15){
		return -1;
	}
	if(a.size()==4&&b.size()!=4){
		return 1;
	}
	if(a.size()!=4&&b.size()==4){
		return -1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	char aa[1000];
	string s;
	string str[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K","joker","JOKER"};
	int num[]={14,15,3,4,5,6,7,8,9,10,11,12,13,16,17};
	map<string,int> mmap;
	for(int i=0;i<15;i++){
		mmap[str[i]]=num[i];
	}
	while(gets(aa)){
		s=aa;
		vector<int> a,b;
		string pre="";
		bool state=false;
		for(int i=0;i<s.length();i++){
			if(s[i]==' '){
				if(!state){
					if(pre!=""){
						a.push_back(mmap[pre]);
					}
				}else{
					if(pre!=""){
						b.push_back(mmap[pre]);
					}
				}
				pre="";
			}else if(s[i]=='-'){
				if(!state){
					if(pre!=""){
						a.push_back(mmap[pre]);
					}
				}else{
					if(pre!=""){
						b.push_back(mmap[pre]);
					}
				}
				state=true;
				pre="";
			}else{
				pre+=s[i];
			}
		}
		if(!state){
			if(pre!=""){
				a.push_back(mmap[pre]);
			}
		}else{
			if(pre!=""){
				b.push_back(mmap[pre]);
			}
		}
		if(a.size()==0||b.size()==0){
			cout<<"ERROR"<<endl;
		}else{
			int tt=c(a,b);
			if(tt>0){
				cout<<select(s,true)<<endl;
			}else if(tt<0){
				cout<<select(s,false)<<endl;
			}else{
				cout<<"ERROR"<<endl;
			}
		}
	}
	
	return 0;
}
