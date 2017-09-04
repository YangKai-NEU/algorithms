#include <iostream>
#include <vector>
using namespace std;

const int ERROR=-1;

class Stack{
public:
	bool isEmpty(){
		return data.size()==0;
	}
	void push(int x){
		data.push_back(x);
	}
	int top(){
		if(this->isEmpty()){
			cout<<"stack is empty!"<<endl;
			return ERROR;
		}else{
			return data[data.size()-1];
		}
	}
	void pop(){
		if(this->isEmpty()){
			cout<<"stack is empty already!"<<endl;
		}else{
			data.pop_back();
		}
	}
private:
	vector<int> data;
};

int main(int argc, char *argv[])
{
	Stack stack;
	stack.push(12);
	stack.push(52);
	stack.push(92);
	cout<<stack.top()<<endl;
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	cout<<stack.isEmpty()<<endl;
	
	return 0;
}
