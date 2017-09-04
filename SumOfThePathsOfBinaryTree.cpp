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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int> > result;
		if(!root){
			return result;
		}
		vector<TreeNode*> path;
		path.push_back(root);
		while(path.size()!=0){
			
			TreeNode *tmp=path[path.size()-1];
			if(!tmp->left&&!tmp->right){
				vector<int> t;
				int sum=0;
				for(int i=0;i<path.size();i++){
					t.push_back(path[i]->val);
					sum+=path[i]->val;
				}
				if(sum==expectNumber){
					result.push_back(t);
				}
				if(path.size()==1){
					break;
				}else{
					while(path.size()>=2){
						if(path[path.size()-2]->left==path[path.size()-1]){
							if(path[path.size()-2]->right){
								path.pop_back();
								path.push_back(path[path.size()-1]->right);
								break;
							}else{
								path.pop_back();
							}
						}else{
							path.pop_back();
						}
					}
					if(path.size()==1){
						path.pop_back();
					}
				}
			}else{
				if(tmp->left){
					path.push_back(tmp->left);
				}else if(tmp->right){
					path.push_back(tmp->right);
				}
			}
		}
		return result;
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
	vector<vector<int>/**/> r=solution.FindPath(r1,8);
	for(int i=0;i<r.size();i++){
		for(int j=0;j<r[i].size();j++){
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
