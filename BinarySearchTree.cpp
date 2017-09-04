#include <iostream>
using namespace std;

struct TreeNode{
public:
	TreeNode *left;
	TreeNode *right;
	int data;
	TreeNode(int x){
		this->data=x;
		this->left=NULL;
		this->right=NULL;
	}
};

class BunarySearchTree{
public:
	BunarySearchTree(){
		this->root=NULL;
	}
	void insert(int x){
		if(this->root==NULL){
			this->root=new TreeNode(x);
		}else{
			TreeNode *tmp=root;
			while(tmp){
				if(x<tmp->data){
					if(tmp->left){
						tmp=tmp->left;
					}else{
						tmp->left=new TreeNode(x);
						break;
					}
				}else{
					if(tmp->right){
						tmp=tmp->right;
					}else{
						tmp->right=new TreeNode(x);
						break;
					}
				}
			}
		}
	}
	TreeNode *search(int x){
		TreeNode *tmp=root;
		while(tmp){
			if(tmp->data==x){
				return tmp;
			}else{
				if(tmp->data>x){
					tmp=tmp->left;
				}else{
					tmp=tmp->right;
				}
			}
		}
		return tmp;
	}
	void remove(int x){
		TreeNode *tmp=root;
		TreeNode *pre=NULL;
		bool isleft=false;
		while(tmp){
			if(tmp->data==x){
				if(tmp->left==NULL){
					if(pre==NULL){
						root=tmp->right;
					}else{
						if(isleft){
							pre->left=tmp->right;
						}else{
							pre->right=tmp->right;
						}
					}
					return;
				}
				if(tmp->right==NULL){
					if(pre==NULL){
						root=tmp->left;
					}else{
						if(isleft){
							pre->left=tmp->left;
						}else{
							pre->right=tmp->left;
						}
					}
					return;
				}
				if(tmp->right->left){
					TreeNode *t=tmp->right->left;
					TreeNode *pret=tmp->right;
					while(t->left){
						t=t->left;
						pret=pret->left;
					}
					pret->left=t->right;
					t->left=tmp->left;
					t->right=tmp->right;
					if(isleft){
						pre->left=t;
					}else{
						pre->right=t;
					}
				}else{
					tmp->right->left=tmp->left;
					if(isleft){
						pre->left=tmp->right;
					}else{
						pre->right=tmp->right;
					}
				}
				break;
			}else if(tmp->data>x){
				pre=tmp;
				tmp=tmp->left;
				isleft=true;
			}else{
				pre=tmp;
				tmp=tmp->right;
				isleft=false;
			}
		}
	}
	int max(){
		TreeNode *tmp=root;
		while(tmp->right){
			tmp=tmp->right;
		}
		return tmp->data;
	}
	int min(){
		TreeNode *tmp=root;
		while(tmp->left){
			tmp=tmp->left;
		}
		return tmp->data;
	}
	void print(){
		display(root);
		cout<<endl;
	}
private:
	TreeNode *root;
	void display(TreeNode *root){
		if(!root){
			return;
		}
		display(root->left);
		cout<<root->data<<" ";
		display(root->right);
	}
};

int main(int argc, char *argv[])
{
	BunarySearchTree *tree=new BunarySearchTree();
	tree->insert(12);
	tree->insert(45);
	tree->insert(2);
	tree->insert(32);
	tree->insert(56);
	tree->insert(13);
	tree->insert(20);
	tree->print();

	TreeNode *r=tree->search(2);
	cout<<r->data<<endl;

	cout<<tree->max()<<endl;

	cout<<tree->min()<<endl;

	tree->remove(13);
	tree->print();

	return 0;
}
