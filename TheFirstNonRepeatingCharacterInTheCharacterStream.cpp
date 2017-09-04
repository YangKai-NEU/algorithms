#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    
    string s;
  //Insert one char from stringstream
    void Insert(char ch)
    {
         s+=ch;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
		map<char,int> mmap;
		for(int i=0;i<s.length();i++){
			mmap[s[i]]++;
		}
		for(int i=0;i<s.length();i++){
			if(mmap[s[i]]==1){
				return s[i];
			}
		}
		return '#';
    }

};

int main(int argc, char *argv[])
{
	Solution solution;
	solution.Insert('2');
	cout<<solution.FirstAppearingOnce()<<endl;

	solution.Insert('2');
	solution.Insert('3');
	cout<<solution.FirstAppearingOnce()<<endl;

	solution.Insert('4');
	solution.Insert('4');
	solution.Insert('5');
	cout<<solution.FirstAppearingOnce()<<endl;
	
	return 0;
}
