#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		TreeNode* root=NULL;
		reConstructBinaryTree(pre,vin,root);
		return root;
    }

	void reConstructBinaryTree(vector<int> &pre,vector<int> &vin,TreeNode *&root){
		if(pre.size()==0){
			return;
		}
		int i;
		root=new TreeNode(pre[0]);
		vector<int> pre1,pre2,vin1,vin2;
		for(i=0;vin[i]!=pre[0];i++){
			vin1.push_back(vin[i]);
		}
		i++;
		for(;i<vin.size();i++){
			vin2.push_back(vin[i]);
		}
		for(i=1;;i++){
			if(pre1.size()==vin1.size()){
				break;
			}
			pre1.push_back(pre[i]);
		}
		for(;i<pre.size();i++){
			pre2.push_back(pre[i]);
		}
		reConstructBinaryTree(pre1,vin1,root->left);
		reConstructBinaryTree(pre2,vin2,root->right);
	} 

	void preOrder(TreeNode* root){
		if(!root){
			return;
		}
		cout<<root->val<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
	void midOrder(TreeNode* root){
		if(!root){
			return;
		}
		midOrder(root->left);
		cout<<root->val<<" ";
		midOrder(root->right);

	}
};

int main(int argc, char *argv[])
{
	int a[]={1,2,4,7,3,5,6,8};
	int b[]={4,7,2,1,5,3,8,6};
	vector<int> pre,vin;
	int n=8;
	for(int i=0;i<n;i++){
		pre.push_back(a[i]);
		vin.push_back(b[i]);
	}
	Solution solution;
	TreeNode* result=solution.reConstructBinaryTree(pre,vin);
	solution.preOrder(result);
	cout<<endl;
	solution.midOrder(result);
	cout<<endl;
	
	return 0;
}
