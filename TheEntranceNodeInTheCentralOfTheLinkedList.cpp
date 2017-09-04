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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		if(!pHead||!pHead->next||!pHead->next->next){
			return NULL;
		}
		ListNode *t1=pHead->next;
		ListNode *t2=pHead->next->next;
		while(t1&&t1!=t2){
			t1=t1->next;
			t2=t2->next->next;
		}
		ListNode *t3=pHead;
		while(t2&&t2!=t3){
			t2=t2->next;
			t3=t3->next;
		}
		return t3;

    }
};

int main(int argc, char *argv[])
{
	ListNode *t1=new ListNode(1);
	ListNode *t2=new ListNode(2);
	ListNode *t3=new ListNode(3);
	ListNode *t4=new ListNode(4);
	ListNode *t5=new ListNode(5);
	
	t1->next=t2;
	t2->next=t3;
	t3->next=t4;
	t4->next=t5;
	t5->next=t3;

	Solution solution;
	cout<<solution.EntryNodeOfLoop(t1)->val<<endl;

	return 0;
}
