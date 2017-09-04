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
    int maxDepth(TreeNode *root) {
        if(!root){
			return 0;
		}
		if(root->left&&!root->right){
			return 1+maxDepth(root->left);
		}else if(!root->left&&root->right){
			return 1+maxDepth(root->right);
		}else{
			return 1+max(maxDepth(root->left),maxDepth(root->right));
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

	Solution s;
	cout<<s.maxDepth(r1)<<endl;
	return 0;
}
