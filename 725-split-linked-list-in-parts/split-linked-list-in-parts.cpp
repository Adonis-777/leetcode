class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // 1. Calculate the total length of the linked list
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }

        // 2. Determine the size of each part
        int partSize = n / k;
        int extraNodes = n % k;

        vector<ListNode*> ans;
        curr = head;

        for (int i = 0; i < k; ++i) {
            ListNode* partHead = curr;
            int currentPartLength = partSize + (i < extraNodes ? 1 : 0);

            // Traverse to the end of the current part
            ListNode* prev = nullptr;
            for (int j = 0; j < currentPartLength; ++j) {
                prev = curr;
                if (curr) curr = curr->next;
            }

            // Cut the connection to the rest of the list
            if (prev) {
                prev->next = nullptr;
            }

            ans.push_back(partHead);
        }

        return ans;
    }
};
