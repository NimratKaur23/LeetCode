class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int totalSum=0;
        for(int i=0;i<nums.size();i++) {
            totalSum+=nums[i];
        }

        int sumleft=0;
        int sumright=totalSum;

        for(int i=0;i<nums.size();i++) {
            sumright-=nums[i];

            if(sumleft==sumright) {
                return i;
            }

            sumleft+=nums[i];
        }

        return -1;
    }
};