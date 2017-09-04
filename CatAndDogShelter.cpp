#include <vector>
#include <iostream>
using namespace std;

class CatDogAsylum {
public:
    vector<int> asylum(vector<vector<int> > ope) {
        vector<int> s;
		vector<int> r;
		for(int i=0;i<ope.size();i++){
			if(ope[i][0]==1){
				s.push_back(ope[i][1]);
			}else if(ope[i][0]==2){
				if(ope[i][1]==0){
					if(s.size()!=0){
						r.push_back(s[0]);
						s.erase(s.begin());
					}
				}else if(ope[i][1]==1){
					for(int j=0;j<s.size();j++){
						if(s[j]>0){
							r.push_back(s[j]);
                            s.erase(s.begin()+j);
							break;
						}
					}
				}else if(ope[i][1]==-1){
					for(int j=0;j<s.size();j++){
						if(s[j]<0){
							r.push_back(s[j]);
                            s.erase(s.begin()+j);
							break;
						}
					}
				}
			}
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	vector<vector<int> > s;
	int a[]={1,1,2,2};
	int b[]={1,-1,0,-1};
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		vector<int> tmp;
		tmp.push_back(a[i]);
		tmp.push_back(b[i]);
		s.push_back(tmp);
	}
	CatDogAsylum c;
	vector<int> r=c.asylum(s);
	for(int i=0;i<r.size();i++){
		cout<<r[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
