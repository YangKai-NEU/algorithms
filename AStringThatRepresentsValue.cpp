#include <iostream>
#include <string>
#include <map>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isNumeric(char* s)
    {
		map<char,int> mmap;
		string ns="1234567890-+eE.";
		for(int i=0;i<ns.length();i++){
			mmap[ns[i]]=1;
		}
		int ecount=0,xcount=0;
		int len=strlen(s);
        for(int i=0;i<len;i++){
			if(s[i]=='e'||s[i]=='E'){
				ecount++;
			}
			if(s[i]=='.'){
				xcount++;
			}
			if(!mmap[s[i]]){
				return false;
			}
		}
		if(ecount>=2||xcount>=2){
			return false;
		}
		bool press=true;
		bool latss=true;
		string pre="",lat="";
		string presub="";
		bool ss=false,pres=false;
		int l=0,r=0;
		for(int i=0;i<len;i++){
			if(s[i]=='e'||s[i]=='E'){
				ss=true;
			}else if(s[i]=='.'&&!ss){
				pres=true;
			}else if(s[i]=='.'&&ss){
				return false;
			}else if(s[i]=='+'){
				if(!ss){
					l++;
				}else{
					r++;
				}
				if((!ss&&pre=="")||(ss&&lat=="")){
					continue;
				}
				if(!ss&&pre!=""){
					return false;
				}
			}else if(s[i]=='-'){
				if(!ss){
					l++;
				}else{
					r++;
				}
				if(!s){
					press=false;
				}else{
					latss=false;
				}
			}else if(s[i]>='0'&&s[i]<='9'){
				if(!ss){
					if(!pres){
						pre+=s[i];
					}else{
						pres+=s[i];
					}
				}else{
					lat+=s[i];
				}
			}
		}
		if(ss&&lat==""){
			return false;
		}
		if(l>=2||r>=2){
			return false;
		}
		return true;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	char a[]="12e";
	cout<<solution.isNumeric(a)<<endl;
	
	return 0;
}
