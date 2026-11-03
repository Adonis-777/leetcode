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
    typedef ListNode* NODE;
    bool hasCycle(ListNode *head) {

        NODE slow = head, fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }

        return false;
        
    }
};