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

    NODE reverse(NODE head, NODE prev){
        if(!head)
            return prev;
        NODE nextptr = head->next;
        head->next = prev;
        return reverse(nextptr, head);
    }

    int sizeofLinkedList(NODE head){
        int n = 0;
        NODE curr = head;
        while(curr){
            n++;
            curr = curr->next;
        }

        return n;
    }
    int pairSum(ListNode* head) {

        int n = sizeofLinkedList(head);

        if(n == 2){

            NODE curr = head;
            int ans = 0;

            while(curr){
                ans += curr->val;
                curr = curr->next;
            }

            return ans;
        }
       
        NODE slow = head, fast = head->next;
        int ans = INT_MIN;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        NODE second = slow->next;
        slow->next = NULL;

        second = reverse(second, NULL);
        while(head && second){
            int temp = head->val + second->val;
            ans = max(ans, temp);
            head = head->next;
            second = second->next;
        }

        return ans;


        
    }
};