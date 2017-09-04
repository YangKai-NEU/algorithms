#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p&&!q){
			return true;
		}
		if(!p&&q){
			return false;
		}
		if(p&&!q){
			return false;
		}
		if(p->val==q->val){
			return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
		}else{
			return false;
		}
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

	TreeNode *r2;
	r2=new TreeNode(1);
	r2->left=new TreeNode(2);
	r2->right=new TreeNode(3);
	r2->left->left=new TreeNode(4);
	r2->left->right=new TreeNode(5);
	r2->right->left=new TreeNode(6);
	r2->right->right=new TreeNode(7);

	Solution s;
	cout<<s.isSameTree(r1,r2)<<endl;
	
	return 0;
}
