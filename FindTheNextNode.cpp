/*
��Ŀ����
�����һ���㷨��Ѱ�Ҷ�������ָ��������һ����㣨����������ĺ�̣���
�������ĸ����ָ��TreeNode* root�ͽ���ֵint p���뷵��ֵΪp�Ľ��ĺ�̽���ֵ����֤����ֵ���ڵ�����С�ڵ���100000��û���ظ�ֵ���������ں�̷���-1��
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Successor {
public:
    int findSucc(TreeNode* root, int p) {
        // write code here
		vector<int> t;
		int r=search(root,t,p);
		if(r==t.size()-1){
			return -1;
		}else{
			return t[r+1];
		}
    }

	int search(TreeNode* root,vector<int> &v,int p){
		int r=0;
		if(root->left){
			int a=search(root->left,v,p);
			r=r|a;
		}
		v.push_back(root->val);
		if(root->val==p){
			r=r|(v.size()-1);
		}
		if(root->right){
			int b=search(root->right,v,p);
			r=r|b;
		}
		return r;
	}
};

int main(int argc, char *argv[])
{
	Successor s;
	TreeNode *r1;
	r1=new TreeNode(1);
	r1->left=new TreeNode(2);
	r1->right=new TreeNode(3);
	r1->left->left=new TreeNode(4);
	r1->left->right=new TreeNode(5);
	r1->right->left=new TreeNode(6);
	r1->right->right=new TreeNode(7);
	cout<<s.findSucc(r1,4)<<endl;
	
	return 0;
}
