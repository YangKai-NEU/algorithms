#include <iostream>
using namespace std;


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
		TreeLinkNode *tmp=pNode;
        if(!tmp){
			return NULL;
		}
		if(tmp->right){
			tmp=tmp->right;
			while(tmp->left){
				tmp=tmp->left;
			}
			return tmp;
		}else if(tmp->next){
			while(tmp->next&&tmp->next->right==tmp){
				tmp=tmp->next;
			}
			if(tmp->next){
				return tmp->next;
			}else{
				return NULL;
			}
		}else {
			return NULL;
		}
    }
};

int main(int argc, char *argv[])
{
	TreeLinkNode *r1;
	r1=new TreeLinkNode(5);
	r1->left=new TreeLinkNode(3);
	r1->left->next=r1;
	r1->right=new TreeLinkNode(8);
	r1->right->next=r1;
	r1->left->left=new TreeLinkNode(1);
	r1->left->left->next=r1->left;
	r1->left->right=new TreeLinkNode(4);
	r1->left->right->next=r1->left;
	r1->right->left=new TreeLinkNode(7);
	r1->right->left->next=r1->right;
	r1->right->right=new TreeLinkNode(9);
	r1->right->right->next=r1->right;

	Solution solution;
	TreeLinkNode *r=solution.GetNext(r1->right->right);
	if(!r){
		cout<<"none"<<endl;
	}else{
		cout<<r->val<<endl;
	}

	return 0;
}
