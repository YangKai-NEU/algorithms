#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
		int res=stack2.top();
		stack2.pop();
		while(!stack2.empty()){
			stack1.push(stack2.top());
			stack2.pop();
		}
		return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, char *argv[])
{
	Solution solution;
	solution.push(23);
	solution.push(233);
	solution.push(34);
	solution.push(73);
	cout<<solution.pop()<<endl;
	cout<<solution.pop()<<endl;
	
	return 0;
}
