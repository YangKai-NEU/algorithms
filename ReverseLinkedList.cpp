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
    ListNode* ReverseList(ListNode* pHead) {
		ListNode* r=NULL;
        ListNode* tmp=pHead;
        if(!tmp){
            return r;
        }
		r=tmp;
		tmp=tmp->next;
		r->next=NULL;
		while(tmp){
			ListNode* t=tmp;
			tmp=tmp->next;
			t->next=r;
			r=t;
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	ListNode* s=new ListNode(213);
	s->next=new ListNode(25);
	s->next->next=new ListNode(89);

	ListNode* t=solution.ReverseList(s);
	while(t){
		cout<<t->val<<" ";
		t=t->next;
	}
	cout<<endl;
	return 0;
}
