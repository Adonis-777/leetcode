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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode dummy(0);
        dummy.next = head;
        ListNode* tail = &dummy;


        // step 1 --> identify left pointer.
        NODE leftBoundary = tail, curr = head;
        for(int i = 0; i < (left - 1); i++){
            leftBoundary = curr;
            curr = curr->next;
        }

        // step 2 --> identify right pointer
        NODE prev = NULL;
        for(int i = 0; i < (right - left + 1); i++){
            NODE nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }

        leftBoundary->next->next = curr;
        leftBoundary->next = prev;

        return dummy.next;
        
    }
};