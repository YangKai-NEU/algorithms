#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void push(int value) {
        data.push_back(value);
    }
    void pop() {
        data.pop_back();
    }
    int top() {
        return data[datasize()-1];
    }
    int min() {
		int v=10000;
        for(int i=0;i<data.size();i++){
			v=v<data[i]?v:data[i];
		}
		return v;
    }
	vector<int> data;
};

int main(int argc, char *argv[])
{
	Solution solution;
	solution.push(123);
	solution.push(34);
	solution.push(12);
	solution.push(3243);

	solution.pop();
	cout<<solution.min()<<endl;

	solution.pop();
	cout<<solution.min()<<endl;

	solution.pop();
	cout<<solution.min()<<endl;

	return 0;
}
