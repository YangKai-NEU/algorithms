#include <iostream>
#include <vector>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		queue<TreeNode*> mqueue;
		vector<int> r;
		if(!root){
			return r;
		}
		mqueue.push(root);
		while(!mqueue.empty()){
			TreeNode* top=mqueue.front();
			mqueue.pop();
			r.push_back(top->val);
			if(top->left){
				mqueue.push(top->left);
			}
			if(top->right){
				mqueue.push(top->right);
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

	Solution solution;
	vector<int> r=solution.PrintFromTopToBottom(r1);
	for(int i=0;i<r.size();i++){
		cout<<r[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
