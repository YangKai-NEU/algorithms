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

class Balance {
public:
    bool isBalance(TreeNode* root) {
        // write code here
		if(!root){
			return true;
		}
		int l=count(root->left);
		int r=count(root->right);
		int t=l-r<0?r-l:l-r;
		if(t>1){
			return false;
		}
		return isBalance(root->left)&&isBalance(root->right);
    }
	int count(TreeNode *r){
		if(!r){
			return 0;
		}
		return 1+max(count(r->left),count(r->right));
	}
};

int main(int argc, char *argv[])
{
	Balance b;
	TreeNode *r1;
	r1=new TreeNode(1);
	r1->left=new TreeNode(2);
	r1->right=new TreeNode(3);
	r1->left->left=new TreeNode(4);
	r1->left->right=new TreeNode(5);
	r1->right->left=new TreeNode(6);
	r1->right->right=new TreeNode(7);
	cout<<b.isBalance(r1)<<endl;
	
	return 0;
}
