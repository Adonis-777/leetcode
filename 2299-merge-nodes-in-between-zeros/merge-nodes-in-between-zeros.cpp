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

    typedef long long ll;
    typedef struct ListNode* NODE;
    ListNode* mergeNodes(ListNode* head) {

        ll sum = 0;
        NODE curr = head->next;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(curr){
            if(curr->val == 0){
                // breaking point, create a new node and store the current sum value in here
                tail->next = new ListNode(sum);
                tail = tail->next;

                sum = 0;
            }

            else{
                sum += curr->val;
            }

            curr = curr->next;
        }

        return dummy.next;
        
    }
};