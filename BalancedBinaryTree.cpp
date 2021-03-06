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
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(!pRoot){
			return true;
		}
		int a=TreeDepth(pRoot->left);
		int b=TreeDepth(pRoot->right);
		int sub=a-b>=0?a-b:b-a;
		if(sub>1){
			return false;
		}
		return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }

	int TreeDepth(TreeNode* pRoot)
    {
    	if(!pRoot){
			return 0;
		}
		if(!pRoot->left&&!pRoot->right){
			return 1;
		}
		return 1+max(TreeDepth(pRoot->left),TreeDepth(pRoot->right));
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

	Solution solution;

	cout<<solution.IsBalanced_Solution(r1)<<endl;
	
	return 0;
}
