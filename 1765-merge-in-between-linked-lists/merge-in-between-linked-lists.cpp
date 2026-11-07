/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    typedef struct ListNode* NODE;
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        NODE left = list1, right = list1;

        for(int i = 0; i < (a - 1); i++){
            left = left->next;
        }

        NODE temp = list2;
        while(temp->next){
            temp = temp->next;
        }

        for(int i = 0; i <= b; i++){
            right = right->next;
        }

        left->next = list2;
        temp->next = right;

        return list1;
    }
};