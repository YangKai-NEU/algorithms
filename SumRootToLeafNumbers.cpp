#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        queue<pair<TreeNode*,int> > mqueue;
		int r=0;
		if(!root){
			return r;
		}
		mqueue.push(make_pair(root,root->val));
		while(!mqueue.empty()){
			pair<TreeNode*,int> top=mqueue.front();
			mqueue.pop();
			if(!top.first->left&&!top.first->right){
				r+=top.second;
			}
			if(top.first->left){
				mqueue.push(make_pair(top.first->left,top.second*10+top.first->left->val));
			}
			if(top.first->right){
				mqueue.push(make_pair(top.first->right,top.second*10+top.first->right->val));
			}
		}
		return r;
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
	cout<<s.sumNumbers(r1)<<endl;
	
	return 0;
}
