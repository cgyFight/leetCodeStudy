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
    	ListNode *pairPre, *pairTail, *pairA, *pairB;
    	pairPre = pairTail = pairA = pairB = NULL;

    	if (!head || !head->next) return head;

    	pairA = head;
    	pairB = pairA->next;

    	pairTail = pairB->next;

    	pairB->next = pairA;
    	pairA->next = pairTail;
    	pairPre = pairA;
    	head->pairB;

    	while(true) {
    		if (!pairPre) break;
    		pairA = pairPre->next;
    		if (!pairA) break;
    		pairB = pairA->next;
    		if (!pairB) break;
    		pairTail = pairB->next;

    		pairPre->next = pairB;
    		pairB->next = pairA;
    		pairA->next = pairTail;
    		pairPre = pairA;
    	}
    	return head;
    }
};