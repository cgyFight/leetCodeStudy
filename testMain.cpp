#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  ListNode(int x, char z) : val(x), c(z), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  int val;
  char c;
  ListNode *next;
};
 
 #if 1
class Solution {
public:
	void func(){

	}
	/*遍历每一个队列，找出其中最小的，加入到最新的*/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode newListDummy(0);
    	ListNode *next = &newListDummy;
    	ListNode *pSmallstNode;
    	std::vector<ListNode *>::iterator tmp;
    	while(next) {
    		pSmallstNode = NULL;
    		for (std::vector<ListNode*>::iterator i = lists.begin(); i != lists.end(); ++i) {
    			if (*i == NULL) continue;
    			if (!pSmallstNode) pSmallstNode = *i;
    			if ((*i)->val <= pSmallstNode->val) {
    				pSmallstNode = *i;
    				tmp = i;
    			}
    		}
    		if (pSmallstNode) *tmp = (*tmp)->next;
    		next->next = pSmallstNode;
    		next = next->next;
    	}
    	return newListDummy.next;
    }

    /*合并两个队列*/
    ListNode *mergeTwoList(ListNode *l1, ListNode *l2) {
    	ListNode newListDummy(0);
    	ListNode *next = &newListDummy;
    	while(true) {
    		if (!l1) {
    			next->next = l2;
    			break;
    		}
    		if (!l2) {
    			next->next = l1;
    			break;
    		}
    	}
    }

    /*合并两个队列*/
    ListNode *mergeTwoList2(ListNode *l1, ListNode *l2) {
    	if (!l1) return l2;
    	if (!l2) return l1;
    	ListNode newListDummy(0);
    	ListNode *next = &newListDummy;
    	next->next = l1;
    	ListNode *tmp;

    	while (l1 && l2) {
    		if (l1->val < l2->val) {
    			l1 = l1->next;
    		} else {
    			tmp = l2;
    			l2 = l2->next;
    			tmp->next = l1;

    		}
    		next = next->next;
    	}


    	while(next) {
    		if (!l1) {
				next->next = l2;
				break;
    		} 
    		if (!l2) {
    			next->next = l1;
    			break;
    		}

    		if (l1->val < l2->val) {
    			next->next = l1;
    			l1 = l1->next;
    		} else {
    			next->next = l2;
    			l2 = l2->next;
    		}
			next = next->next;
    	}
    }

    /*
    	两个两个的排序，再并入下一个
     */
    ListNode *mergeKLists2(std::vector<ListNode *> &lists){
    }
};

#endif

int main(int argc, char const *argv[])
{
#if 1
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

	cout << "befor size " << v.size();
	v.erase(iter);
	cout << "end size " << v.size();

	// tmp = (*iter);
	// (*iter) = (*iter)->next;

	// cout <<  "hello" << v[0]->val << v[0]->type;
	// cout << "tmp val = " << tmp->val;
	#endif

	return 0;
}





















