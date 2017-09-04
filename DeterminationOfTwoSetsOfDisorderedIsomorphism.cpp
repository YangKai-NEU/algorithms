#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Same {
public:
    bool checkSam(string stringA, string stringB) {
        // write code here
		sort(stringA.begin(),stringA.end());
		sort(stringB.begin(),stringB.end());
		return stringA==stringB;
    }
};

int main(int argc, char *argv[])
{
	Same s;
	string a="This is nowcoder";
	string b="is This nowcoder";
	cout<<s.checkSam(a,b)<<endl;
	
	return 0;
}
