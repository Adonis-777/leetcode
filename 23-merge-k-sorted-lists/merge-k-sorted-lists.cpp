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
    typedef ListNode* NODE;

    NODE merge(NODE l1, NODE l2){

        ListNode dummy(0);
        NODE tail = &dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        tail->next = (l1) ? l1 : l2;
        return dummy.next;
    }

    NODE mergeSort(NODE head){
        if(!head || !(head->next))
            return head;
        
        NODE slow = head, fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        NODE mid = slow->next;
        slow->next = NULL;

        NODE left = mergeSort(head);
        NODE right = mergeSort(mid);

        return merge(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode dummy(0);
        NODE tail = &dummy;

        for(NODE l : lists){

            if(!l)
                continue;

            tail->next = l;
            while(tail->next)
                tail = tail->next;
        }

        return mergeSort(dummy.next);
        
    }
};