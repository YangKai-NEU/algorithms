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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *tmp=pHead1;
		while(tmp){
			ListNode *t=pHead2;
			while(t){
				if(t==tmp){
					return t;
				}
				t=t->next;
			}
			tmp=tmp->next;
		}
		return tmp;
    }
};

int main(int argc, char *argv[])
{
	ListNode *t1=new ListNode(1);
	ListNode *t2=new ListNode(2);
	ListNode *t3=new ListNode(3);
	ListNode *t4=new ListNode(4);
	ListNode *t5=new ListNode(5);
	ListNode *t6=new ListNode(6);
	
	t1->next=t2;
	t2->next=t3;
	t3->next=t4;

	t5->next=t3;
	t4->next=t6;

	Solution solution;
	cout<<solution.FindFirstCommonNode(t1,t5)->val<<endl;

	
	return 0;
}
