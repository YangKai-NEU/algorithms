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
    ListNode* deleteDuplication(ListNode* pHead)
    {
		ListNode *result=NULL,*t=NULL;
		ListNode *tmp=pHead;
		ListNode *pre=NULL;
		int prec=0;
		if(!tmp){
			return result;
		}
		while(tmp){
			if(!pre){
				pre=tmp;
				prec=1;
			}else{
				
				if(tmp->val!=pre->val){
					if(!result){
						if(prec==1){
							result=pre;
							t=result;
							t->next=NULL;
						}
					}else{
						if(prec==1){
							t->next=pre;
							t=t->next;
							t->next=NULL;
						}
					}
					pre=tmp;
					prec=1;
				}else{
					prec++;
				}
			}
			tmp=tmp->next;
		}
		if(!result){
            if(prec==1){
                result=pre;
				result->next=NULL;
            }
        }else{
            if(prec==1){
                t->next=pre;
				t=t->next;
				t->next=NULL;
            }
        }
		return result;
    }
};

int main(int argc, char *argv[])
{
	ListNode *t1=new ListNode(1);
	ListNode *t2=new ListNode(1);
	ListNode *t3=new ListNode(2);
	ListNode *t4=new ListNode(4);
	ListNode *t5=new ListNode(5);
	ListNode *t6=new ListNode(5);

	t1->next=t2;
	t2->next=t3;
	t3->next=t4;
	t4->next=t5;
	t5->next=t6;

	Solution solution;
	ListNode *t=solution.deleteDuplication(t1);
	while(t){
		cout<<t->val<<" ";
		t=t->next;
	}
	return 0;
}
