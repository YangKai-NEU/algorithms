#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class TreeLevel {
public:
	ListNode *result;
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        // write code here
		ListNode *result=NULL;
		ListNode *pre=NULL;
		queue<pair<TreeNode*,int> > mqueue;
		mqueue.push(make_pair(root,1));
		while(!mqueue.empty()){
			pair<TreeNode*,int> top=mqueue.front();
			mqueue.pop();
			if(top.second==dep){
				if(!result){
					result=new ListNode(top.first->val);
					pre=result;
				}else{
					pre->next=new ListNode(top.first->val);
					pre=pre->next;
				}
			}
			if(top.second<dep){
				if(top.first->left){
					mqueue.push(make_pair(top.first->left,top.second+1));
				}
				if(top.first->right){
					mqueue.push(make_pair(top.first->right,top.second+1));
				}
			}
		}
		return result;
    }
};

int main(int argc, char *argv[])
{
	TreeNode *r1;
	r1=new TreeNode(1);
	r1->left=new TreeNode(2);
	r1->right=new TreeNode(3);
	r1->left->left=new TreeNode(4);
	r1->left->right=new TreeNode(5);
	r1->right->left=new TreeNode(6);
	r1->right->right=new TreeNode(7);

	TreeLevel t;
	ListNode *r=t.getTreeLevel(r1,3);
	while(r){
		cout<<r->val<<" ";
		r=r->next;
	}
	cout<<endl;
	
	return 0;
}
