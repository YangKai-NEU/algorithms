#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        // write code here
        ListNode *r=NULL;
		ListNode *t=NULL;
		int pre=0;
		while(a&&b){
			int tmp=a->val+b->val+pre;
			pre=tmp/10;
			tmp=tmp%10;
			if(!r){
				r=new ListNode(tmp);
				t=r;
			}else{
				t->next=new ListNode(tmp);
				t=t->next;
			}

			a=a->next;
			b=b->next;
		}

		while(a){
			int tmp=a->val+pre;
			pre=tmp/10;
			tmp=tmp%10;
			if(!r){
				r=new ListNode(tmp);
				t=r;
			}else{
				t->next=new ListNode(tmp);
				t=t->next;
			}

			a=a->next;
		}

		while(b){
			int tmp=b->val+pre;
			pre=tmp/10;
			tmp=tmp%10;
			if(!r){
				r=new ListNode(tmp);
				t=r;
			}else{
				t->next=new ListNode(tmp);
				t=t->next;
			}

			b=b->next;
		}

		if(pre!=0){
			if(!r){
				r=new ListNode(pre);
				t=r;
			}else{
				t->next=new ListNode(pre);
				t=t->next;
			}
		}

		return r;
    }
};

int main(int argc, char *argv[])
{
	ListNode *s1,*s2;
	s1=new ListNode(2);
	s1->next=new ListNode(3);
	s1->next->next=new ListNode(4);

	s2=new ListNode(1);
	s2->next=new ListNode(6);
	s2->next->next=new ListNode(4);

	Plus p;

	ListNode *s3=p.plusAB(s1,s2);
	while(s3){
		cout<<s3->val<<" ";
		s3=s3->next;
	}
	cout<<endl;
	
	return 0;
}
