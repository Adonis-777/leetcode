class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[nums[0]];

        int head = 0;

        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        
        while(head != slow){
            head = nums[head];
            slow = nums[slow];
        }

        return head;
    
        
    }
};