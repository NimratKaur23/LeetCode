class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxbest=nums[0];
        int minbest=nums[0];

        int maxSum=nums[0];
        int minSum=nums[0];

        int sum=nums[0];

        for(int i=1;i<nums.size();i++) {
            maxbest=max(nums[i],maxbest+nums[i]);
            minbest=min(nums[i],minbest+nums[i]);

            maxSum=max(maxbest,maxSum);
            minSum=min(minbest,minSum);

            sum+=nums[i];
            
        }

        //all elemesnts are negative
        if(maxSum<0)
          return maxSum;
        
        //maximum circular subarray
        int roundbest=sum-minSum;

        return max(maxSum,roundbest);
    }
};