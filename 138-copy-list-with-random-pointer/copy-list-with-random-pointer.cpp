/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    typedef struct Node* NODE;

    Node* copyRandomList(Node* head) {

        Node dummy(0);
        NODE tail = &dummy;

        // we want to create a linkedlist somewhere else in the memory..
        vector<NODE> temp;
        NODE curr = head;
        while(curr){
            temp.push_back(curr);
            curr = curr->next;
        }

        map<NODE, NODE> mp;

        for(auto x : temp){
            NODE temp_node = new Node(x->val);
            tail->next = temp_node;
            tail = tail->next;

            mp[x] = temp_node;
        }

        curr = head;
        NODE c1 = dummy.next;

        while(curr){
            if(curr->random)
                c1->random = mp[curr->random];

            curr = curr->next;
            c1 = c1->next;
        }

        

        return dummy.next;
    }
};