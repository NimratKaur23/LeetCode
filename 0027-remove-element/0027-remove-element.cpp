class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int k=0;
        int i=0;
        int count=0;

        while(i<nums.size()) {
            if(nums[i]!=val) {
                nums[k]=nums[i];
                i++;
                k++;
                count++;
            }
            else {
                i++;
            }
        }

        return count;

        
    }
};