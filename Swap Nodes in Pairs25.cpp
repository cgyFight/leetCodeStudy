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
    ListNode* swapPairs(ListNode* head) {
    	if (!head) return head;
    	ListNode *pre, *cur, *next;
    	pre = head;


		cur = pre->next;
		if (!cur) return head;
		next = cur->next;

		cur->next = pre;
		pre->next = next;

		head = cur;
    	while(next) {
    		pre = next;
    		cur = pre->next;

    		if (!cur)  return head;
    		next = cur->next;

    		cur->next= pre;
    		pre->next = next;
    	}
    	return head;

    }
};