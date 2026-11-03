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

    int sizeofLinkedList(NODE head){
        int n = 0;
        NODE curr = head;

        while(curr){
            n++;
            curr = curr->next;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head)
            return NULL;

        int n = sizeofLinkedList(head);
        k = k % n;

        if(k == 0)
            return head;
        
        NODE tail = head;
        while(tail->next){
            tail = tail->next;
        }

        tail->next = head; // made a circular loop
        NODE prev = tail, curr = head;

        for(int i = 0; i < (n - k); i++){
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        return curr;
    }
};