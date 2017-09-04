#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > r;
		queue<pair<TreeNode*,int> > mqueue;
		if(!pRoot){
			return r;
		}
		mqueue.push(make_pair(pRoot,1));
		vector<int> t;
		int p=1;
		while(!mqueue.empty()){
			pair<TreeNode*,int> top=mqueue.front();
			mqueue.pop();
			if(top.second==p){
				t.push_back(top.first->val);
			}else{
				p++;
				r.push_back(t);
				t.clear();
				t.push_back(top.first->val);
			}
			if(top.first->left){
				mqueue.push(make_pair(top.first->left,top.second+1));
			}
			if(top.first->right){
				mqueue.push(make_pair(top.first->right,top.second+1));
			}
		}
		r.push_back(t);
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
	vector<vector<int> > s=solution.Print(r1);

	for(int i=0;i<s.size();i++){
		for(int j=0;j<s[i].size();j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
