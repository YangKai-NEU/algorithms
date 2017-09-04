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
    TreeNode* KthNode(TreeNode* r, int k)
    {
		if(!r){
			return NULL;
		}
		int c1=count(r->left);
		if(c1==k-1){
			return r;
		}
		if(c1>=k){
			return KthNode(r->left,k);
		}else{
			return KthNode(r->right,k-c1-1);
		}
    }

    int count(TreeNode *r){
		if(!r){
			return 0;
		}
		return 1+count(r->left)+count(r->right);
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
	cout<<solution.KthNode(r1,3)->val<<endl;
	
	return 0;
}
