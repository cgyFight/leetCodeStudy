#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode newListDummy(0);
    	ListNode *next = &newListDummy;
    	ListNode *pSmallstNode;
    	int smalstVal = pSmallstNode->val;

    	if (lists.isempty()) return NULL;

    	pSmallstNode = lists[0];
    	while(pSmallstNode) {
    		for (std::vector<>::iterator i = lists.begin(); i != lists.end(); ++i) {
    			if (*i == NULL) continue;//end of an list
    			if ((*i)->val <= pSmallstNode->val) {
    				pSmallstNode = *i;
    				*i = (*i)->next;
    				next->next = pSmallstNode;
    				next = next->next;
    			} 
    		}
    	}
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	struct ListNode a1(1, 'a');
	struct ListNode a2(2, 'a');
	struct ListNode a3(3, 'a');
	struct ListNode a4(4, 'a');
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;

	struct ListNode b1(1, 'b');
	struct ListNode b2(2, 'b');
	struct ListNode b3(3, 'b');
	struct ListNode b4(4, 'b');
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &b4;

	ListNode *head1 = &a1;
	ListNode *head2 = &b1;

	ListNode *tmp;

	std::vector<ListNode *> v;
	v.push_back(head1);
	v.push_back(head2);

	std::vector<ListNode *>::iterator iter;
	iter = v.begin();
	tmp = (*iter);
	(*iter) = (*iter)->next;

	// cout <<  "hello" << v[0]->val << v[0]->type;
	// cout << "tmp val = " << tmp->val;

	return 0;
}





















