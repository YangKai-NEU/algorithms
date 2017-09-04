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
	bool check(TreeNode* left,TreeNode* right){
		if(left&&!right){
			return false;
		}	
		if(!left&&right){
			return false;
		}
		if(!left&&!right){
			return true;
		}
		if(left->val!=right->val){
			return false;
		}
		return check(left->left,right->right)&&check(left->right,right->left);
	}
    bool isSymmetrical(TreeNode* pRoot)
    {
    	if(!pRoot){
			return true;
		}
		return check(pRoot->left,pRoot->right);
    }
};

int main(int argc, char *argv[])
{
	TreeNode *r1;
	r1=new TreeNode(5);
	r1->left=new TreeNode(3);
	r1->right=new TreeNode(8);
	r1->left->left=new TreeNode(1);
	r1->left->right=new TreeNode(4);
	r1->right->left=new TreeNode(7);
	r1->right->right=new TreeNode(9);

	Solution solution;
	cout<<solution.isSymmetrical(r1)<<endl;
	
	return 0;
}
