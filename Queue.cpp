#include <iostream>
#include <vector>
using namespace std;

const int ERROR=-1;

class Queue{
public:
	bool isEmpty(){
		return data.size()==0;
	}
	void enqueue(int x){
		data.push_back(x);
	}
	void dequeue(){
		if(this->isEmpty()){
			cout<<"queue is empty alreaday!"<<endl;
		}else{
			data.erase(data.begin());
		}
	}
	int front(){
		if(this->isEmpty()){
			cout<<"queue is empty!"<<endl;
			return ERROR;
		}else{
			return data[0];
		}
	}
private:
	vector<int> data;
};

int main(int argc, char *argv[])
{
	Queue queue;
	queue.enqueue(2);
	queue.enqueue(22);
	queue.enqueue(2124);
	cout<<queue.front()<<endl;
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	cout<<queue.isEmpty()<<endl;

	return 0;
}
