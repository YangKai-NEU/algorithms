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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		int total=0;
        if(pListHead==NULL||k==0){
            return NULL;
        }
		ListNode* tmp=pListHead;
		while(tmp){
			total++;
			tmp=tmp->next;
		}
		int aim=total-k;
        if(aim<0){
            return NULL;
        }
		tmp=pListHead;
		while(aim){
			tmp=tmp->next;
			aim--;
		}
		return tmp;
    }

};

int main(int argc, char *argv[])
{
	Solution solution;
	ListNode* s=new ListNode(213);
	s->next=new ListNode(25);
	s->next->next=new ListNode(89);

	cout<<solution.FindKthToTail(s,3)->val<<endl;
	
	return 0;
}
