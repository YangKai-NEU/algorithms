#include <iostream>
#include <string>
using namespace std;

class KeywordDetect {
public:
    vector<int> containKeyword(vector<string> A, int n, vector<string> keys, int m) {
        // write code here
		vector<int> r;
        int j=0;
        int i=0;
        for(;j<n;j++){
			for(int i=0;i<m;i++){
				if(A[j].find(keys[i],0)!=A[j].npos){
					r.push_back(j);
                    break;
				}
			}
		}
        if(r.size()==0){
            r.push_back(-1);
        }
		return r;
    }
};

int main(int argc, char *argv[])
{
	KeywordDetect k;

	
	return 0;
}
