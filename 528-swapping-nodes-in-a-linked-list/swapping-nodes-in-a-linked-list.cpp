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
        NODE curr = head;
        int n = 0;

        while(curr){
            n++;
            curr = curr->next;
        }

        return n;
    }

    ListNode* swapNodes(ListNode* head, int k) {

        int n = sizeofLinkedList(head);

        // if k == n --> only shift last values
        if(k == n){
            NODE curr = head;
            while(curr->next){
                curr = curr->next;
            }

            int temp = head->val;
            head->val = curr->val;
            curr->val = temp;

            return head;
        }

        ListNode dummy(0);
        NODE tail = &dummy;
        tail->next = head;

        for(int i = 0; i < k; i++){
            tail = tail->next;
        }


        NODE curr = &dummy;
        for(int i = 0; i < (n - (k - 1));  i++){
            curr = curr->next;
        }

        int temp = tail->val;
        tail->val = curr->val;
        curr->val = temp;

        return dummy.next;
    }

};