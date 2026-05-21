class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        int closetSum=INT_MAX/2;

        for(int i=0;i<nums.size()-2;i++) {
            int s=i+1;
            int e=nums.size()-1;

            while(s<e) {
                int currSum=nums[i]+nums[s]+nums[e];
                if(abs(currSum-target)< abs(closetSum-target)) {
                    closetSum=currSum;
                }

                if(currSum<target) {
                    s++;
                }
                else if(currSum>target) {
                    e--;
                }
                else {
                    return currSum;
                }
            }
        }

        return closetSum;
    }
};