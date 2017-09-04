/*
��Ŀ����
��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱䡣
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
		if(!pHead){
			return NULL;
		}
		ListNode *pre=NULL,*pret=NULL;
		ListNode *lat=NULL,*latt=NULL;
		ListNode *tmp=pHead;
		while(tmp){
			if(tmp->val<x){
				if(!pre){
					pre=tmp;
					pret=pre;
					tmp=tmp->next;
				}else{
					pret->next=tmp;
					pret=pret->next;
					tmp=tmp->next;
					pret->next=NULL;
				}
			}else{
				if(!lat){
					lat=tmp;
					latt=lat;
					tmp=tmp->next;
				}else{
					latt->next=tmp;
					latt=latt->next;
					tmp=tmp->next;
					latt->next=NULL;
				}
			}
		}
		if(pret){
			pret->next=lat;
		}else{
			return lat;
		}
		return pre;
    }
};

int main(int argc, char *argv[])
{
	Partition solution;
	ListNode *s1,*s2;
	s1=new ListNode(12);
	s1->next=new ListNode(32);
	s1->next->next=new ListNode(24);

	ListNode *r=solution.partition(s1,24);
	while(r){
		cout<<r->val<<" ";
		r=r->next;
	}
	cout<<endl;

	return 0;
}
