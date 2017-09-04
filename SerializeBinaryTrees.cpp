#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
    char* Serialize(TreeNode *root) {    
        char *r=new char[10000];
		for(int i=0;i<10000;i++){
			r[i]='\0';
		}
		queue<pair<TreeNode*,int> > mqueue;
		if(!root){
			return r;
		}
		mqueue.push(make_pair(root,1));
		while(!mqueue.empty()){
			pair<TreeNode*,int> top=mqueue.front();
			mqueue.pop();
			if(strlen(r)==0){
				sprintf(r,"%d %d",top.first->val,top.second);
			}else{
				sprintf(r,"%s %d %d",r,top.first->val,top.second);
			}
			if(top.first->left){
				mqueue.push(make_pair(top.first->left,top.second*2));
			}
			if(top.first->right){
				mqueue.push(make_pair(top.first->right,top.second*2+1));
			}
		}
		return r;
    }
    TreeNode* Deserialize(char *str) {
		vector<int> s;
		int pre=0;
		bool state=false;
		for(int i=0;i<strlen(str);i++){
			if(str[i]==' '){
				if(state){
					s.push_back(pre);
					pre=0;
					state=false;
				}
			}else{
				pre*=10;
				pre+=(str[i]-'0');
				state=true;
			}
		}
		if(state){
			s.push_back(pre);
		}
		
		TreeNode *result=NULL;
		for(int i=0;i<s.size();i+=2){
			if(!result){
				result=new TreeNode(-1);
			}
			vector<int> tpre;
			while(s[i+1]!=0){
				tpre.push_back(s[i+1]);
				s[i+1]/=2;
			}
			reverse(tpre.begin(),tpre.end());
			TreeNode *tmp=result;
			int t=1;
			for(int j=1;j<tpre.size();j++){
				if(tpre[j]==t*2){
					if(!tmp->left){
						tmp->left=new TreeNode(-1);
					}
					tmp=tmp->left;
				}else{
					if(!tmp->right){
						tmp->right=new TreeNode(-1);
					}
					tmp=tmp->right;
				}
				t=tpre[j];
			}
			tmp->val=s[i];
		}
		return result;
    }

	void print(TreeNode* r){
		if(!r){
			return;
		}
		cout<<r->val<<" ";
		print(r->left);
		print(r->right);
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

	char *a=solution.Serialize(r1);
	cout<<a<<endl;

	TreeNode *r=solution.Deserialize(a);
	solution.print(r);
	cout<<endl;

	return 0;
}
