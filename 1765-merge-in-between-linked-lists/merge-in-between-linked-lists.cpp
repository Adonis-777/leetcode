class Solution {
public:
    typedef struct ListNode* NODE;

    int sizeofLinkedList(NODE head) {
        int n = 0;
        NODE curr = head;

        while(curr) {
            n++;
            curr = curr->next;
        }

        return n;
    }

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        int n = sizeofLinkedList(list1);

        // Case 1: a > 1 && b < n
        if(a > 1 && b < n) {

            NODE leftboundary = list1, rightboundary = NULL;
            NODE curr = list1;

            for(int i = 0; i < n; i++) {
                if(i + 1 == a)
                    leftboundary = curr;

                if(i == b + 1) {
                    rightboundary = curr;
                    break;
                }

                curr = curr->next;
            }

            NODE temp = list2;
            while(temp->next)
                temp = temp->next;

            leftboundary->next = list2;
            temp->next = rightboundary;

            return list1;
        }

        // Case 2: a == 1 && b < n
        if(a == 1 && b < n) {

            NODE rightboundary = list1;

            for(int i = 0; i <= b; i++)
                rightboundary = rightboundary->next;

            NODE temp = list2;
            while(temp->next)
                temp = temp->next;

            list1->next = list2;
            temp->next = rightboundary;

            return list1;
        }

        // Case 3: a > 1 && b == n
        if(a > 1 && b == n) {

            NODE curr = list1, leftboundary = list1;

            for(int i = 0; i < a - 1; i++)
                curr = curr->next;

            leftboundary = curr;

            leftboundary->next = list2;

            return list1;
        }

        // Case 4: a == 1 && b == n
        return list2;
    }
};