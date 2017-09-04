#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x), next(NULL) {
	}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;
		ListNode *tmp=head;
		while(tmp){
			result.push_back(tmp->val);
			tmp=tmp->next;
		}
		reverse(result.begin(),result.end());
		return result;
    }
};

int main(int argc, char *argv[])
{
	ListNode *t=new ListNode(12);
	t->next=new ListNode(42);
	t->next->next=new ListNode(56);
	Solution solution;
	vector<int> result=solution.printListFromTailToHead(t);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
