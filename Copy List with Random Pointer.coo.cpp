
#include <iostream>
#include <vector>

#include<algorithm>  
// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};



/*
 *  链表的拷贝
 *  拷贝一个带随机指针的链表
 *  138 copy list with random pointer
 *
 *  对于链表的总结：
 *  首先确定游标，再确定结束的Null，判断谁会先null
*/
class Solution {
public:
    /*最原始的，先遍历主线，然后再遍历赋值random, 赋值random时通过遍历原始的，来找到遍历的index*/
    RandomListNode *copyRandowList_traverse_double(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *res = new RandomListNode(head->label);
        RandomListNode *node = res;
        RandomListNode *cur = head->next;
        while (cur) {
            RandomListNode *tmp = new RandomListNode(cur->label);
            node->next = tmp;
            node = node->next;
            cur = cur->next;
        }

        cur = head;
        node = res;
        while(cur) {
            if (cur->random) {

                // find random index in head index
                RandomListNode *index = head;
                RandomListNode *index_new = res;
                while (index) {
                    if (index == cur->random) {
                        node->random = index_new;
                        break;
                    }
                    index = index->next;
                    index_new = index_new->next;
                }
            }
            cur = cur->next;
            node = node->next;
        }
        return res;
    }

    /* 使用map暂存randowm pointer,第一遍遍历Head，赋值主线，第二遍在遍历赋值random，通过map来查找对应的node */
    RandomListNode *copyRandomList_use_map(RandomListNode *head) {
        if (!head) return NULL;

        RandomListNode *res = new RandomListNode(head->label);
        RandomListNode *node = res;
        RandomListNode *cur = head->next;
        map<RandomListNode *, RandomListNode *> mapOfNode;
        mapOfNode[head] = res;
        while (cur) {
            RandomListNode *tmp = new RandomListNode(cur->label);
            node->next = tmp;
            node = node->next;
            mapOfNode[cur] = tmp;
            cur = cur->next;
        }

        node = res;
        cur = head;

        while (node) {
            node->random = mapOfNode[cur->random];
            node = node->next;
            cur = cur->next;
        }
        return res;
    }

    /* 最快的方式，现在提升效率的点在于找到random与新链表匹配的位置
     * 先遍历一遍head，并将复制的node插入到node->next,
     * 这样可以知道每个node的next是对应的新的链表的位置,找到原链表的random时,便亦可知道新链表的random应当在原链表的random的next中
     * 再遍历一遍，对random进行赋值
     * 最后遍历一遍，将他们断掉
    */

    RandomListNode *copyRadomList_insert_in_close(RandomListNode *head) {
        if (!head) return NULL;

        RandomListNode *node = head;
        while (node) {
            RandomListNode *tmp = new RandomListNode(node->label);
            tmp->next = node->next;
            node->next = tmp;
            node = tmp->next;
        }

        node = head;
        while (node) {
            if (node->random) node->next->random = node->random->next;
            node = node->next->next;
        }

        node = head;
        RandomListNode *cur = node->next;
        RandomListNode *res = cur;// = node->next;
        while(node) {
            cur = node->next;
            node->next = cur->next;
            if (cur->next) {
                node = cur->next;
                cur->next = node->next;
            } else {
                break;
            }
        }
        return res;
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
                //鑾峰彇鏈�灏忕殑鎸囬拡
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
