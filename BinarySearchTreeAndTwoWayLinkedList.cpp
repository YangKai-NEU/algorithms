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

void print(TreeNode *r){
	TreeNode *tmp=r;
	while(tmp){
		cout<<tmp->val<<" ";
		tmp=tmp->right;
	}
	cout<<endl;
}

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree){
			return NULL;
		}
		TreeNode *mid=pRootOfTree;
		TreeNode *result=mid;
		TreeNode *ml=mid->left;
		TreeNode *mr=mid->right;
		result->left=NULL;
		result->right=NULL;
		if(ml){
			TreeNode *l=Convert(ml);
			result=l;
			while(l->right){
				l=l->right;
			}
			l->right=mid;
			mid->left=l;
		}
		if(mr){
			TreeNode *r=Convert(mr);
			TreeNode *t=result;
			while(t->right){
				t=t->right;
			}
			t->right=r;
			r->left=t;
		}
		return result;
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
	TreeNode *r=solution.Convert(r1);

	print(r);
}
