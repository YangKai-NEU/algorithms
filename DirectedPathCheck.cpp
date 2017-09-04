/*
��Ŀ����
����һ������ͼ����ʵ��һ���㷨���ҳ�����֮���Ƿ����һ��·����
����ͼ�е���������ָ��UndirectedGraphNode* a,UndirectedGraphNode* b(�벻Ҫ�����������ͣ�ͼ������ͼ),�뷵��һ��bool����������֮���Ƿ����һ��·��(a��b��b��a)��
*/

#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

class Path {
public:
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        // write code here
		queue<UndirectedGraphNode*> mqueue;
		map<int,int> mmap;
		mqueue.push(a);
		mmap[a->label]=1;
		while(!mqueue.empty()){
			UndirectedGraphNode *top=mqueue.front();
			mqueue.pop();
			if(top->label==b->label){
				return true;
			}
			for(int i=0;i<top->neighbors.size();i++){
				if(!mmap[top->neighbors[i]->label]){
					mqueue.push(top->neighbors[i]);
					mmap[top->neighbors[i]->label]=1;
				}
			}
		}
		mmap.erase(mmap.begin(),mmap.end());
		mqueue.push(b);
		mmap[b->label]=1;
		while(!mqueue.empty()){
			UndirectedGraphNode *top=mqueue.front();
			mqueue.pop();
			if(top->label==a->label){
				return true;
			}
			for(int i=0;i<top->neighbors.size();i++){
				if(!mmap[top->neighbors[i]->label]){
					mqueue.push(top->neighbors[i]);
					mmap[top->neighbors[i]->label]=1;
				}
			}
		}
		return false;
    }
};

int main(int argc, char *argv[])
{
	UndirectedGraphNode *a1=new UndirectedGraphNode(12);
	UndirectedGraphNode *a2=new UndirectedGraphNode(22);

	a1->neighbors.push_back(a2);

	Path p;
	cout<<p.checkPath(a1,a2)<<endl;
	
	return 0;
}
