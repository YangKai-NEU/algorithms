/*
[�����] �򵥴����¼
ʱ�����ƣ�1��
�ռ����ƣ�65536K
����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš� 
����:
1.��¼���8�������¼������ͬ�Ĵ����¼(���ļ����ƺ��к���ȫƥ��)ֻ��¼һ��������������ӣ�(�ļ����ڵ�Ŀ¼��ͬ���ļ������к���ͬҲҪ�ϲ�)
2.����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���(����ļ�����ͬ����ֻ���ļ����ĺ�16���ַ����к���ͬ��Ҳ��Ҫ�ϲ�)
3.������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·��

��������:
һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������

    �ļ�·��Ϊwindows��ʽ

    �磺E:\V1R2\product\fpgadrive.c 1325


�������:
�����еļ�¼ͳ�Ʋ�������������ʽ���ļ�������������Ŀ��һ���ո��������: fpgadrive.c 1325 1 

    ���������Ŀ�Ӷൽ��������Ŀ��ͬ������£����������һ�γ���˳������

    �������8����¼����ֻ���ǰ8����¼.

    ����ļ����ĳ��ȳ���16���ַ�����ֻ�����16���ַ�

��������1:
E:\V1R2\product\fpgadrive.c 1325

�������1:
fpgadrive.c 1325 1
*/

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

string filename(string s){
	string r="";
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]!='\\'){
			r+=s[i];
		}else{
			break;
		}
	}
	reverse(r.begin(),r.end());
	return r;
}

string sub(string s){
	if(s.length()<=16){
		return s;
	}
	string a="";
	for(int i=s.length()-1;i>=0;i--){
		if(a.length()<16){
			a+=s[i];
		}
	}
	reverse(a.begin(),a.end());
	return a;
}

int main(int argc, char *argv[])
{
	string a;
	int b;
	vector<pair<string,int> > s;
	while(cin>>a>>b){
		s.push_back(make_pair(filename(a),b));
	}
	map<pair<string,int>,int> mmap;
	for(int i=0;i<s.size();i++){
		mmap[s[i]]++;
	}
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size()-1-i;j++){
			if(mmap[s[j+1]]>mmap[s[j]]){
				pair<string,int> t=s[j];
				s[j]=s[j+1];
				s[j+1]=t;
			}
		}
	}
    int cc=0;
	for(int i=0;i<s.size();i++){
		if(mmap[s[i]]){
			cout<<sub(s[i].first)<<" "<<s[i].second<<" "<<mmap[s[i]]<<endl;
            cc++;
            if(cc>=8){
                break;
            }
			mmap[s[i]]=0;
		}
	}
	
	return 0;
}
