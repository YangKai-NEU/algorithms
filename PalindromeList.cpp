#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        // write code here
        vector<int> s;
		ListNode *t=pHead;
		while(t){
			s.push_back(t->val);
			t=t->next;
		}
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-1-i]){
				return false;
			}
		}
		return true;
    }
};

int main(int argc, char *argv[])
{
	ListNode *s1;
	s1=new ListNode(2);
	s1->next=new ListNode(3);
	s1->next->next=new ListNode(4);

	Palindrome p;
	cout<<p.isPalindrome(s1)<<endl;

	return 0;
}
