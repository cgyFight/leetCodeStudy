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
    ListNode *detectCycle(ListNode *head) {
    	if (!head) return  head;
    	ListNode *runA, *runB;

    	runA = head;
    	runB = head->next;
    	while(runA != runB) {
    		if (runA == NULL ) return NULL;
    		runA = runA->next;
    		if (!runB || !runB->next) return NULL;
    		runB = runB->next->next;
    	}
    	return runA;
    }
};