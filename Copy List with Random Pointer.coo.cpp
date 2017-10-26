
#include <iostream>
#include <vector>

#include<algorithm>  
// Definition for singly-linked list with a random pointer.
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	RandomListNode *newPart = new RandomListNode(0);
    	newPart->label = head->label;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode newListDummy(0);
    	ListNode *next = &newListDummy;
    	while(1) {
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
    	return newListDummy->next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode listDummy(0);
    	ListNode *next = &listDummy;
    	ListNode *smalstNode;
    	int smalVal = lists[0]->val;
    	ListNode *tmp;
    	vector<ListNode*>::iterator iter;
    	if (lists.isempty()) return lists;
    	while(1) {
    		smalstNode = NULL;
    		iter = lists.begin();
    		smalVal = (*iter).val;
    		for(; iter != lists.end(); iter++) {
    			//获取最小的指针
    			tmp = *iter;
    		}
    	}
    }
};

int main(int argc, char const *argv[])
{

	//  1 2    3     4       5   6
	// []()mutable throw()->int {}
	//1 
	//[]
	std::vector<int> v(10);
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
		/* code */
	}

	int total = 0;
	int tmp = 23;
	std::for_each(v.begin(), v.end(),[&total, tmp](int x) {
		std::cout<<x << std::endl;
		total += x;
		total += tmp;
	} );
	// std::cout << total;
	std::cout << total;
	return 0;
}