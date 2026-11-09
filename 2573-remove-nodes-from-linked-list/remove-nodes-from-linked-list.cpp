class Solution {
public:

    typedef ListNode* NODE;

    NODE reverse(NODE head, NODE prev) {
        if(!head)
            return prev;

        NODE nxtptr = head->next;
        head->next = prev;

        return reverse(nxtptr, head);
    }

    ListNode* removeNodes(ListNode* head) {

        if(!head || !head->next)
            return head;

        head = reverse(head, NULL);
        ListNode dummy(0);
        NODE tail = &dummy;

        NODE curr = head;
        int maximum_value = INT_MIN;

        while(curr){
            if(curr->val >= maximum_value){
                maximum_value = curr->val;
                tail->next = curr;
                tail = tail->next;
            }

            curr = curr->next;
        }

        tail->next = NULL;
        return reverse(dummy.next, NULL);
        
    }
};