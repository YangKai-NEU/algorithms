#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
		if(!pHead){
			return NULL;
		} 
		RandomListNode *result=NULL,*tmp=NULL;
		RandomListNode *t=pHead;
		while(t){
			if(result==NULL){
				result=new RandomListNode(t->label);
				tmp=result;
			}else{
				tmp->next=new RandomListNode(t->label);
				tmp=tmp->next;
			}
			t=t->next;
		}
		tmp=result;
		t=pHead;
		while(t){
			if(t->random){
				RandomListNode *t1=result;
				RandomListNode *t2=pHead;
				while(t2!=t->random){
					t1=t1->next;
					t2=t2->next;
				}
				tmp->random=t2;
			}
			t=t->next;
			tmp=tmp->next;
		}
		return result;
    }
};

int main(int argc, char *argv[])
{
	Solution solution;
	RandomListNode *a=NULL;
	RandomListNode *r=solution.Clone(a);

	
	return 0;
}
