/*
题目描述
请实现一个函数，检查一棵二叉树是否为二叉查找树。
给定树的根结点指针TreeNode* root，请返回一个bool，代表该树是否为二叉查找树。
*/

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

class Checker {
public:
    bool checkBST(TreeNode* root) {
        // write code here
		if(!root){
			return true;
		}
		if(root->left){
			int t=maxtree(root->left);
			if(t>root->val){
				return false;
			}
		}
		if(root->right){
			int t=mintree(root->right);
			if(t<root->val){
				return false;
			}
		}
		return (root->left?checkBST(root->left):true)&&(root->right?checkBST(root->right):true);
    }

	int maxtree(TreeNode* root){
		if(!root->left&&!root->right){
			return root->val;
		}
		int l=-10000;
		int r=-10000;
		if(root->left){
			l=maxtree(root->left);
		}
		if(root->right){
			r=maxtree(root->right);
		}
		return max(max(root->val,l),r);
	}

	int mintree(TreeNode* root){
		if(!root->left&&!root->right){
			return root->val;
		}
		int l=10000;
		int r=10000;
		if(root->left){
			l=mintree(root->left);
		}
		if(root->right){
			r=mintree(root->right);
		}
		return min(min(root->val,l),r);
	}
};

int main(int argc, char *argv[])
{
	Checker c;
	TreeNode *r1;
	r1=new TreeNode(1);
	r1->left=new TreeNode(2);
	r1->right=new TreeNode(3);
	r1->left->left=new TreeNode(4);
	r1->left->right=new TreeNode(5);
	r1->right->left=new TreeNode(6);
	r1->right->right=new TreeNode(7);

	cout<<c.checkBST(r1)<<endl;
	
	return 0;
}
