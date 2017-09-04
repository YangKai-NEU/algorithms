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
        int tmp;
		while(!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
		tmp=stack2.top();
		stack2.pop();
		while(!stack2.empty()){
			stack1.push(stack2.top());
			stack2.pop();
		}
		return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, char *argv[])
{
	Solution s;
	s.push(12);
	s.push(122);
	s.push(19);

	cout<<s.pop()<<endl;
	
	return 0;
}
