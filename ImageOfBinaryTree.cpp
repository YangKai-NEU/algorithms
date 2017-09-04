#include <iostream>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
		if(!pRoot){
			return;
		}
		TreeNode *tmp=pRoot->left;
		pRoot->left=pRoot->right;
		pRoot->right=tmp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
    }
};

void print(TreeNode *r){
	if(!r){
		return;
	}
	cout<<r->val<<" ";
	print(r->left);
	print(r->right);
}

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

	Solution solution;
	solution.Mirror(r1);

	print(r1);

	return 0;
}
