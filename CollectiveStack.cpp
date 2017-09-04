#include <vector>
#include <iostream>
using namespace std;

class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
        // write code here
		vector<vector<int> > s;
		for(int i=0;i<ope.size();i++){
			if(ope[i][0]==1){
				if(s.size()==0||s[s.size()-1].size()==size){
					 vector<int> t;
					 t.push_back(ope[i][1]);
					 s.push_back(t);
				}else{
					s[s.size()-1].push_back(ope[i][1]);
				}
			}else{
				s[s.size()-1].pop_back();
				if(s[s.size()-1].size()==0){
					s.pop_back();
				}
			}
		}
		return s;
     }
};

int main(int argc, char *argv[])
{
	SetOfStacks s;
	vector<vector<int> > o;
	int a[]={1,1,1,1,1,2,2,2,1,1,1,1,1,1,2};
	int b[]={2,3,4,5,6,1,1,5,3,2,2,1,4,2,3};

	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		vector<int> tmp;
		tmp.push_back(a[i]);
		tmp.push_back(b[i]);
		o.push_back(tmp);
	}

	vector<vector<int> > r=s.setOfStacks(o,4);

	for(int i=0;i<r.size();i++){
		for(int j=0;j<r[i].size();j++){
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
