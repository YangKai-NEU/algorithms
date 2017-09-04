#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* h, unsigned int k) {
		ListNode *t=h;
		while(t){
			if(count(t)==k){
				return t;
			}
			t=t->next;
		}
		return NULL;
    }

	int count(ListNode* s){
		if(!s->next){
			return 1;
		}
		return 1+count(s->next);
	}
};

int main(int argc, char *argv[])
{
	Solution solution;
	ListNode *s1;
	s1=new ListNode(12);
	s1->next=new ListNode(23);
	s1->next->next=new ListNode(32);
	s1->next->next->next=new ListNode(32);
	
	cout<<solution.FindKthToTail(s1,2)->val<<endl;

	return 0;
}
