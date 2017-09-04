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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *result=NULL,*tmp;
		ListNode *tmp1=pHead1,*tmp2=pHead2;
		while(tmp1&&tmp2){
			if(tmp1->val<tmp2->val){
				if(!result){
					result=tmp1;
					tmp=result;
					tmp1=tmp1->next;
					result->next=NULL;
				}else{
					tmp->next=tmp1;
					tmp=tmp->next;
					tmp1=tmp1->next;
					tmp->next=NULL;
				}
			}else{
				if(!result){
					result=tmp2;
					tmp=result;
					tmp2=tmp2->next;
					result->next=NULL;
				}else{
					tmp->next=tmp2;
					tmp=tmp->next;
					tmp2=tmp2->next;
					tmp->next=NULL;
				}
			}
		}
		if(tmp1){
            if(!result){
                result=tmp1;
            }else{
                tmp->next=tmp1;
            }
        }else{
            if(!result){
                result=tmp2;
            }else{
                tmp->next=tmp2;
            }
        }
		return result;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	ListNode *s1,*s2;
	s1=new ListNode(12);
	s1->next=new ListNode(23);
	s1->next->next=new ListNode(32);

	s2=new ListNode(21);
	s2->next=new ListNode(28);
	s2->next->next=new ListNode(200);

	ListNode* t=solution.Merge(s1,s2);
	while(t){
		cout<<t->val<<" ";
		t=t->next;
	}
	cout<<endl;
	
	return 0;
}
