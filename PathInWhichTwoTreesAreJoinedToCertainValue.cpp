#include <iostream>
#include <stack>
#include <vector>
#include <map>
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		stack<vector<TreeNode*> > mstack;
		vector<vector<int> > r;
		if(!root){
			return r;
		}
		vector<TreeNode*> t;
		map<TreeNode*,int> mmap;
		t.push_back(root);
		mstack.push(t);
		mmap[root]=1;
		while(!mstack.empty()){
			vector<TreeNode*> top=mstack.top();
			
			if(!top[top.size()-1]->left&&!top[top.size()-1]->right){
				int c=0;
				for(int i=0;i<top.size();i++){
					c+=top[i]->val;
				}
				if(c==expectNumber){
					vector<int> tmp;
					for(int i=0;i<top.size();i++){
						tmp.push_back(top[i]->val);
					}
					r.push_back(tmp);
				}
				mstack.pop();
				continue;
			}
			if(top[top.size()-1]->left&&!mmap[top[top.size()-1]->left]){
				//cout<<"here1"<<endl;
				mmap[top[top.size()-1]->left]=1;
				vector<TreeNode*> l(top);
				l.push_back(top[top.size()-1]->left);
				mstack.push(l);
			}else if(top[top.size()-1]->right&&!mmap[top[top.size()-1]->right]){
				//cout<<"here2"<<endl;
				mmap[top[top.size()-1]->right]=1;
				vector<TreeNode*> r(top);
				r.push_back(top[top.size()-1]->right);
				mstack.push(r);
			}else{
				mstack.pop();
			}
		}
		return r;
    }
};

int main(int argc, char *argv[])
{
	TreeNode *r1;
	r1=new TreeNode(10);
	r1->left=new TreeNode(5);
	r1->right=new TreeNode(12);
	r1->left->left=new TreeNode(4);
	r1->left->right=new TreeNode(7);

	Solution s;
	vector<vector<int> > r=s.FindPath(r1,22);

	for(int i=0;i<r.size();i++){
		for(int j=0;j<r[i].size();j++){
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
