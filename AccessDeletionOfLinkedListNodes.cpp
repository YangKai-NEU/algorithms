#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Remove {
public:
    bool removeNode(ListNode* pNode) {
        // write code here
		if(!pNode||!pNode->next){
			return false;
		}
		pNode->val=pNode->next->val;
		pNode->next=pNode->next->next;
		return true;
    }
};

int main(int argc, char *argv[])
{
	ListNode *s1,*s2;
	s1=new ListNode(12);
	s1->next=new ListNode(23);
	s1->next->next=new ListNode(32);
	Remove r;
	r.removeNode(s1->next);

	ListNode *t=s1;
	while(t){
		cout<<t->val<<" ";
		t=t->next;
	}
	cout<<endl;

	return 0;
}
