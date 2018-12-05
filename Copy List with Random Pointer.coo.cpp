
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
 *  ����Ŀ���
 *  ����һ�������ָ�������
 *  138 copy list with random pointer
 *
 *  ����������ܽ᣺
 *  ����ȷ���α꣬��ȷ��������Null���ж�˭����null
*/
class Solution {
public:
    /*��ԭʼ�ģ��ȱ������ߣ�Ȼ���ٱ�����ֵrandom, ��ֵrandomʱͨ������ԭʼ�ģ����ҵ�������index*/
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

    /* ʹ��map�ݴ�randowm pointer,��һ�����Head����ֵ���ߣ��ڶ����ڱ�����ֵrandom��ͨ��map�����Ҷ�Ӧ��node */
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

    /* ���ķ�ʽ����������Ч�ʵĵ������ҵ�random��������ƥ���λ��
     * �ȱ���һ��head���������Ƶ�node���뵽node->next,
     * ��������֪��ÿ��node��next�Ƕ�Ӧ���µ������λ��,�ҵ�ԭ�����randomʱ,�����֪���������randomӦ����ԭ�����random��next��
     * �ٱ���һ�飬��random���и�ֵ
     * ������һ�飬�����Ƕϵ�
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
