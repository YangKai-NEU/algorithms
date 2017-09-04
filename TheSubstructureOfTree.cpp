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

class Solution {
public:
    bool HasSubtree(TreeNode* r1, TreeNode* r2)
    {
		if(!r2||!r1){
			return false;
		}
		queue<TreeNode*> mqueue;
		mqueue.push(r1);
		while(!mqueue.empty()){
			TreeNode* top=mqueue.front();
            mqueue.pop();
			if(top->val==r2->val){
				if(check(top,r2)){
					return true;
				}
			}
			if(top->left){
				mqueue.push(top->left);
			}
			if(top->right){
				mqueue.push(top->right);
			}
		}
        return false;
    }
	bool check(TreeNode* r1, TreeNode* r2){
		if(!r2){
			return true;
		}
		if(!r1||r1->val!=r2->val){
			return false;
		}
		return check(r1->left,r2->left)&&check(r1->right,r2->right);
	}
};

int main(int argc, char *argv[])
{
	TreeNode *r1,*r2;
	r1=new TreeNode(1);
	r1->left=new TreeNode(2);
	r1->right=new TreeNode(3);
	r1->left->left=new TreeNode(4);
	r1->left->right=new TreeNode(5);
	r1->right->left=new TreeNode(6);
	r1->right->right=new TreeNode(7);

	r2=new TreeNode(3);
	r2->left=new TreeNode(6);
	r2->right=new TreeNode(7);

	Solution solution;
	cout<<solution.HasSubtree(r1,r2)<<endl;
	
	return 0;
}
